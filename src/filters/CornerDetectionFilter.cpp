//
//  CornerDetectionFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#include "CornerDetectionFilter.h"

CornerDetectionFilter::CornerDetectionFilter(float width, float height, float sensitivity) : AbstractFilter(width, height) {
    _name = "Corner Detection";
    _addParameter(new ParameterF("sensitivity", sensitivity));
    _setupShader();
}
CornerDetectionFilter::~CornerDetectionFilter() {}


string CornerDetectionFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;
        uniform float sensitivity;
        
        const float harrisConstant = 0.04;
        
        void main() {
            vec2 textureCoordinate = gl_TexCoord[0].xy;
            vec3 derivativeElements = texture2D(inputImageTexture, textureCoordinate).rgb;
            
            float derivativeSum = derivativeElements.x + derivativeElements.y;
            float zElement = (derivativeElements.z * 2.0) - 1.0;
            
            // R = Ix^2 * Iy^2 - Ixy * Ixy - k * (Ix^2 + Iy^2)^2
            float cornerness = derivativeElements.x * derivativeElements.y - (zElement * zElement) - harrisConstant * derivativeSum * derivativeSum;
            
            gl_FragColor = vec4(vec3(cornerness * sensitivity), 1.0);
        }
    );
}