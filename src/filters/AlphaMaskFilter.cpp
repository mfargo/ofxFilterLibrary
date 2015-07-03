//
//  AlphaMaskFilter.cpp
//  ofxFilterLibrary
//
//  Created by Matthew Fargo on 2014/09/24.
//
//

#include "AlphaMaskFilter.h"

AlphaMaskFilter::AlphaMaskFilter() : AbstractTwoInputFilter() {
    _setupShader();
}
AlphaMaskFilter::~AlphaMaskFilter() {}



string AlphaMaskFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       varying vec2 textureCoordinate;
                       
                       uniform sampler2D inputImageTexture;
                       uniform sampler2D inputImageTexture2;
                       uniform float mixturePercent;
                       
                       void main()
                       {
                           vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);
                           vec4 textureColor2 = texture2D(inputImageTexture2, textureCoordinate);
                           float a = textureColor2.a;
                           if (a > 0) a = textureColor.a * a;
                           gl_FragColor = vec4(textureColor.rgb, a);
                       }
                       );
}
