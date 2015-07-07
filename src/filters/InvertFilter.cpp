//
//  InvertFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2015/07/07.
//
//

#include "InvertFilter.h"

InvertFilter::InvertFilter() {
    _name = "Invert";
    _setupShader();
}
InvertFilter::~InvertFilter() {}

string InvertFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       uniform sampler2D inputImageTexture;
                       
                       void main()
                       {
                           vec2 uv = gl_TexCoord[0].xy;
                           vec4 textureColor = texture2D(inputImageTexture, uv );
                           gl_FragColor = vec4((1.0 - textureColor.rgb), textureColor.w);
                       }
                       );
}
