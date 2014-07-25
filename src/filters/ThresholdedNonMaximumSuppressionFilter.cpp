//
//  ThresholdedNonMaximumSuppressionFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#include "ThresholdedNonMaximumSuppressionFilter.h"

ThresholdedNonMaximumSuppressionFilter::ThresholdedNonMaximumSuppressionFilter(float width, float height, bool usesPackedColorSpace, float texelSpacing) : Abstract3x3TextureSamplingFilter(width, height, ofVec2f(texelSpacing, texelSpacing)) {
    _name = "Threshold Non-Maximum Suppression";
    _usesPackedColorSpace = usesPackedColorSpace;
    _setupShader();
}
ThresholdedNonMaximumSuppressionFilter::~ThresholdedNonMaximumSuppressionFilter() {}


string ThresholdedNonMaximumSuppressionFilter::_getFragSrc() {
    return (_usesPackedColorSpace) ?
        GLSL_STRING(120,
            uniform sampler2D inputImageTexture;
            
            varying vec2 textureCoordinate;
            varying vec2 leftTextureCoordinate;
            varying vec2 rightTextureCoordinate;
            
            varying vec2 topTextureCoordinate;
            varying vec2 topLeftTextureCoordinate;
            varying vec2 topRightTextureCoordinate;
            
            varying vec2 bottomTextureCoordinate;
            varying vec2 bottomLeftTextureCoordinate;
            varying vec2 bottomRightTextureCoordinate;
            
            uniform float threshold;
            
            void main()
            {
                float bottomColor = texture2D(inputImageTexture, bottomTextureCoordinate).r;
                float bottomLeftColor = texture2D(inputImageTexture, bottomLeftTextureCoordinate).r;
                float bottomRightColor = texture2D(inputImageTexture, bottomRightTextureCoordinate).r;
                vec4 centerColor = texture2D(inputImageTexture, textureCoordinate);
                float leftColor = texture2D(inputImageTexture, leftTextureCoordinate).r;
                float rightColor = texture2D(inputImageTexture, rightTextureCoordinate).r;
                float topColor = texture2D(inputImageTexture, topTextureCoordinate).r;
                float topRightColor = texture2D(inputImageTexture, topRightTextureCoordinate).r;
                float topLeftColor = texture2D(inputImageTexture, topLeftTextureCoordinate).r;
                
                float multiplier = 1.0 - step(centerColor.r, topColor);
                multiplier = multiplier * 1.0 - step(centerColor.r, topLeftColor);
                multiplier = multiplier * 1.0 - step(centerColor.r, leftColor);
                multiplier = multiplier * 1.0 - step(centerColor.r, bottomLeftColor);
                
                float maxValue = max(centerColor.r, bottomColor);
                maxValue = max(maxValue, bottomRightColor);
                maxValue = max(maxValue, rightColor);
                maxValue = max(maxValue, topRightColor);
                
                float finalValue = centerColor.r * step(maxValue, centerColor.r) * multiplier;
                finalValue = step(threshold, finalValue);
                
                gl_FragColor = vec4(finalValue, finalValue, finalValue, 1.0);
            }
        ) : GLSL_STRING(120,
            uniform sampler2D inputImageTexture;
            
            varying vec2 textureCoordinate;
            varying vec2 leftTextureCoordinate;
            varying vec2 rightTextureCoordinate;
            
            varying vec2 topTextureCoordinate;
            varying vec2 topLeftTextureCoordinate;
            varying vec2 topRightTextureCoordinate;
            
            varying vec2 bottomTextureCoordinate;
            varying vec2 bottomLeftTextureCoordinate;
            varying vec2 bottomRightTextureCoordinate;
            
            uniform float threshold;
            
            void main()
            {
                float bottomColor = texture2D(inputImageTexture, bottomTextureCoordinate).r;
                float bottomLeftColor = texture2D(inputImageTexture, bottomLeftTextureCoordinate).r;
                float bottomRightColor = texture2D(inputImageTexture, bottomRightTextureCoordinate).r;
                vec4 centerColor = texture2D(inputImageTexture, textureCoordinate);
                float leftColor = texture2D(inputImageTexture, leftTextureCoordinate).r;
                float rightColor = texture2D(inputImageTexture, rightTextureCoordinate).r;
                float topColor = texture2D(inputImageTexture, topTextureCoordinate).r;
                float topRightColor = texture2D(inputImageTexture, topRightTextureCoordinate).r;
                float topLeftColor = texture2D(inputImageTexture, topLeftTextureCoordinate).r;
                
                float multiplier = 1.0 - step(centerColor.r, topColor);
                multiplier = multiplier * 1.0 - step(centerColor.r, topLeftColor);
                multiplier = multiplier * 1.0 - step(centerColor.r, leftColor);
                multiplier = multiplier * 1.0 - step(centerColor.r, bottomLeftColor);
                
                float maxValue = max(centerColor.r, bottomColor);
                maxValue = max(maxValue, bottomRightColor);
                maxValue = max(maxValue, rightColor);
                maxValue = max(maxValue, topRightColor);
                
                float finalValue = centerColor.r * step(maxValue, centerColor.r) * multiplier;
                finalValue = step(threshold, finalValue);
                
                gl_FragColor = vec4(finalValue, finalValue, finalValue, 1.0);
            }
        );
}


