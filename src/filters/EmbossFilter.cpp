//
//  EmbossFilter.cpp
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/24.
//
//

#include "EmbossFilter.h"

EmbossFilter::EmbossFilter(float width, float height, float intensity) : AbstractFilter(width, height) {
    _name = "Emboss";
    _setup();
    _addParameter(new ParameterMatrix4f("convolutionMatrix", _matrix));
    _addParameter(new ParameterF("texelWidth", 1.f/getWidth()));
    _addParameter(new ParameterF("texelHeight", 1.f/getHeight()));
    setIntensity(intensity);
}
EmbossFilter::~EmbossFilter() {}

void EmbossFilter::onKeyPressed(int key) {
    if (key==OF_KEY_UP) _intensity+=0.2f;
    else if (key==OF_KEY_DOWN) _intensity-=0.2f;
    if (_intensity<0) _intensity = 0;
    setIntensity(_intensity);
}

void EmbossFilter::_setup() {
    string fragSrc = GLSL_STRING(120,
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
            
            gl_FragColor = vec4(resultColor, centerColor.a);
        }
    );
    string vertSrc = GLSL_STRING(120,
        uniform float texelWidth;
        uniform float texelHeight;

        varying vec2 textureCoordinate;
        varying vec2 leftTextureCoordinate;
        varying vec2 rightTextureCoordinate;

        varying vec2 topTextureCoordinate;
        varying vec2 topLeftTextureCoordinate;
        varying vec2 topRightTextureCoordinate;

        varying vec2 bottomTextureCoordinate;
        varying vec2 bottomLeftTextureCoordinate;
        varying vec2 bottomRightTextureCoordinate;

        void main() {
            //gl_Position = position;
            gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

            vec2 widthStep = vec2(texelWidth, 0.0);
            vec2 heightStep = vec2(0.0, texelHeight);
            vec2 widthHeightStep = vec2(texelWidth, texelHeight);
            vec2 widthNegativeHeightStep = vec2(texelWidth, -texelHeight);

            //textureCoordinate = inputTextureCoordinate.xy;
            textureCoordinate = vec2(gl_MultiTexCoord0);
            leftTextureCoordinate = textureCoordinate - widthStep;
            rightTextureCoordinate = textureCoordinate + widthStep;

            topTextureCoordinate = textureCoordinate - heightStep;
            topLeftTextureCoordinate = textureCoordinate - widthHeightStep;
            topRightTextureCoordinate = textureCoordinate + widthNegativeHeightStep;

            bottomTextureCoordinate = textureCoordinate + heightStep;
            bottomLeftTextureCoordinate = textureCoordinate - widthNegativeHeightStep;
            bottomRightTextureCoordinate = textureCoordinate + widthHeightStep;
        }
    );
    _shader.setupShaderFromSource(GL_VERTEX_SHADER, vertSrc);
    _shader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragSrc);
    _shader.linkProgram();
}

void EmbossFilter::setIntensity(float intensity) {
    _intensity = intensity;
        // really just need a Matrix3x3, but ofShader doesn't support that so whatevs
    _matrix.set(_intensity * (-2.0), -_intensity, 0, 0,
                -_intensity, 1.0, _intensity, 0,
                0.0f, _intensity, _intensity*2.f, 0,
                0, 0, 0, 0);
    updateParameter("convolutionMatrix", _matrix);

}
