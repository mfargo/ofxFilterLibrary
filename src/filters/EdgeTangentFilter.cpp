//
//  EdgeTangentFilter.cpp
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/22.
//
//

#include "EdgeTangentFilter.h"

EdgeTangentFilter::EdgeTangentFilter(float width, float height) : Abstract3x3TextureSamplingFilter(width, height, ofVec2f(1, 1)) {
    _setupShader();
}
EdgeTangentFilter::~EdgeTangentFilter() {}

string EdgeTangentFilter::_getFragSrc() {
    return GLSL_STRING(120,
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
                       
                       const float MAX_VAL = 1020.0;

                       void main() {
                           float bottomColor = texture2D(inputImageTexture, bottomTextureCoordinate).r;
                           float bottomLeftColor = texture2D(inputImageTexture, bottomLeftTextureCoordinate).r;
                           float bottomRightColor = texture2D(inputImageTexture, bottomRightTextureCoordinate).r;
                           float leftColor = texture2D(inputImageTexture, leftTextureCoordinate).r;
                           float rightColor = texture2D(inputImageTexture, rightTextureCoordinate).r;
                           float topColor = texture2D(inputImageTexture, topTextureCoordinate).r;
                           float topRightColor = texture2D(inputImageTexture, topRightTextureCoordinate).r;
                           float topLeftColor = texture2D(inputImageTexture, topLeftTextureCoordinate).r;
                           
                           vec2 v = vec2( (topRightColor + 2*rightColor + bottomRightColor - topLeftColor - 2*leftColor - bottomLeftColor)/MAX_VAL, (bottomLeftColor + 2*bottomColor + bottomRightColor - topLeftColor - 2*topColor - topRightColor)/MAX_VAL);
                           
                           vec4 c = vec4(-v.y, v.x, 0, 1.0);
                           float b = sqrt(c.r * c.r + c.g * c.g);
                           
                           if (b!=0.0) {
                               c.r /= b;
                               c.g /= b;
                           }
                           gl_FragColor = vec4(c.r, c.g, b, 1.0);

                       }
                       );
}
