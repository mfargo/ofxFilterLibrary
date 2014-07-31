//
//  GradientMapFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/30.
//
//

#include "GradientMapFilter.h"

GradientMapFilter::GradientMapFilter(vector<GradientMapColorPoint> colorPoints) {
    _name = "Gradient Map";
    //float * colors = new float[colorPoints.size()*3];
    vector<ofVec3f> colors;
    float * percents = new float[colorPoints.size()];
    for (int i=0; i<colorPoints.size(); i++) {
        percents[i] = colorPoints[i].p;
        colors.push_back(ofVec3f(colorPoints[i].r,colorPoints[i].g,colorPoints[i].b));
    }
    _addParameter(new Parameter3fv("colors", colors));
    _addParameter(new ParameterV("percents", percents, colorPoints.size()));
    _setupShader();
}
GradientMapFilter::~GradientMapFilter() {}

string GradientMapFilter::_getFragSrc() {
    string fragSrc = GLSL_STRING(120,
                                 uniform sampler2D inputImageTexture;
                                 
                                 uniform vec3 colors[%%NUM_COLORS%%];
                                 uniform float percents[%%NUM_COLORS%%];
                                 
                                 void main() {
                                     vec2 uv = gl_TexCoord[0].xy;
                                     vec4 color = texture2D(inputImageTexture, uv );
                                     
                                     float val = (color.r + color.g + color.b)/3.0;
                                     int top = 0;
                                     for (int i=1; i<%%NUM_COLORS%%; i++) {
                                         top = i;
                                         if (percents[i]>val) {
                                             break;
                                         }
                                     }
                                     int bottom = top - 1;
                                     //if (bottom < 0) bottom = 0;
                                     
                                     vec3 topColor = colors[top];
                                     vec3 bottomColor = colors[bottom];
                                     
                                     float diff = percents[top] - percents[bottom];
                                     
                                     float pdiff = val - percents[bottom];
                                     float percent = 1.0-pdiff/diff;
                                     vec3 result = mix(topColor, bottomColor, percent);
                                     
                                     gl_FragColor = vec4(result, color.a);
                                     
                                 }
                                 );
    ofStringReplace(fragSrc, "%%NUM_COLORS%%", ofToString(((ParameterV *)getParameter("percents"))->getNumValues()));
    return fragSrc;
}
