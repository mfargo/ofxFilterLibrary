//
//  AbstractTwoInputCrossTextureSamplingFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/30.
//
//

#include "AbstractTwoInputCrossTextureSamplingFilter.h"

AbstractTwoInputCrossTextureSamplingFilter::AbstractTwoInputCrossTextureSamplingFilter(string secondTextureUri, ofVec2f texelSpacing) : AbstractTwoInputFilter(secondTextureUri) {
    _texelSpacing = texelSpacing;
    _addParameter(new ParameterF("texelWidth", _texelSpacing.x/getWidth()));
    _addParameter(new ParameterF("texelHeight", _texelSpacing.y/getHeight()));
}

AbstractTwoInputCrossTextureSamplingFilter::AbstractTwoInputCrossTextureSamplingFilter(float width, float height, ofVec2f texelSpacing) : AbstractTwoInputFilter(width, height) {
    _texelSpacing = texelSpacing;
    _addParameter(new ParameterF("texelWidth", _texelSpacing.x/getWidth()));
    _addParameter(new ParameterF("texelHeight", _texelSpacing.y/getHeight()));
    
}
AbstractTwoInputCrossTextureSamplingFilter::~AbstractTwoInputCrossTextureSamplingFilter() {}



string AbstractTwoInputCrossTextureSamplingFilter::_getVertSrc() {
    return GLSL_STRING(120,
        uniform float texelWidth;
        uniform float texelHeight;
        
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
        
        void main()
        {
            gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
            gl_TexCoord[0] = gl_MultiTexCoord0;
            textureCoordinate = gl_TexCoord[0].xy;
            
            //gl_TexCoord[1] = gl_MultiTexCoord1;
            //textureCoordinate2 = gl_TexCoord[1].xy;
            textureCoordinate2 = textureCoordinate;
            
            vec2 widthStep = vec2(texelWidth, 0.0);
            vec2 heightStep = vec2(0.0, texelHeight);
            
            leftTextureCoordinate = textureCoordinate.xy - widthStep;
            rightTextureCoordinate = textureCoordinate.xy + widthStep;
            topTextureCoordinate = textureCoordinate.xy - heightStep;
            bottomTextureCoordinate = textureCoordinate.xy + heightStep;
            
            textureCoordinate2 = textureCoordinate2.xy;
            leftTextureCoordinate2 = textureCoordinate2.xy - widthStep;
            rightTextureCoordinate2 = textureCoordinate2.xy + widthStep;
            topTextureCoordinate2 = textureCoordinate2.xy - heightStep;
            bottomTextureCoordinate2 = textureCoordinate2.xy + heightStep;
        }
    );
}
