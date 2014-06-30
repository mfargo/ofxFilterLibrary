//
//  AverageColorFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/30.
//
//

#include "AverageColorFilter.h"

AverageColorFilter::AverageColorFilter(ofTexture & texture, float percentReduction) : AbstractFilter(texture.getWidth()*percentReduction, texture.getHeight()*percentReduction) {
    _name = "Average Color";
    _texture = texture;
    _setupShader();
    _addParameter(new ParameterF("texelWidth", 0.5f/getWidth()));
    _addParameter(new ParameterF("texelHeight", 0.5f/getHeight()));
    _sampleFbo.allocate(getWidth(),getHeight());
}
AverageColorFilter::~AverageColorFilter() {}


void AverageColorFilter::begin() {
    ofSetColor(255);
    _sampleFbo.begin();
    _shader.begin();
    _updateParameters(&_shader);
    _texture.draw(0, 0, getWidth(), getHeight());
    _shader.end();
    _sampleFbo.end();
    _sampleFbo.readToPixels(_pixels);
    ofVec3f average;
    for (int y=0; y<_pixels.getHeight(); y++)
        for (int x=0; x<_pixels.getWidth(); x++) {
            ofColor c = _pixels.getColor(x, y);
            average += ofVec3f(c.r/255.f, c.g/255.f, c.b/255.f);
        }
    float total = _pixels.getWidth()*(float)_pixels.getHeight();
    _averageColor = ofFloatColor(average.x/total, average.y/total, average.z/total);
}

void AverageColorFilter::end() {
    //ofSetColor(_averageColor);
    //ofRect(0, 0, getWidth(), getHeight());
}

string AverageColorFilter::_getVertSrc() {
    return GLSL_STRING(120,
        
        uniform float texelWidth;
        uniform float texelHeight;
        
        varying vec2 upperLeftInputTextureCoordinate;
        varying vec2 upperRightInputTextureCoordinate;
        varying vec2 lowerLeftInputTextureCoordinate;
        varying vec2 lowerRightInputTextureCoordinate;
        
        void main()
        {
            gl_TexCoord[0] = gl_MultiTexCoord0;
            vec2 inputTextureCoordinate = gl_TexCoord[0].xy;
            gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
            
            upperLeftInputTextureCoordinate = inputTextureCoordinate.xy + vec2(-texelWidth, -texelHeight);
            upperRightInputTextureCoordinate = inputTextureCoordinate.xy + vec2(texelWidth, -texelHeight);
            lowerLeftInputTextureCoordinate = inputTextureCoordinate.xy + vec2(-texelWidth, texelHeight);
            lowerRightInputTextureCoordinate = inputTextureCoordinate.xy + vec2(texelWidth, texelHeight);
        }
    );
}

string AverageColorFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;
                
        varying vec2 upperLeftInputTextureCoordinate;
        varying vec2 upperRightInputTextureCoordinate;
        varying vec2 lowerLeftInputTextureCoordinate;
        varying vec2 lowerRightInputTextureCoordinate;
        
        void main()
        {
            vec4 upperLeftColor = texture2D(inputImageTexture, upperLeftInputTextureCoordinate);
            vec4 upperRightColor = texture2D(inputImageTexture, upperRightInputTextureCoordinate);
            vec4 lowerLeftColor = texture2D(inputImageTexture, lowerLeftInputTextureCoordinate);
            vec4 lowerRightColor = texture2D(inputImageTexture, lowerRightInputTextureCoordinate);
            
            gl_FragColor = 0.25 * (upperLeftColor + upperRightColor + lowerLeftColor + lowerRightColor);
        }
    );
}