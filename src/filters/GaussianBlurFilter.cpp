//
//  GaussianBlurFilter.cpp
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#include "GaussianBlurFilter.h"


GaussianBlurFilter::GaussianBlurFilter(float width, float height, float blurSize, float bloom) : AbstractTwoPassFilter(width, height, ofVec2f(1, 1)) {
    _name = "Gaussian Blur";
    _blurSize = blurSize;
    _bloom = bloom;
    _setup();
    _addParameter(new ParameterF("blurSize", blurSize));
    _addParameter(new ParameterF("bloom", bloom));
}
GaussianBlurFilter::~GaussianBlurFilter() {}

void GaussianBlurFilter::onKeyPressed(int key) {
    if (key==OF_KEY_LEFT) _blurSize--;
    else if (key==OF_KEY_RIGHT) _blurSize++;
    else if (key==OF_KEY_UP) _bloom += 0.1;
    else if (key==OF_KEY_DOWN) _bloom -= 0.1;
    if (_blurSize<0) _blurSize = 0;
    if (_bloom<0) _bloom = 0;
    updateParameter("blurSize", _blurSize);
    updateParameter("bloom", _bloom);
}

void GaussianBlurFilter::_setup() {
    string fragSrc = GLSL_STRING(120,
        uniform sampler2D texture0;
        uniform float blurSize;
        uniform float bloom;
        uniform float texelWidthOffset;
        uniform float texelHeightOffset;
        
        void main() {
        float v;
        float pi = 3.141592653589793;
        float radius = blurSize;
        if ( radius < 0 ) radius = 0;
        int steps = int(min(radius * 0.7, sqrt(radius) * pi));
        float r = radius / steps;
        float t = bloom / (steps * 2 + 1);
        float x = gl_TexCoord[0].x;
        float y = gl_TexCoord[0].y;
        vec4 sum = texture2D(texture0, vec2(x, y)) * t;
        int i;
        for(i = 1; i <= steps; i++){
            v = (cos(i / (steps + 1) / pi) + 1) * 0.5;
            sum += texture2D(texture0, vec2(x + i * texelWidthOffset * r, y + i * texelHeightOffset * r)) * v * t;
            sum += texture2D(texture0, vec2(x - i * texelWidthOffset * r, y - i * texelHeightOffset * r)) * v * t;
        }
        
        gl_FragColor = sum;
        
    }
    );

    _shader.setupShaderFromSource(GL_VERTEX_SHADER, _getPassthroughVertexShader());
    _shader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragSrc);
    _shader.linkProgram();
}
