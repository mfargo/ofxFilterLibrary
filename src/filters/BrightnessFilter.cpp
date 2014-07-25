//
//  BrightnessFilter.cpp
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/24.
//
//

#include "BrightnessFilter.h"

BrightnessFilter::BrightnessFilter(float brightness) : AbstractFilter(0,0){
    _addParameter(new ParameterF("brightness", brightness));
    _setupShader();
}
BrightnessFilter::~BrightnessFilter() {}


string BrightnessFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       uniform sampler2D inputImageTexture;
                       uniform float brightness;
                       
                       void main() {
                           vec2 uv = gl_TexCoord[0].xy;
                           vec4 c = texture2D(inputImageTexture, uv );
                           gl_FragColor = vec4((c.rgb + vec3(brightness)), c.a);
                       }
                       );
}

void BrightnessFilter::setBrightness(float brightness) {
    updateParameter("brightness", brightness);
}