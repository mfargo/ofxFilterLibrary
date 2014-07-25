//
//  EdgeTangentSmoothingFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/23.
//
//

#include "EdgeTangentSmoothingFilter.h"

EdgeTangentSmoothingFilter::EdgeTangentSmoothingFilter(float width, float height, ofVec2f offset, int halfWidth) : AbstractFilter(width, height) {

    _addParameter(new ParameterI("halfWidth", halfWidth));
    _addParameter(new ParameterF("texelWidthOffset", offset.x/getWidth()));
    _addParameter(new ParameterF("texelHeightOffset", offset.y/getHeight()));
    _setupShader();
}
EdgeTangentSmoothingFilter::~EdgeTangentSmoothingFilter() {}

string EdgeTangentSmoothingFilter::_getVertSrc() {
    return AbstractFilter::_getVertSrc();
}

string EdgeTangentSmoothingFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       uniform sampler2D inputImageTexture;
                       uniform int halfWidth;
                       uniform float texelWidthOffset;
                       uniform float texelHeightOffset;
                       
                       void main() {
                           vec2 uv = gl_TexCoord[0].xy;
                           vec4 color = texture2D(inputImageTexture, uv );
                           float weight;
                           float mag_diff;

                           vec4 g = vec4(0, 0, color.b, 1.0);
                           
                           for (int s=-halfWidth; s<=halfWidth; s++) {
                               vec2 offset = vec2(s*texelWidthOffset, s*texelHeightOffset);
                               vec4 c = texture2D(inputImageTexture, uv + offset);
                               mag_diff = c.b - color.b;
                               float factor = 1.0;
                               float angle = color.r*c.r + color.g*c.g;
                               if (angle < 0.0) factor = -1.0;
                               weight = mag_diff + 1.0;
                               
                               g.r += weight * c.r * factor;
                               g.g += weight * c.g * factor;
                           }
                           float mag = sqrt( g.r*g.r + g.g*g.g ) ;
                           
                           if (mag != 0.0) {
                               g.r /= mag;
                               g.g /= mag;
                           }
                           
                           gl_FragColor = g;
                       }
                       );
}

void EdgeTangentSmoothingFilter::setOffset(ofVec2f offset) {
    updateParameter("texelWidthOffset", offset.x/getWidth());
    updateParameter("texelHeightOffset", offset.y/getHeight());
}

