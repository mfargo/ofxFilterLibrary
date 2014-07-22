//
//  DilationFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/17.
//
//

#include "DilationFilter.h"

DilationFilter::DilationFilter(float width, float height, int dilationRadius) : Abstract3x3PingPongFilter(width, height, ofVec2f(dilationRadius, dilationRadius)) {
    _name = "Dilation Filter";
    _setupShader();
}
DilationFilter::~DilationFilter() {}



void DilationFilter::setDilationRadius(int dilationRadius) {
    _texelSpacing.x = dilationRadius;
    _texelSpacing.y = dilationRadius;
}

string DilationFilter::_getFragSrc() {
    return _getFragSrcForRadius(_texelSpacing.x);
}

string DilationFilter::_getVertSrc() {
    return _getVertSrcForRadius(_texelSpacing.x);
}

string DilationFilter::_getVertSrcForRadius(int radius) {
    switch (radius) {
        case 1:
            return GLSL_STRING(120,
                               
                               uniform float texelWidthOffset;
                               uniform float texelHeightOffset;
                               
                               varying vec2 centerTextureCoordinate;
                               varying vec2 oneStepPositiveTextureCoordinate;
                               varying vec2 oneStepNegativeTextureCoordinate;
                               
                               void main()
                               {
                                   gl_TexCoord[0] = gl_MultiTexCoord0;
                                   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
                                   
                                   vec2 offset = vec2(texelWidthOffset, texelHeightOffset);
                                   
                                   centerTextureCoordinate = gl_TexCoord[0].xy;
                                   oneStepNegativeTextureCoordinate = centerTextureCoordinate - offset;
                                   oneStepPositiveTextureCoordinate = centerTextureCoordinate + offset;
                               }
                               );
            break;
        case 2:
            return GLSL_STRING(120,
                               uniform float texelWidthOffset;
                               uniform float texelHeightOffset;
                               
                               varying vec2 centerTextureCoordinate;
                               varying vec2 oneStepPositiveTextureCoordinate;
                               varying vec2 oneStepNegativeTextureCoordinate;
                               varying vec2 twoStepsPositiveTextureCoordinate;
                               varying vec2 twoStepsNegativeTextureCoordinate;
                               
                               void main()
                               {
                                   gl_TexCoord[0] = gl_MultiTexCoord0;
                                   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
                                   
                                   vec2 offset = vec2(texelWidthOffset, texelHeightOffset);
                                   
                                   centerTextureCoordinate = gl_TexCoord[0].xy;
                                   oneStepNegativeTextureCoordinate = centerTextureCoordinate - offset;
                                   oneStepPositiveTextureCoordinate = centerTextureCoordinate + offset;
                                   twoStepsNegativeTextureCoordinate = centerTextureCoordinate - (offset * 2.0);
                                   twoStepsPositiveTextureCoordinate = centerTextureCoordinate + (offset * 2.0);
                               }
                               );
            break;
        case 3:
            return GLSL_STRING(120,
                               
                               uniform float texelWidthOffset;
                               uniform float texelHeightOffset;
                               
                               varying vec2 centerTextureCoordinate;
                               varying vec2 oneStepPositiveTextureCoordinate;
                               varying vec2 oneStepNegativeTextureCoordinate;
                               varying vec2 twoStepsPositiveTextureCoordinate;
                               varying vec2 twoStepsNegativeTextureCoordinate;
                               varying vec2 threeStepsPositiveTextureCoordinate;
                               varying vec2 threeStepsNegativeTextureCoordinate;
                               
                               void main()
                               {
                                   gl_TexCoord[0] = gl_MultiTexCoord0;
                                   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
                                   
                                   vec2 offset = vec2(texelWidthOffset, texelHeightOffset);
                                   
                                   centerTextureCoordinate = gl_TexCoord[0].xy;
                                   oneStepNegativeTextureCoordinate = centerTextureCoordinate - offset;
                                   oneStepPositiveTextureCoordinate = centerTextureCoordinate + offset;
                                   twoStepsNegativeTextureCoordinate = centerTextureCoordinate - (offset * 2.0);
                                   twoStepsPositiveTextureCoordinate = centerTextureCoordinate + (offset * 2.0);
                                   threeStepsNegativeTextureCoordinate = centerTextureCoordinate - (offset * 3.0);
                                   threeStepsPositiveTextureCoordinate = centerTextureCoordinate + (offset * 3.0);
                               }
                               );
            break;
        default:
            return GLSL_STRING(120,
                               
                               uniform float texelWidthOffset;
                               uniform float texelHeightOffset;
                               
                               varying vec2 centerTextureCoordinate;
                               varying vec2 oneStepPositiveTextureCoordinate;
                               varying vec2 oneStepNegativeTextureCoordinate;
                               varying vec2 twoStepsPositiveTextureCoordinate;
                               varying vec2 twoStepsNegativeTextureCoordinate;
                               varying vec2 threeStepsPositiveTextureCoordinate;
                               varying vec2 threeStepsNegativeTextureCoordinate;
                               varying vec2 fourStepsPositiveTextureCoordinate;
                               varying vec2 fourStepsNegativeTextureCoordinate;
                               
                               void main() {
                                   gl_TexCoord[0] = gl_MultiTexCoord0;
                                   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
                                   
                                   vec2 offset = vec2(texelWidthOffset, texelHeightOffset);
                                   
                                   centerTextureCoordinate = gl_TexCoord[0].xy;
                                   oneStepNegativeTextureCoordinate = centerTextureCoordinate - offset;
                                   oneStepPositiveTextureCoordinate = centerTextureCoordinate + offset;
                                   twoStepsNegativeTextureCoordinate = centerTextureCoordinate - (offset * 2.0);
                                   twoStepsPositiveTextureCoordinate = centerTextureCoordinate + (offset * 2.0);
                                   threeStepsNegativeTextureCoordinate = centerTextureCoordinate - (offset * 3.0);
                                   threeStepsPositiveTextureCoordinate = centerTextureCoordinate + (offset * 3.0);
                                   fourStepsNegativeTextureCoordinate = centerTextureCoordinate - (offset * 4.0);
                                   fourStepsPositiveTextureCoordinate = centerTextureCoordinate + (offset * 4.0);
                               }
                               );
            break;
            
            
    }
}

string DilationFilter::_getFragSrcForRadius(int radius) {
    switch (radius) {
        case 1:
            return GLSL_STRING(120,
                               varying vec2 centerTextureCoordinate;
                               varying vec2 oneStepPositiveTextureCoordinate;
                               varying vec2 oneStepNegativeTextureCoordinate;
                               
                               uniform sampler2D inputImageTexture;
                               
                               void main()
                               {
                                   float centerIntensity = texture2D(inputImageTexture, centerTextureCoordinate).r;
                                   float oneStepPositiveIntensity = texture2D(inputImageTexture, oneStepPositiveTextureCoordinate).r;
                                   float oneStepNegativeIntensity = texture2D(inputImageTexture, oneStepNegativeTextureCoordinate).r;
                                   
                                   float maxValue = max(centerIntensity, oneStepPositiveIntensity);
                                   maxValue = max(maxValue, oneStepNegativeIntensity);
                                   
                                   gl_FragColor = vec4(vec3(maxValue), 1.0);
                               }
                               );
            break;
        case 2:
            return GLSL_STRING(120,
                               varying vec2 centerTextureCoordinate;
                               varying vec2 oneStepPositiveTextureCoordinate;
                               varying vec2 oneStepNegativeTextureCoordinate;
                               varying vec2 twoStepsPositiveTextureCoordinate;
                               varying vec2 twoStepsNegativeTextureCoordinate;
                               
                               uniform sampler2D inputImageTexture;
                               
                               void main()
                               {
                                   float centerIntensity = texture2D(inputImageTexture, centerTextureCoordinate).r;
                                   float oneStepPositiveIntensity = texture2D(inputImageTexture, oneStepPositiveTextureCoordinate).r;
                                   float oneStepNegativeIntensity = texture2D(inputImageTexture, oneStepNegativeTextureCoordinate).r;
                                   float twoStepsPositiveIntensity = texture2D(inputImageTexture, twoStepsPositiveTextureCoordinate).r;
                                   float twoStepsNegativeIntensity = texture2D(inputImageTexture, twoStepsNegativeTextureCoordinate).r;
                                   
                                   float maxValue = max(centerIntensity, oneStepPositiveIntensity);
                                   maxValue = max(maxValue, oneStepNegativeIntensity);
                                   maxValue = max(maxValue, twoStepsPositiveIntensity);
                                   maxValue = max(maxValue, twoStepsNegativeIntensity);
                                   
                                   gl_FragColor = vec4(vec3(maxValue), 1.0);
                               }
                               );
        case 3:
            return GLSL_STRING(120,
                               varying vec2 centerTextureCoordinate;
                               varying vec2 oneStepPositiveTextureCoordinate;
                               varying vec2 oneStepNegativeTextureCoordinate;
                               varying vec2 twoStepsPositiveTextureCoordinate;
                               varying vec2 twoStepsNegativeTextureCoordinate;
                               varying vec2 threeStepsPositiveTextureCoordinate;
                               varying vec2 threeStepsNegativeTextureCoordinate;
                               
                               uniform sampler2D inputImageTexture;
                               
                               void main()
                               {
                                   float centerIntensity = texture2D(inputImageTexture, centerTextureCoordinate).r;
                                   float oneStepPositiveIntensity = texture2D(inputImageTexture, oneStepPositiveTextureCoordinate).r;
                                   float oneStepNegativeIntensity = texture2D(inputImageTexture, oneStepNegativeTextureCoordinate).r;
                                   float twoStepsPositiveIntensity = texture2D(inputImageTexture, twoStepsPositiveTextureCoordinate).r;
                                   float twoStepsNegativeIntensity = texture2D(inputImageTexture, twoStepsNegativeTextureCoordinate).r;
                                   float threeStepsPositiveIntensity = texture2D(inputImageTexture, threeStepsPositiveTextureCoordinate).r;
                                   float threeStepsNegativeIntensity = texture2D(inputImageTexture, threeStepsNegativeTextureCoordinate).r;
                                   
                                   float maxValue = max(centerIntensity, oneStepPositiveIntensity);
                                   maxValue = max(maxValue, oneStepNegativeIntensity);
                                   maxValue = max(maxValue, twoStepsPositiveIntensity);
                                   maxValue = max(maxValue, twoStepsNegativeIntensity);
                                   maxValue = max(maxValue, threeStepsPositiveIntensity);
                                   maxValue = max(maxValue, threeStepsNegativeIntensity);
                                   
                                   gl_FragColor = vec4(vec3(maxValue), 1.0);
                               }
                               );
            break;
        default:
            return GLSL_STRING(120,
                               varying vec2 centerTextureCoordinate;
                               varying vec2 oneStepPositiveTextureCoordinate;
                               varying vec2 oneStepNegativeTextureCoordinate;
                               varying vec2 twoStepsPositiveTextureCoordinate;
                               varying vec2 twoStepsNegativeTextureCoordinate;
                               varying vec2 threeStepsPositiveTextureCoordinate;
                               varying vec2 threeStepsNegativeTextureCoordinate;
                               varying vec2 fourStepsPositiveTextureCoordinate;
                               varying vec2 fourStepsNegativeTextureCoordinate;
                               
                               uniform sampler2D inputImageTexture;
                               
                               void main()
                               {
                                   float centerIntensity = texture2D(inputImageTexture, centerTextureCoordinate).r;
                                   float oneStepPositiveIntensity = texture2D(inputImageTexture, oneStepPositiveTextureCoordinate).r;
                                   float oneStepNegativeIntensity = texture2D(inputImageTexture, oneStepNegativeTextureCoordinate).r;
                                   float twoStepsPositiveIntensity = texture2D(inputImageTexture, twoStepsPositiveTextureCoordinate).r;
                                   float twoStepsNegativeIntensity = texture2D(inputImageTexture, twoStepsNegativeTextureCoordinate).r;
                                   float threeStepsPositiveIntensity = texture2D(inputImageTexture, threeStepsPositiveTextureCoordinate).r;
                                   float threeStepsNegativeIntensity = texture2D(inputImageTexture, threeStepsNegativeTextureCoordinate).r;
                                   float fourStepsPositiveIntensity = texture2D(inputImageTexture, fourStepsPositiveTextureCoordinate).r;
                                   float fourStepsNegativeIntensity = texture2D(inputImageTexture, fourStepsNegativeTextureCoordinate).r;
                                   
                                   float maxValue = max(centerIntensity, oneStepPositiveIntensity);
                                   maxValue = max(maxValue, oneStepNegativeIntensity);
                                   maxValue = max(maxValue, twoStepsPositiveIntensity);
                                   maxValue = max(maxValue, twoStepsNegativeIntensity);
                                   maxValue = max(maxValue, threeStepsPositiveIntensity);
                                   maxValue = max(maxValue, threeStepsNegativeIntensity);
                                   maxValue = max(maxValue, fourStepsPositiveIntensity);
                                   maxValue = max(maxValue, fourStepsNegativeIntensity);
                                   
                                   gl_FragColor = vec4(vec3(maxValue), 1.0);
                               }
                               );
            break;
    }
}

