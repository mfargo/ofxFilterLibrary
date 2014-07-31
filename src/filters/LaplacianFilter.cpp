//
//  LaplacianFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/30.
//
//

#include "LaplacianFilter.h"

LaplacianFilter::LaplacianFilter(float width, float height, ofVec2f texelSpacing) : Abstract3x3ConvolutionFilter(width, height, texelSpacing) {
    _name = "Laplacian";
    _matrix.set(0.5, 1.0, 0.5, 0.0,
            1.0, -6.0, 1.0, 0.0,
            0.5, 1.0, 0.5, 0.0,
            0.0, 0.0, 0.0, 0.0);
    updateParameter("convolutionMatrix", _matrix);
    _setupShader();
}
LaplacianFilter::~LaplacianFilter() {}


string LaplacianFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       uniform sampler2D inputImageTexture;
                       
                       uniform mat4 convolutionMatrix;
                       
                       varying vec2 textureCoordinate;
                       varying vec2 leftTextureCoordinate;
                       varying vec2 rightTextureCoordinate;
                       
                       varying vec2 topTextureCoordinate;
                       varying vec2 topLeftTextureCoordinate;
                       varying vec2 topRightTextureCoordinate;
                       
                       varying vec2 bottomTextureCoordinate;
                       varying vec2 bottomLeftTextureCoordinate;
                       varying vec2 bottomRightTextureCoordinate;
                       
                       void main()
                       {
                           vec3 bottomColor = texture2D(inputImageTexture, bottomTextureCoordinate).rgb;
                           vec3 bottomLeftColor = texture2D(inputImageTexture, bottomLeftTextureCoordinate).rgb;
                           vec3 bottomRightColor = texture2D(inputImageTexture, bottomRightTextureCoordinate).rgb;
                           vec4 centerColor = texture2D(inputImageTexture, textureCoordinate);
                           vec3 leftColor = texture2D(inputImageTexture, leftTextureCoordinate).rgb;
                           vec3 rightColor = texture2D(inputImageTexture, rightTextureCoordinate).rgb;
                           vec3 topColor = texture2D(inputImageTexture, topTextureCoordinate).rgb;
                           vec3 topRightColor = texture2D(inputImageTexture, topRightTextureCoordinate).rgb;
                           vec3 topLeftColor = texture2D(inputImageTexture, topLeftTextureCoordinate).rgb;
                           
                           vec3 resultColor = topLeftColor * convolutionMatrix[0][0] + topColor * convolutionMatrix[0][1] + topRightColor * convolutionMatrix[0][2];
                           resultColor += leftColor * convolutionMatrix[1][0] + centerColor.rgb * convolutionMatrix[1][1] + rightColor * convolutionMatrix[1][2];
                           resultColor += bottomLeftColor * convolutionMatrix[2][0] + bottomColor * convolutionMatrix[2][1] + bottomRightColor * convolutionMatrix[2][2];
                           
                           // Normalize the results to allow for negative gradients in the 0.0-1.0 colorspace
                           resultColor = resultColor + 0.5;
                           
                           gl_FragColor = vec4(resultColor, centerColor.a);
                       }
                       );
}