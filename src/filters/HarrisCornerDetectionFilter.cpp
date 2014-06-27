//
//  HarrisCornerDetectionFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#include "HarrisCornerDetectionFilter.h"

HarrisCornerDetectionFilter::HarrisCornerDetectionFilter(ofTexture & texture, float sensitivity, float threshold, float blur) : AbstractPingPongRenderer(texture.getWidth(), texture.getHeight()), AbstractFilter(texture.getWidth(), texture.getHeight()){
    _name = "Harris Corner Detection";
    _threshold = threshold;
    _texture = texture;
    _derivativeFilter = new XYDerivativeFilter(getWidth(), getHeight());
    _blurFilter = new GaussianBlurFilter(getWidth(), getHeight(), blur);
    _suppresionFilter = new ThresholdedNonMaximumSuppressionFilter(getWidth(), getHeight());
    
    _addParameter(new ParameterF("sensitivity", sensitivity));
    _setupShader();
}
HarrisCornerDetectionFilter::~HarrisCornerDetectionFilter() {}

void HarrisCornerDetectionFilter::begin() {
    _derivativeFilter->begin();
    _ping.begin();
    ofClear(0, 0, 0, 0);
}
void HarrisCornerDetectionFilter::end() {
    _ping.end();
    _derivativeFilter->end();
    
    _blurFilter->begin();
    _ping.draw(0, 0);
    _blurFilter->end();
    
    _pong.begin();
    ofClear(0, 0, 0, 0);
    _blurFilter->getTextureReference().draw(0, 0);
    _pong.end();
    
    _shader.begin();
    _updateParameters(&_shader);
    _ping.begin();
    ofClear(0, 0, 0, 0);
    _pong.draw(0, 0);
    _ping.end();
    _shader.end();

    _pong.begin();
    ofClear(0 ,0 ,0 , 0);
    _suppresionFilter->begin();
    _ping.draw(0, 0);
    _suppresionFilter->end();
    _pong.end();
    
    _pong.readToPixels(_filteredPixels);
    ofSetColor(255);
    _texture.draw(0, 0);
    ofSetColor(0,255,0);
    
    for (int y=0; y<_filteredPixels.getHeight(); y++)
        for (int x=0; x<_filteredPixels.getWidth(); x++)
            if (_filteredPixels.getColor(x, y).r==0) {
                ofLine(x, y-2, x, y+2);
                ofLine(x-2, y, x+2, y);
            }

    ofSetColor(255);
    ////_pong.draw(0, 0);
    
}

string HarrisCornerDetectionFilter::_getFragSrc() {
    return GLSL_STRING(120,
        
        uniform sampler2D inputImageTexture;
        uniform float sensitivity;
        
        const float harrisConstant = 0.04;
        
        void main() {
            vec2 textureCoordinate = gl_TexCoord[0].xy;
            vec3 derivativeElements = texture2D(inputImageTexture, textureCoordinate).rgb;
            
            float derivativeSum = derivativeElements.x + derivativeElements.y;
            
            float zElement = (derivativeElements.z * 2.0) - 1.0;
            
            // R = Ix^2 * Iy^2 - Ixy * Ixy - k * (Ix^2 + Iy^2)^2
            float cornerness = derivativeElements.x * derivativeElements.y - (zElement * zElement) - harrisConstant * derivativeSum * derivativeSum;
            
            gl_FragColor = vec4(vec3(cornerness * sensitivity), 1.0);
        }
    );
}