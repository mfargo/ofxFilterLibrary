//
//  MultiplyBlendFilter.cpp
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/09.
//
//

#include "MultiplyBlendFilter.h"

MultiplyBlendFilter::MultiplyBlendFilter() : AbstractTwoInputFilter(0, 0) {
    _setupShader();

}
MultiplyBlendFilter::~MultiplyBlendFilter() {}


string MultiplyBlendFilter::_getFragSrc() {
    return GLSL_STRING(120,
        varying vec2 textureCoordinate;
        
        uniform sampler2D inputImageTexture;
        uniform sampler2D inputImageTexture2;
        
        void main()
        {
            vec4 overlayer = texture2D(inputImageTexture, textureCoordinate);
            vec4 base = texture2D(inputImageTexture2, textureCoordinate);
            
            gl_FragColor = overlayer * base + overlayer * (1.0 - base.a) + base * (1.0 - overlayer.a);
        }
    );
}