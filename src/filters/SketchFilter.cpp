//
//  SketchFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/03.
//
//

#include "SketchFilter.h"

SketchFilter::SketchFilter(float width, float height, float edgeStrength) : SobelEdgeDetectionFilter(width, height, edgeStrength) {
    _name = "Sketch";
    _setupShader();
}
SketchFilter::~SketchFilter() {}

string SketchFilter::_getFragSrc() {
    return GLSL_STRING(120,
        varying vec2 textureCoordinate;
        varying vec2 leftTextureCoordinate;
        varying vec2 rightTextureCoordinate;
        
        varying vec2 topTextureCoordinate;
        varying vec2 topLeftTextureCoordinate;
        varying vec2 topRightTextureCoordinate;
        
        varying vec2 bottomTextureCoordinate;
        varying vec2 bottomLeftTextureCoordinate;
        varying vec2 bottomRightTextureCoordinate;
        
        uniform float edgeStrength;
        
        uniform sampler2D inputImageTexture;
        
        void main()
        {
            float bottomLeftIntensity = texture2D(inputImageTexture, bottomLeftTextureCoordinate).r;
            float topRightIntensity = texture2D(inputImageTexture, topRightTextureCoordinate).r;
            float topLeftIntensity = texture2D(inputImageTexture, topLeftTextureCoordinate).r;
            float bottomRightIntensity = texture2D(inputImageTexture, bottomRightTextureCoordinate).r;
            float leftIntensity = texture2D(inputImageTexture, leftTextureCoordinate).r;
            float rightIntensity = texture2D(inputImageTexture, rightTextureCoordinate).r;
            float bottomIntensity = texture2D(inputImageTexture, bottomTextureCoordinate).r;
            float topIntensity = texture2D(inputImageTexture, topTextureCoordinate).r;
            float h = -topLeftIntensity - 2.0 * topIntensity - topRightIntensity + bottomLeftIntensity + 2.0 * bottomIntensity + bottomRightIntensity;
            float v = -bottomLeftIntensity - 2.0 * leftIntensity - topLeftIntensity + bottomRightIntensity + 2.0 * rightIntensity + topRightIntensity;
            
            float mag = 1.0 - (length(vec2(h, v)) * edgeStrength);
            
            gl_FragColor = vec4(vec3(mag), 1.0);
        }
    );
}