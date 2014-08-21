//
//  ColorBurnFilter.cpp
//  ImageComparisonShader
//
//  Created by Matthew Fargo on 2014/08/10.
//
//

#include "ColorBurnFilter.h"

ColorBurnFilter::ColorBurnFilter() {
    _setupShader();
}
ColorBurnFilter::~ColorBurnFilter() {}


string ColorBurnFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       varying vec2 textureCoordinate;
                       
                       uniform sampler2D inputImageTexture;
                       uniform sampler2D inputImageTexture2;
                       
                       void main()
                       {
                           vec4 base = texture2D(inputImageTexture, textureCoordinate);
                           vec4 overlayer = texture2D(inputImageTexture2, textureCoordinate);
                           vec4 whiteColor = vec4(1.0);
                           gl_FragColor = whiteColor - (whiteColor - base) / overlayer;

                       }
                       );
}