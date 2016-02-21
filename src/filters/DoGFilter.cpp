//
//  DoGFilter.cpp
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/24.
//
//

#include "DoGFilter.h"

DoGFilter::DoGFilter(float width, float height, float black, float sigma, float sigma3, float tau, int halfWidth, int smoothPasses, ofVec2f sketchiness) : AbstractFilter(width, height) {
    _name = "Difference of Gradient";
    _imageFbo.allocate(getWidth(), getHeight(), GL_RGBA32F_ARB);
    _edgeTangentFbo.allocate(getWidth(), getHeight(), GL_RGBA32F_ARB);
    _directionalFbo.allocate(getWidth(), getHeight(), GL_RGBA32F_ARB);
    _imageFbo.begin();
    ofClear(0, 0, 0, 0);
    _imageFbo.end();
    _edgeTangentFbo.begin();
    ofClear(0, 0, 0, 0);
    _edgeTangentFbo.end();
    _directionalFbo.begin();
    ofClear(0, 0, 0, 0);
    _directionalFbo.end();
    
    _edgeTangentFilters = new FilterChain(getWidth(), getHeight(), "edgeTangentFilters", GL_RGBA32F_ARB);
    _edgeTangentFilters->addFilter(new EdgeTangentFilter(getWidth(), getHeight()));

    for (int i=0; i<smoothPasses; i++) {
        _edgeTangentFilters->addFilter(new EdgeTangentSmoothingFilter(getWidth(), getHeight(), ofVec2f(2.0, 0.0), halfWidth));
        _edgeTangentFilters->addFilter(new EdgeTangentSmoothingFilter(getWidth(), getHeight(), ofVec2f(0.0, 2.0), halfWidth));
    }
    
    _directionalDoGFilter = new DirectionalDoGFilter(getWidth(), getHeight(), sigma, tau, sketchiness.x, sketchiness.y);
    _flowDoGFilter = new FlowDoGFilter(getWidth(), getHeight(), sigma3);
    _addParameter(new ParameterF("black", black));
    _setupShader();
}
DoGFilter::~DoGFilter() {}


void DoGFilter::begin() {
    _imageFbo.begin();
    AbstractFilter::begin();
}

void DoGFilter::end() {
    AbstractFilter::end();
    _imageFbo.end();

    
    _edgeTangentFbo.begin();
    _edgeTangentFilters->begin();
    _imageFbo.draw(0,0);
    _edgeTangentFilters->end();
    _edgeTangentFbo.end();
    
    
    _directionalDoGFilter->setSecondTexture(_edgeTangentFbo.getTexture());
    _directionalFbo.begin();
    _directionalDoGFilter->begin();
    _imageFbo.draw(0, 0);
    _directionalDoGFilter->end();
    _directionalFbo.end();
    
    _flowDoGFilter->setSecondTexture(_edgeTangentFbo.getTexture());
    _flowDoGFilter->begin();
    _updateParameters(&_shader);
    _directionalFbo.draw(0, 0);
    _flowDoGFilter->end();
    //_directionalFbo.draw(0, 0);
    //_edgeTangentFbo.draw(0, 0);
    
}


string DoGFilter::_getFragSrc() {
    return GLSL_STRING(120,
       uniform sampler2D inputImageTexture;
       uniform float black;
       const vec3 W = vec3(0.2125, 0.7154, 0.0721);
       
       void main() {
           vec2 textureCoordinate = gl_TexCoord[0].xy;
           vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);
           float luminance = dot(textureColor.rgb, W) - black/255.0;
           gl_FragColor = vec4(luminance, luminance, luminance, textureColor.a);
       }
       );
}

void DoGFilter::setBlack(float black) {
    updateParameter("black", black);
}

void DoGFilter::setTau(float tau) {
    _directionalDoGFilter->updateParameter("tau", tau);
}
void DoGFilter::setSigma(float sigma) {
    _directionalDoGFilter->setSigma(sigma);
}

void DoGFilter::setSigma3(float sigma3) {
    _flowDoGFilter->setSigma(sigma3);
}

void DoGFilter::setHalfWidth(int halfWidth) {
    for (int i=1; i<_edgeTangentFilters->getNumFilters(); i++)
        _edgeTangentFilters->getFilterAt(i)->updateParameter("halfWidth", halfWidth);
}

void DoGFilter::setSketchiness(ofVec2f sketchiness) {
    _directionalDoGFilter->updateParameter("sketchinessX", sketchiness.x);
    _directionalDoGFilter->updateParameter("sketchinessY", sketchiness.y);
}