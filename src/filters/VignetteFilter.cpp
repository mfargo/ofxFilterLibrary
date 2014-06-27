//
//  VignetteFilter.cpp
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#include "VignetteFilter.h"

VignetteFilter::VignetteFilter() : AbstractFilter(0, 0) {
    _name = "Vignette";
    _addParameter(new Parameter2f("vignetteCenter", ofVec2f(0.5, 0.5) ));
    _addParameter(new Parameter3f("vignetteColor", ofVec3f(0, 0, 0)));
    _addParameter(new ParameterF("vignetteStart", 0.3));
    _addParameter(new ParameterF("vignetteEnd", 0.75));
    _setupShader();
}
VignetteFilter::~VignetteFilter() {}



string VignetteFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;

        uniform vec2 vignetteCenter;
        uniform vec3 vignetteColor;
        uniform float vignetteStart;
        uniform float vignetteEnd;

        void main() {
            vec2 uv = gl_TexCoord[0].xy;
            vec4 sourceImageColor = texture2D(inputImageTexture, uv);
            float d = distance(uv, vec2(vignetteCenter.x, vignetteCenter.y));
            float percent = smoothstep(vignetteStart, vignetteEnd, d);
            gl_FragColor = vec4(mix(sourceImageColor.rgb, vignetteColor, percent), sourceImageColor.a);
        }
    );
}