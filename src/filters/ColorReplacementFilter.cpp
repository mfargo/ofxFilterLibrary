//
//  ColorReplacementFilter.cpp
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/26.
//
//

#include "ColorReplacementFilter.h"

ColorReplacementFilter::ColorReplacementFilter(vector<ofVec3f> fromColors, vector<ofVec3f>toColors) {
    if (toColors.size() < fromColors.size()) printf(" WARNING: ColorReplacementFilter vectors must be same size.");
    _addParameter(new Parameter3fv("fromColors", fromColors));
    _addParameter(new Parameter3fv("toColors", toColors));
    _setupShader();
}
ColorReplacementFilter::~ColorReplacementFilter() {}

string ColorReplacementFilter::_getFragSrc() {
    string fragSrc = GLSL_STRING(120,
                                 uniform sampler2D inputImageTexture;
                                
                                 uniform vec3 fromColors[%%FROM_SIZE%%];
                                 uniform vec3 toColors[%%TO_SIZE%%];
         
                                 void main() {
                                     vec2 uv = gl_TexCoord[0].xy;
                                     vec4 color = texture2D(inputImageTexture, uv );
                                     vec3 orig = color.rgb;
                                     int closest = 0;
                                     int closest2 = closest;
                                     float d = distance(orig, fromColors[0]);
                                     float d2 = d;
                                     for (int i=1; i<%%FROM_SIZE%%; i++) {
                                         float td = distance(orig, fromColors[i]);
                                         if (td<d) {
                                             d2 = d;
                                             d = td;
                                             closest2 = closest;
                                             closest = i;
                                         }
                                     }
                                     float percent = d/(d+d2);
                                     
                                     vec3 c = (percent*toColors[closest]) + ((1.0-percent)*toColors[closest2]);
                                     gl_FragColor = vec4(c, color.a);

                                 }
                           
           );
    ofStringReplace(fragSrc, "%%FROM_SIZE%%", ofToString(((ParameterV *)getParameter("fromColors"))->getNumValues()));
    ofStringReplace(fragSrc, "%%TO_SIZE%%", ofToString(((ParameterV *)getParameter("toColors"))->getNumValues()));
    return fragSrc;
}