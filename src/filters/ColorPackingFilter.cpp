//
//  ColorPackingFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#include "ColorPackingFilter.h"

ColorPackingFilter::ColorPackingFilter(float width, float height, ofVec2f texelSize) : AbstractFilter(width, height) {
    _texelSize = texelSize;
    _name = "Color Packing";
    _addParameter(new ParameterF("texelWidth", _texelSize.x/getWidth()));
    _addParameter(new ParameterF("texelHeight", _texelSize.y/getHeight()));
    _setupShader();
}
ColorPackingFilter::~ColorPackingFilter() {}

string ColorPackingFilter::_getVertSrc() {
    return GLSL_STRING(120,
        
        uniform float texelWidth;
        uniform float texelHeight;
        
        varying vec2 upperLeftInputTextureCoordinate;
        varying vec2 upperRightInputTextureCoordinate;
        varying vec2 lowerLeftInputTextureCoordinate;
        varying vec2 lowerRightInputTextureCoordinate;
        
        void main()
        {
            gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
            gl_TexCoord[0] = gl_MultiTexCoord0;
            
            upperLeftInputTextureCoordinate = gl_TexCoord[0].xy + vec2(-texelWidth, -texelHeight);
            upperRightInputTextureCoordinate = gl_TexCoord[0].xy + vec2(texelWidth, -texelHeight);
            lowerLeftInputTextureCoordinate = gl_TexCoord[0].xy + vec2(-texelWidth, texelHeight);
            lowerRightInputTextureCoordinate = gl_TexCoord[0].xy + vec2(texelWidth, texelHeight);
        }
    );
}

string ColorPackingFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;
        
        uniform mat3 convolutionMatrix;
        
        varying vec2 upperLeftInputTextureCoordinate;
        varying vec2 upperRightInputTextureCoordinate;
        varying vec2 lowerLeftInputTextureCoordinate;
        varying vec2 lowerRightInputTextureCoordinate;
        
        void main()
        {
            vec2 upperLeftInputTextureCoordinate = gl_TexCoord[0].xy;
            float upperLeftIntensity = texture2D(inputImageTexture, upperLeftInputTextureCoordinate).r;
            float upperRightIntensity = texture2D(inputImageTexture, upperRightInputTextureCoordinate).r;
            float lowerLeftIntensity = texture2D(inputImageTexture, lowerLeftInputTextureCoordinate).r;
            float lowerRightIntensity = texture2D(inputImageTexture, lowerRightInputTextureCoordinate).r;
            
            gl_FragColor = vec4(upperLeftIntensity, upperRightIntensity, lowerLeftIntensity, lowerRightIntensity);
        }
    );
}

