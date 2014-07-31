//
//  SaturationFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/27.
//
//

#include "SaturationFilter.h"

SaturationFilter::SaturationFilter(float saturation) : AbstractFilter (0, 0) {
    _addParameter(new ParameterF("saturation", saturation));
    _setupShader();
}
SaturationFilter::~SaturationFilter() {}

void SaturationFilter::setSaturation(float saturation) {
    updateParameter("saturation", saturation);
}

string SaturationFilter::_getFragSrc() {
    return GLSL_STRING(120,                       
                       uniform sampler2D inputImageTexture;
                       uniform float saturation;
                       
                       // Values from "Graphics Shaders: Theory and Practice" by Bailey and Cunningham
                       const vec3 luminanceWeighting = vec3(0.2125, 0.7154, 0.0721);
                       
                       void main()
                       {
                           vec2 uv = gl_TexCoord[0].xy;
                           vec4 textureColor = texture2D(inputImageTexture, uv);
                           float luminance = dot(textureColor.rgb, luminanceWeighting);
                           vec3 greyScaleColor = vec3(luminance);
                           
                           gl_FragColor = vec4(mix(greyScaleColor, textureColor.rgb, saturation), textureColor.w);
                           
                       }
                       );
}