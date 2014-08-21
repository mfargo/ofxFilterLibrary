//
//  ColorBlendFilter.cpp
//  ImageComparisonShader
//
//  Created by Matthew Fargo on 2014/08/10.
//
//

#include "ColorBlendFilter.h"

ColorBlendFilter::ColorBlendFilter() {
    _setupShader();
}
ColorBlendFilter::~ColorBlendFilter() {}



string ColorBlendFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       varying vec2 textureCoordinate;
                       
                       uniform sampler2D inputImageTexture;
                       uniform sampler2D inputImageTexture2;
                       
                       float lum(vec3 c) {
                           return dot(c, vec3(0.3, 0.59, 0.11));
                       }
                       
                       vec3 clipcolor(vec3 c) {
                           float l = lum(c);
                           float n = min(min(c.r, c.g), c.b);
                           float x = max(max(c.r, c.g), c.b);
                           
                           if (n < 0.0) {
                               c.r = l + ((c.r - l) * l) / (l - n);
                               c.g = l + ((c.g - l) * l) / (l - n);
                               c.b = l + ((c.b - l) * l) / (l - n);
                           }
                           if (x > 1.0) {
                               c.r = l + ((c.r - l) * (1.0 - l)) / (x - l);
                               c.g = l + ((c.g - l) * (1.0 - l)) / (x - l);
                               c.b = l + ((c.b - l) * (1.0 - l)) / (x - l);
                           }
                           
                           return c;
                       }
                       
                       vec3 setlum(vec3 c, float l) {
                           float d = l - lum(c);
                           c = c + vec3(d);
                           return clipcolor(c);
                       }
                       
                       void main()
                       {
                           vec4 overlayColor = texture2D(inputImageTexture, textureCoordinate);
                           vec4 baseColor = texture2D(inputImageTexture2, textureCoordinate);
                           
                           gl_FragColor = vec4(baseColor.rgb * (1.0 - overlayColor.a) + setlum(overlayColor.rgb, lum(baseColor.rgb)) * overlayColor.a, baseColor.a);
                       }
                       );
}