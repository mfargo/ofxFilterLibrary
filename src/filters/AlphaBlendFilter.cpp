//
//  AlphaBlendFilter.cpp
//  ofxFilterLibrary
//
//  Created by Matthew Fargo on 2014/09/24.
//
//

#include "AlphaBlendFilter.h"

AlphaBlendFilter::AlphaBlendFilter(float mixturePercent) : AbstractTwoInputFilter() {
    _setupShader();
    _addParameter(new ParameterF("mixturePercent", mixturePercent));
}
AlphaBlendFilter::~AlphaBlendFilter() {}

string AlphaBlendFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       varying vec2 textureCoordinate;
                       
                       uniform sampler2D inputImageTexture;
                       uniform sampler2D inputImageTexture2;
                       uniform float mixturePercent;
                       
                       void main()
                       {
                           vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);
                           vec4 textureColor2 = texture2D(inputImageTexture2, textureCoordinate);
                           gl_FragColor = vec4(mix(textureColor.rgb, textureColor2.rgb, textureColor2.a * mixturePercent), textureColor.a);
                       }
                       );

}