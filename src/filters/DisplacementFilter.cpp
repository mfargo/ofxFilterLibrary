//
//  DisplacementFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/31.
//
//

#include "DisplacementFilter.h"

DisplacementFilter::DisplacementFilter(string imageUri, float width, float height, float strength) : AbstractTwoInputCrossTextureSamplingFilter(width, height, ofVec2f(strength, strength)) {
    _name = "Displacement";
    ofImage blendImage = ofImage(imageUri);
    setSecondTexture(blendImage.getTexture());
    _setupShader();
}

DisplacementFilter::DisplacementFilter(float width, float height, float strength) : AbstractTwoInputCrossTextureSamplingFilter(width, height, ofVec2f(strength, strength)) {
    _name = "Displacement";
    _setupShader();
}
DisplacementFilter::~DisplacementFilter() {}

string DisplacementFilter::_getVertSrc() {
    return AbstractFilter::_getVertSrc();
}

string DisplacementFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       uniform float texelWidth;
                       uniform float texelHeight;
                       
                       uniform sampler2D inputImageTexture;
                       uniform sampler2D inputImageTexture2;
                       
                       void main() {
                           vec2 uv = gl_TexCoord[0].xy;
                           vec2 offset = texture2D(inputImageTexture2, uv ).xy * vec2(texelWidth, texelHeight);
                           gl_FragColor = texture2D(inputImageTexture, uv + offset.xy);
                       }
                       );
}