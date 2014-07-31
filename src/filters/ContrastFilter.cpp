//
//  ContrastFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/27.
//
//

#include "ContrastFilter.h"

ContrastFilter::ContrastFilter(float contrast) : AbstractFilter(0, 0) {
    _addParameter(new ParameterF("contrast", contrast));
    _setupShader();
}
ContrastFilter::~ContrastFilter() {}


void ContrastFilter::setContrast(float contrast) {
    updateParameter("contrast", contrast);
}

string ContrastFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       varying vec2 textureCoordinate;
                       
                       uniform sampler2D inputImageTexture;
                       uniform float contrast;
                       
                       void main()
                       {
                           vec2 uv = gl_TexCoord[0].xy;
                           vec4 textureColor = texture2D(inputImageTexture, uv);
                           
                           gl_FragColor = vec4(((textureColor.rgb - vec3(0.5)) * contrast + vec3(0.5)), textureColor.w);
                       }
                       );
}