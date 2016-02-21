//
//  ChromaKeyBlendFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2015/07/03.
//
//

#include "ChromaKeyBlendFilter.h"

ChromaKeyBlendFilter::ChromaKeyBlendFilter(ofVec3f keyColor, float thresholdSensitivity, float smoothing) {
    _name = "Chroma Key Blend";
    _addParameter(new Parameter3f("keyColor", keyColor));
    _addParameter(new ParameterF("thresholdSensitivity", thresholdSensitivity));
    _addParameter(new ParameterF("smoothing", smoothing));
    _setupShader();
}
ChromaKeyBlendFilter::~ChromaKeyBlendFilter() {}

string ChromaKeyBlendFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       varying vec2 textureCoordinate;
                       
                       uniform sampler2D inputImageTexture;
                       uniform sampler2D inputImageTexture2;
                       
                       uniform float thresholdSensitivity;
                       uniform float smoothing;
                       uniform vec3 keyColor;
                       
                       void main()
                       {
                           vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);
                           vec4 textureColor2 = texture2D(inputImageTexture2, textureCoordinate);
                           
                           float maskY = 0.2989 * keyColor.r + 0.5866 * keyColor.g + 0.1145 * keyColor.b;
                           float maskCr = 0.7132 * (keyColor.r - maskY);
                           float maskCb = 0.5647 * (keyColor.b - maskY);
                           
                           float Y = 0.2989 * textureColor.r + 0.5866 * textureColor.g + 0.1145 * textureColor.b;
                           float Cr = 0.7132 * (textureColor.r - Y);
                           float Cb = 0.5647 * (textureColor.b - Y);
                           
                           float blendValue = 1.0 - smoothstep(thresholdSensitivity, thresholdSensitivity + smoothing, distance(vec2(Cr, Cb), vec2(maskCr, maskCb)));
                           gl_FragColor = mix(textureColor, textureColor2, blendValue);
                       }
                       );
}
