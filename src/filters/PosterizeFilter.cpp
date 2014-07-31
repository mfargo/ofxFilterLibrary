//
//  PosterizeFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/29.
//
//

#include "PosterizeFilter.h"

PosterizeFilter::PosterizeFilter(float colorLevels) {
    _name = "Posterize";
    _addParameter(new ParameterF("colorLevels", colorLevels));
    _setupShader();
}
PosterizeFilter::~PosterizeFilter() {}


string PosterizeFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       uniform sampler2D inputImageTexture;
                       uniform float colorLevels;
                       
                       void main() {
                           vec2 uv = gl_TexCoord[0].xy;
                           vec4 textureColor = texture2D(inputImageTexture, uv);

                           gl_FragColor = floor((textureColor * colorLevels) + vec4(0.5)) / colorLevels;
                           
                       }
                       );
}