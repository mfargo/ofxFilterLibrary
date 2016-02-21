//
//  PoissonBlendFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/30.
//
//

#include "PoissonBlendFilter.h"

PoissonBlendFilter::PoissonBlendFilter(string blendImageUri, float width, float height, float mix, int numIterations) : AbstractTwoInputCrossTextureSamplingFilter(width, height, ofVec2f(1,1)) {
    _name = "Poisson Blend";
    ofImage blendImage = ofImage(blendImageUri);
    setSecondTexture(blendImage.getTexture());
    _addParameter(new ParameterF("mixturePercent", mix));
    _setupShader();
}
PoissonBlendFilter::PoissonBlendFilter(ofTexture & texture, float width, float height, float mix, int numIterations) : AbstractTwoInputCrossTextureSamplingFilter(width, height, ofVec2f(1,1)) {
    _name = "Poisson Blend";
    setSecondTexture(texture);
    _addParameter(new ParameterF("mixturePercent", mix));
    _setupShader();
}
PoissonBlendFilter::PoissonBlendFilter(float width, float height, float mix, int numIterations) : AbstractTwoInputCrossTextureSamplingFilter(width, height, ofVec2f(1,1)) {
    _name = "Poisson Blend";
    _addParameter(new ParameterF("mixturePercent", mix));
    _setupShader();
}
PoissonBlendFilter::~PoissonBlendFilter() {}

string PoissonBlendFilter::_getFragSrc() {
    return GLSL_STRING(120,
        varying vec2 textureCoordinate;
        varying vec2 leftTextureCoordinate;
        varying vec2 rightTextureCoordinate;
        varying vec2 topTextureCoordinate;
        varying vec2 bottomTextureCoordinate;
        
        varying vec2 textureCoordinate2;
        varying vec2 leftTextureCoordinate2;
        varying vec2 rightTextureCoordinate2;
        varying vec2 topTextureCoordinate2;
        varying vec2 bottomTextureCoordinate2;
        
        uniform sampler2D inputImageTexture;
        uniform sampler2D inputImageTexture2;
        
        uniform float mixturePercent;
        
        void main()
        {
            
            vec4 centerColor = texture2D(inputImageTexture, textureCoordinate);
            vec3 bottomColor = texture2D(inputImageTexture, bottomTextureCoordinate).rgb;
            vec3 leftColor = texture2D(inputImageTexture, leftTextureCoordinate).rgb;
            vec3 rightColor = texture2D(inputImageTexture, rightTextureCoordinate).rgb;
            vec3 topColor = texture2D(inputImageTexture, topTextureCoordinate).rgb;
            
            vec4 centerColor2 = texture2D(inputImageTexture2, textureCoordinate2);
            vec3 bottomColor2 = texture2D(inputImageTexture2, bottomTextureCoordinate2).rgb;
            vec3 leftColor2 = texture2D(inputImageTexture2, leftTextureCoordinate2).rgb;
            vec3 rightColor2 = texture2D(inputImageTexture2, rightTextureCoordinate2).rgb;
            vec3 topColor2 = texture2D(inputImageTexture2, topTextureCoordinate2).rgb;
            
            vec3 meanColor = (bottomColor + leftColor + rightColor + topColor) / 4.0;
            vec3 diffColor = centerColor.rgb - meanColor;
            
            vec3 meanColor2 = (bottomColor2 + leftColor2 + rightColor2 + topColor2) / 4.0;
            vec3 diffColor2 = centerColor2.rgb - meanColor2;
            
            vec3 gradColor = (meanColor + diffColor2);
            
            gl_FragColor = vec4(mix(centerColor.rgb, gradColor, centerColor2.a * mixturePercent), centerColor.a);
        }
    );
}

