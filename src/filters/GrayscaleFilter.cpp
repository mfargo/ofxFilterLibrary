//
//  GrayscaleFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#include "GrayscaleFilter.h"

GrayscaleFilter::GrayscaleFilter() : AbstractFilter() {
    _name = "Grayscale";
    _setupShader();
}
GrayscaleFilter::~GrayscaleFilter() {}


string GrayscaleFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;
        
        const vec3 W = vec3(0.2125, 0.7154, 0.0721);
        
        void main() {
            vec2 textureCoordinate = gl_TexCoord[0].xy;
            
            vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);
            float luminance = dot(textureColor.rgb, W);
            
            gl_FragColor = vec4(vec3(luminance), textureColor.a);
        }
    );
}