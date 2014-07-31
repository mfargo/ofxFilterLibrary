//
//  LineDrawingAlphaFilter.cpp
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/07.
//
//

#include "LineDrawingAlphaFilter.h"

LineDrawingAlphaFilter::LineDrawingAlphaFilter() : AbstractFilter(0, 0) {
    _setupShader();    
}
LineDrawingAlphaFilter::~LineDrawingAlphaFilter() {}


string LineDrawingAlphaFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;
       
       void main() {
           vec2 uv = gl_TexCoord[0].xy;
           vec4 color = texture2D(inputImageTexture, uv );
           gl_FragColor = vec4(0, 0, 0, 1- (color.r + color.g + color.b)/3.0 );
       }
    );
}
