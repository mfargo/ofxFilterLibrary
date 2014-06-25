//
//  TiltShiftFilter.cpp
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#include "TiltShiftFilter.h"


TiltShiftFilter::TiltShiftFilter(ofTexture & texture, float topFocus, float bottomFocus, float falloff) : AbstractFilter(texture.getWidth(), texture.getHeight()) {
    _name = "Tilt Shift";
    _texture = texture;
    _setup();
    _gaussianBlurFilter = new GaussianBlurFilter(getWidth(), getHeight());
    _addParameter(new ParameterF("topFocusLevel", topFocus));
    _addParameter(new ParameterF("bottomFocusLevel", bottomFocus));
    _addParameter(new ParameterF("focusFallOffRate", falloff));
    _addParameter(new ParameterT("inputImageTexture", _texture, 1));
    _addParameter(new ParameterT("inputImageTexture2", _gaussianBlurFilter->getTextureReference(), 2));
}
TiltShiftFilter::~TiltShiftFilter() {}

void TiltShiftFilter::_setup() {
    if (getWidth()<=0 || getHeight() <= 0) return;
    
    string fragSource = GLSL_STRING(120,
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
    
    _shader.setupShaderFromSource(GL_VERTEX_SHADER, _getPassthroughVertexShader());
    _shader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragSource);
    _shader.linkProgram();
}

void TiltShiftFilter::onKeyPressed(int key) {
    if (key=='>' || key=='.') {
        float focusFallOffRate = ((ParameterF *)getParameter("focusFallOffRate"))->getValue();
        focusFallOffRate += 0.05f;
        if (focusFallOffRate>1.f) focusFallOffRate = 1.f;
        updateParameter("focusFallOffRate", focusFallOffRate);
    }
    else if (key=='<' || key==',') {
        float focusFallOffRate = ((ParameterF *)getParameter("focusFallOffRate"))->getValue();
        focusFallOffRate -= 0.05f;
        if (focusFallOffRate<0) focusFallOffRate = 0;
        updateParameter("focusFallOffRate", focusFallOffRate);

    }
    else _gaussianBlurFilter->onKeyPressed(key);
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