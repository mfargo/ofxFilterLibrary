//
//  GaussianBlurFilter.cpp
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#include "GaussianBlurFilter.h"


GaussianBlurFilter::GaussianBlurFilter(float width, float height, float blurSize, float bloom) :Abstract3x3PingPongFilter(width, height, ofVec2f(1, 1)) {
    _name = "Gaussian Blur";
    _blurSize = blurSize;
    _bloom = bloom;
    _addParameter(new ParameterF("blurSize", blurSize));
    _addParameter(new ParameterF("bloom", bloom));
    _setupShader();
}
GaussianBlurFilter::~GaussianBlurFilter() {}


string GaussianBlurFilter::_getVertSrc() {
    return AbstractFilter::_getVertSrc();
}

string GaussianBlurFilter::_getFragSrc() {
    return GLSL_STRING(120,
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
}
