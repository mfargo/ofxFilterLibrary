//
//  ColorMatrixFilter.cpp
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/27.
//
//

#include "ColorMatrixFilter.h"

ColorMatrixFilter::ColorMatrixFilter() :AbstractFilter(0, 0) {
}
ColorMatrixFilter::~ColorMatrixFilter() {}


string ColorMatrixFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       varying vec2 textureCoordinate;
                       
                       uniform sampler2D inputImageTexture;
                       
                       uniform mat4 colorMatrix;
                       uniform float intensity;
                       
                       void main()
                       {
                           vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);
                           vec4 outputColor = textureColor * colorMatrix;
                           
                           gl_FragColor = (intensity * outputColor) + ((1.0 - intensity) * textureColor);
                       }
                       );
}
