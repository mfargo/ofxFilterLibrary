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