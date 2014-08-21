//
//  NormalBlendFilter.cpp
//  ImageComparisonShader
//
//  Created by Matthew Fargo on 2014/08/11.
//
//

#include "NormalBlendFilter.h"

NormalBlendFilter::NormalBlendFilter() {
    _setupShader();
}
NormalBlendFilter::~NormalBlendFilter() {}


string NormalBlendFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       varying vec2 textureCoordinate;
                       
                       uniform sampler2D inputImageTexture;
                       uniform sampler2D inputImageTexture2;
                       
                       void main()
                       {
                           vec4 c2 = texture2D(inputImageTexture, textureCoordinate);
                           vec4 c1 = texture2D(inputImageTexture2, textureCoordinate);
                           
                           vec4 outputColor;
                           
                           //     outputColor.r = c1.r + c2.r * c2.a * (1.0 - c1.a);
                           //     outputColor.g = c1.g + c2.g * c2.a * (1.0 - c1.a);
                           //     outputColor.b = c1.b + c2.b * c2.a * (1.0 - c1.a);
                           //     outputColor.a = c1.a + c2.a * (1.0 - c1.a);
                           
                           float a = c1.a + c2.a * (1.0 - c1.a);
                           float alphaDivisor = a + step(a, 0.0); // Protect against a divide-by-zero blacking out things in the output

                           outputColor.r = (c1.r * c1.a + c2.r * c2.a * (1.0 - c1.a))/alphaDivisor;
                           outputColor.g = (c1.g * c1.a + c2.g * c2.a * (1.0 - c1.a))/alphaDivisor;
                           outputColor.b = (c1.b * c1.a + c2.b * c2.a * (1.0 - c1.a))/alphaDivisor;
                           outputColor.a = a;

                           gl_FragColor = outputColor;
                       }
                       );
}