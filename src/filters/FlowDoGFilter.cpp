//
//  FlowDoGFilter.cpp
//
//  Created by Matthew Fargo on 2014/07/25.
//
//

#include "FlowDoGFilter.h"

FlowDoGFilter::FlowDoGFilter(float width, float height, float sigma) : AbstractDoGFilter(width, height, sigma) {
    _setupShader();
}
FlowDoGFilter::~FlowDoGFilter() {}



// EFT comes in as texture2
// DoG comes in as texture1
string FlowDoGFilter::_getFragSrc() {
    string fragSrc = GLSL_STRING(120,
                                 uniform sampler2D inputImageTexture;
                                 uniform sampler2D inputImageTexture2;
                                 
                                 uniform float gau[%%GAU_SIZE%%];
                                 uniform float width;
                                 uniform float height;
                                 
                                 float tanh(float val) {
                                     float tmp = exp(val);
                                     float tanH = (tmp - 1.0 / tmp) / (tmp + 1.0 / tmp);
                                     return tanH;
                                 }
                                 void main() {
                                     
                                     int half_l = %%GAU_SIZE%% - 1;
                                     int flow_DOG_sign = 0;
                                     float step_size = 1.0;
                                     
                                     float texelSizeWidth = 1.0/width;
                                     float texelSizeHeight = 1.0/height;
                                     
                                     vec2 uv = gl_TexCoord[0].xy;
                                     vec4 color = texture2D(inputImageTexture, uv ) * 1.0001;
                                     vec4 etf = texture2D(inputImageTexture2, uv);
                                     
                                     float sum1 = 0.0;
                                     float weight1 = 0.0;
                                     
                                     float val = color.r;
                                     weight1 = gau[0];
                                     sum1 = val * weight1;
                                     float w_sum1 = weight1;
                                     
                                     vec2 d = uv;
                                     
                                     for (int k=0; k<half_l; k++) {
                                         vec2 vt = etf.xy;
                                         if (vt.x==0.0 && vt.y==0.0) break;
                                         vec4 c = texture2D(inputImageTexture, d );
                                         
                                         val = c.r;
                                         weight1 = gau[k];
                                         sum1 += val * weight1;
                                         w_sum1 += weight1;
                                         d.x += vt.x * step_size * texelSizeWidth;
                                         d.y += vt.y * step_size * texelSizeHeight;
                                         if (d.x < 0.0 || d.x > 1.0 || d.y < 0.0 || d.y > 1.0) break;
                                     }
                                     
                                     
                                     d = uv;
                                     for (int k=0; k<half_l; k++) {
                                         vec2 vt = etf.xy * -1.0;
                                         if (vt.x==0.0 && vt.y==0.0) break;
                                         vec4 c = texture2D(inputImageTexture, d );
                                         val = c.r;
                                         weight1 = gau[k];
                                         sum1 += val * weight1;
                                         w_sum1 += weight1;
                                         d.x += vt.x * step_size * texelSizeWidth;
                                         d.y += vt.y * step_size * texelSizeHeight;
                                         if (d.x < 0.0 || d.x > 1.0 || d.y < 0.0 || d.y > 1.0) break;
                                         
                                     }
                                     
                                     sum1 /= w_sum1;
                                     float total = 1.0 + tanh(sum1);
                                     if (sum1 > 0) total = 1.0;
                                     if (total < 0.0) total = 0.0;
                                     if (total > 1.0) total = 1.0;
                                     else gl_FragColor = vec4(total, total, total, 1.0);
                                 }
                                 
                                 );
    ofStringReplace(fragSrc, "%%GAU_SIZE%%", ofToString(((ParameterV *)getParameter("gau"))->getNumValues()));
    return fragSrc;
}
