//
//  BloomFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2015/02/27.
//
//

#include "BloomFilter.h"

BloomFilter::BloomFilter(float width, float height) : AbstractFilter(width, height) {
    _name = "Bloom";
    _addParameter(new ParameterF("bloom", 4));
    _addParameter(new ParameterF("texelWidth", 1.f/getWidth()));
    _addParameter(new ParameterF("texelHeight", 1.f/getHeight()));
    _setupShader();
}
BloomFilter::~BloomFilter() {}


string BloomFilter::_getFragSrc() {
    
    return GLSL_STRING(120,
                       uniform sampler2D inputImageTexture;
                       uniform float bloom;
                       uniform float texelWidth;
                       uniform float texelHeight;
                       
                       void main() {
                           
                           vec4 sum = vec4(0);
                           vec2 texcoord = gl_TexCoord[0].xy;
                           int j;
                           int i;
                           
                           for( i= -4 ;i < 4; i++)
                               for (j = -3; j < 3; j++)
                                   sum += texture2D(inputImageTexture, texcoord + vec2(j, i)*0.004) * 0.25;
                           if (texture2D(inputImageTexture, texcoord).r < 0.3)
                               gl_FragColor = sum*sum*0.012 + texture2D(inputImageTexture, texcoord);
                           else {
                               if (texture2D(inputImageTexture, texcoord).r < 0.5)
                                   gl_FragColor = sum*sum*0.009 + texture2D(inputImageTexture, texcoord);
                               else
                                   gl_FragColor = sum*sum*0.0075 + texture2D(inputImageTexture, texcoord);
                           }
                           
                       }
                       );
}