//
//  TiltShiftFilter.cpp
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#include "TiltShiftFilter.h"


TiltShiftFilter::TiltShiftFilter(ofTexture & texture, float focusPercent, float falloff) : AbstractFilter(texture.getWidth(), texture.getHeight()) {
    _name = "Tilt Shift";
    _texture = texture;
    _focusPercent=ofClamp(focusPercent, 0, 1);
    _gaussianBlurFilter = new GaussianBlurFilter(getWidth(), getHeight());
    _addParameter(new ParameterF("topFocusLevel", focusPercent));
    _addParameter(new ParameterF("bottomFocusLevel", 1.f - focusPercent));
    _addParameter(new ParameterF("focusFallOffRate", falloff));
    _addParameter(new ParameterT("inputImageTexture", _texture, 1));
    _addParameter(new ParameterT("inputImageTexture2", _gaussianBlurFilter->getTexture(), 2));
    _setupShader();
}
TiltShiftFilter::~TiltShiftFilter() {}

string TiltShiftFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;
        uniform sampler2D inputImageTexture2;

        uniform float topFocusLevel;
        uniform float bottomFocusLevel;
        uniform float focusFallOffRate;

        void main() {
            vec2 uv = gl_TexCoord[0].xy;
            vec4 sharpImageColor = texture2D(inputImageTexture, uv);
            vec4 blurredImageColor = texture2D(inputImageTexture2, uv);
            
            float blurIntensity = 1.0 - smoothstep(topFocusLevel - focusFallOffRate, topFocusLevel, uv.y);
            blurIntensity += smoothstep(bottomFocusLevel, bottomFocusLevel + focusFallOffRate, uv.y);
            
            gl_FragColor = mix(sharpImageColor, blurredImageColor, blurIntensity);
        }
    );
}

void TiltShiftFilter::begin() {
    _gaussianBlurFilter->begin();
    _texture.draw(0, 0);
    _gaussianBlurFilter->end();
    AbstractFilter::begin();
}


void TiltShiftFilter::describeParameters() {
    AbstractFilter::describeParameters();
    _gaussianBlurFilter->describeParameters();
}