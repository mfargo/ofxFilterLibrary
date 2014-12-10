//
//  GammaFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/12/10.
//
//

#include "GammaFilter.h"


GammaFilter::GammaFilter(float gamma) {
    _setupShader();
    _addParameter(new ParameterF("gamma", gamma));
}
GammaFilter::~GammaFilter() {}

string GammaFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       uniform sampler2D inputImageTexture;
                       uniform float gamma;
                       
                       void main() {
                           vec2 textureCoordinate = gl_TexCoord[0].xy;
                           vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);
                           
                           gl_FragColor = vec4(pow(textureColor.rgb, vec3(gamma)), textureColor.w);
                       }
                       );
}