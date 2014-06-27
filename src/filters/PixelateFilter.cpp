//
//  PixelateFilter.cpp
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/24.
//
//

#include "PixelateFilter.h"

PixelateFilter::PixelateFilter(float width, float height, float pixelRatio) : AbstractFilter(width, height) {
    _name = "Pixelate";
    _pixelRatio = pixelRatio;
    _addParameter(new ParameterF("fractionalWidthOfPixel", pixelRatio));
    _addParameter(new ParameterF("aspectRatio", getHeight()/getWidth() ));
    _setupShader();
}
PixelateFilter::~PixelateFilter() {}

void PixelateFilter::onKeyPressed(int key) {
    if (key==OF_KEY_UP) _pixelRatio+=0.01;
    else if (key==OF_KEY_DOWN) _pixelRatio-=0.01;
    if (_pixelRatio<0) _pixelRatio = 0;
    else if (_pixelRatio>1) _pixelRatio = 1;
    updateParameter("fractionalWidthOfPixel", _pixelRatio);
}

string PixelateFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;
        uniform float fractionalWidthOfPixel;
        uniform float aspectRatio;

        void main() {
            vec2 uv = gl_TexCoord[0].xy;
            vec2 sampleDivisor = vec2(fractionalWidthOfPixel, fractionalWidthOfPixel / aspectRatio);
            vec2 samplePos = uv - mod(uv, sampleDivisor) + 0.5 * sampleDivisor;
            gl_FragColor = texture2D(inputImageTexture, samplePos);
        }
    );
}