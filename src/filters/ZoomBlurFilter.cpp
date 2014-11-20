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

void ZoomBlurFilter::setBlurCenter(ofVec2f center) {
    updateParameter("blurCenter", center);
}
