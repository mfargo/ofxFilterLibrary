//
//  Abstract3x3TextureSamplingFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#include "Abstract3x3TextureSamplingFilter.h"

Abstract3x3TextureSamplingFilter::Abstract3x3TextureSamplingFilter(float width, float height, ofVec2f texelSpacing) : AbstractFilter(width, height) {
    _texelSpacing = texelSpacing;
    _addParameter(new ParameterF("texelWidthOffset", _texelSpacing.x/getWidth()));
    _addParameter(new ParameterF("texelHeightOffset", _texelSpacing.y/getHeight()));
}
Abstract3x3TextureSamplingFilter::~Abstract3x3TextureSamplingFilter() {}


string Abstract3x3TextureSamplingFilter::_getVertSrc() {
    return GLSL_STRING(120,
       uniform float texelWidthOffset;
       uniform float texelHeightOffset;
       
       varying vec2 textureCoordinate;
       varying vec2 leftTextureCoordinate;
       varying vec2 rightTextureCoordinate;
       
       varying vec2 topTextureCoordinate;
       varying vec2 topLeftTextureCoordinate;
       varying vec2 topRightTextureCoordinate;
       
       varying vec2 bottomTextureCoordinate;
       varying vec2 bottomLeftTextureCoordinate;
       varying vec2 bottomRightTextureCoordinate;
       
       void main(){
           gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
           gl_TexCoord[0] = gl_MultiTexCoord0;
           textureCoordinate = gl_TexCoord[0].xy;
           
           vec2 widthStep = vec2(texelWidthOffset, 0.0);
           vec2 heightStep = vec2(0.0, texelHeightOffset);
           vec2 widthHeightStep = vec2(texelWidthOffset, texelHeightOffset);
           vec2 widthNegativeHeightStep = vec2(texelWidthOffset, -texelHeightOffset);
           
           leftTextureCoordinate = textureCoordinate.xy - widthStep;
           rightTextureCoordinate = textureCoordinate.xy + widthStep;
           
           topTextureCoordinate = textureCoordinate.xy - heightStep;
           topLeftTextureCoordinate = textureCoordinate.xy - widthHeightStep;
           topRightTextureCoordinate = textureCoordinate.xy + widthNegativeHeightStep;
           
           bottomTextureCoordinate = textureCoordinate.xy + heightStep;
           bottomLeftTextureCoordinate = textureCoordinate.xy - widthNegativeHeightStep;
           bottomRightTextureCoordinate = textureCoordinate.xy + widthHeightStep;
       }
    );
}

