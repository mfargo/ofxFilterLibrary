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

    string s = (ofGetGLProgrammableRenderer()) ?
        GLSL_STRING(150,
            uniform mat4 orientationMatrix;
            uniform mat4 projectionMatrix;
            uniform mat4 modelViewMatrix;
            uniform mat4 textureMatrix;
            uniform mat4 modelViewProjectionMatrix;
            
            in vec4  position;
            in vec4  color;
            in vec3  normal;
            in float fractionalWidthOfPixel;
            in float aspectRatio;
            
            out vec4 colorVarying;

            void main()
            {
                colorVarying = color;
            }
        ) :
        GLSL_STRING(120,
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
    return s;
}