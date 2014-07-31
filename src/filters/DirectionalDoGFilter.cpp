//
//  DirectionalDoGFilter.cpp
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/22.
//
//

#include "DirectionalDoGFilter.h"


DirectionalDoGFilter::DirectionalDoGFilter(float width, float height, float sigma, float tau, float sketchinessX, float sketchinessY) : AbstractDoGFilter(width, height, sigma) {
    _addParameter(makeGaussianVector(sigma*1.6, "gau2"));
    _addParameter(new ParameterF("tau", tau));
    _addParameter(new ParameterF("sketchinessX", sketchinessX));
    _addParameter(new ParameterF("sketchinessY", sketchinessY));
    _setupShader();
}
DirectionalDoGFilter::~DirectionalDoGFilter() {}



string DirectionalDoGFilter::_getFragSrc() {
    string fragSrc = GLSL_STRING(120,
         uniform sampler2D inputImageTexture;
         uniform sampler2D inputImageTexture2;

         uniform float gau[%%GAU_SIZE%%];
         uniform float gau2[%%GAU2_SIZE%%];
         uniform float tau;
         uniform float width;
         uniform float height;
         uniform float sketchinessX;
         uniform float sketchinessY;
         
         void main(){
             
             int half_w1 = %%GAU_SIZE%% - 1;
             int half_w2 = %%GAU2_SIZE%% - 1;
             
             float sum1 = 0.0;
             float sum2 = 0.0;
             
             float texelSizeWidth = 1.0/width;
             float texelSizeHeight = 1.0/height;
          
             vec2 uv = gl_TexCoord[0].xy;

             vec4 etf = texture2D(inputImageTexture2, uv);

             vec2 vn = vec2(-etf.g, etf.r) * vec2(sketchinessX, sketchinessY);
             
             if (vn.x == 0.0 && vn.y == 0.0) {
                 sum1 = 255.0;
                 sum2 = 255.0;
             }
             else {
                 float w_sum1 = 0.0;
                 float w_sum2 = 0.0;
                 
                 for (int s= - half_w2; s<half_w2; s++) {
                     
                     vec2 d = uv + vec2( vn.x * float(s) * texelSizeWidth, vn.y * float(s) * texelSizeHeight);
                     
                     vec4 c = texture2D(inputImageTexture, d);
                     
                     float val = c.r * 255.0;
                     
                     int dd = s; //int(abs(float(s)));
                     if (dd < 0) dd *= -1;
                     
                     float weight1;
                     if (dd > half_w1) weight1 = 0.0;
                     else weight1 = gau[dd];
                     
                     sum1 += val * weight1;
                     w_sum1 += weight1;
                     
                     float weight2 = gau2[dd];
                     sum2 += val * weight2;
                     w_sum2 += weight2;
                     
                 }
                 sum1 /= w_sum1;
                 sum2 /= w_sum2;
             }
             float total = sum1 - tau * sum2;
             gl_FragColor = vec4(total, total, total, 1.0 );
             
         }
        );
    ofStringReplace(fragSrc, "%%GAU_SIZE%%", ofToString(((ParameterV *)getParameter("gau"))->getNumValues()));
    ofStringReplace(fragSrc, "%%GAU2_SIZE%%", ofToString(((ParameterV *)getParameter("gau2"))->getNumValues()));
    return fragSrc;
}



