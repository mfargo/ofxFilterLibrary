//
//  ZoomBlurFilter.cpp
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/25.
//
//

#include "ZoomBlurFilter.h"

ZoomBlurFilter::ZoomBlurFilter(float blurSize) : AbstractFilter(0, 0) {
    _name = "Zoom Blur";
    _addParameter(new Parameter2f("blurCenter", ofVec2f(0.5, 0.5)));
    _addParameter(new ParameterF("blurSize", blurSize ));
    _setupShader();
}
ZoomBlurFilter::~ZoomBlurFilter() {}

void ZoomBlurFilter::onKeyPressed(int key) {
    if (key==OF_KEY_UP) _blurSize += 0.1;
    else if (key==OF_KEY_DOWN) _blurSize -= 0.1;
    if (_blurSize<0) _blurSize = 0;
    updateParameter("blurSize", _blurSize);
}

string ZoomBlurFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;
        
        uniform vec2 blurCenter;
        uniform float blurSize;
        
        void main() {
            vec2 uv = gl_TexCoord[0].xy;
            vec2 samplingOffset = 1.0/100.0 * (blurCenter - uv) * blurSize;
            
            vec4 fragmentColor = texture2D(inputImageTexture, uv) * 0.18;
            fragmentColor += texture2D(inputImageTexture, uv + samplingOffset) * 0.15;
            fragmentColor += texture2D(inputImageTexture, uv + (2.0 * samplingOffset)) *  0.12;
            fragmentColor += texture2D(inputImageTexture, uv + (3.0 * samplingOffset)) * 0.09;
            fragmentColor += texture2D(inputImageTexture, uv + (4.0 * samplingOffset)) * 0.05;
            fragmentColor += texture2D(inputImageTexture, uv - samplingOffset) * 0.15;
            fragmentColor += texture2D(inputImageTexture, uv - (2.0 * samplingOffset)) *  0.12;
            fragmentColor += texture2D(inputImageTexture, uv - (3.0 * samplingOffset)) * 0.09;
            fragmentColor += texture2D(inputImageTexture, uv - (4.0 * samplingOffset)) * 0.05;
            
            gl_FragColor = fragmentColor;
            
        }
    );
}

void ZoomBlurFilter::begin() {
    updateParameter("blurCenter", ofVec2f((float)ofGetMouseX()/ofGetWidth(), (float)ofGetMouseY()/ofGetHeight()));
    _shader.begin();
    _updateParameters(&_shader);
}