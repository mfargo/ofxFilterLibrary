//
//  DarkenBlendFilter.cpp
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/27.
//
//

#include "DarkenBlendFilter.h"

DarkenBlendFilter::DarkenBlendFilter() : AbstractTwoInputFilter(0, 0){
    _setupShader();
}
DarkenBlendFilter::~DarkenBlendFilter() {}

string DarkenBlendFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       varying vec2 textureCoordinate;
                       
                       uniform sampler2D inputImageTexture;
                       uniform sampler2D inputImageTexture2;
                       
                       void main()
                       {
                           vec4 base = texture2D(inputImageTexture, textureCoordinate);
                           vec4 overlayer = texture2D(inputImageTexture2, textureCoordinate);
                           
                           gl_FragColor = vec4(min(overlayer.rgb * base.a, base.rgb * overlayer.a) + overlayer.rgb * (0.5) + base.rgb * (1.0 - overlayer.a), 1.0);
                       }
                       );
}
