//
//  KuwaharaFilter.cpp
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#include "KuwaharaFilter.h"

KuwaharaFilter::KuwaharaFilter(int radius) : AbstractFilter(0, 0) {
    _name = "Kuwahara";
    _radius = radius;
    _addParameter(new ParameterI("radius", _radius));
    _setupShader();
}
KuwaharaFilter::~KuwaharaFilter() {}

void KuwaharaFilter::onKeyPressed(int key) {
    if (key==OF_KEY_DOWN) _radius--;
    else if (key==OF_KEY_UP) _radius++;
    if (_radius<0) _radius = 0;
    updateParameter("radius", _radius);
}

string KuwaharaFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;
        uniform int radius;

        const vec2 src_size = vec2 (1.0 / 680.0, 1.0 / 1024.0);

        void main (void) {
            vec2 uv = gl_TexCoord[0].xy;
            float n = float((radius + 1) * (radius + 1));
            int i; int j;
            vec3 m0 = vec3(0.0); vec3 m1 = vec3(0.0); vec3 m2 = vec3(0.0); vec3 m3 = vec3(0.0);
            vec3 s0 = vec3(0.0); vec3 s1 = vec3(0.0); vec3 s2 = vec3(0.0); vec3 s3 = vec3(0.0);
            vec3 c;
            
            for (j = -radius; j <= 0; ++j)  {
                for (i = -radius; i <= 0; ++i)  {
                    c = texture2D(inputImageTexture, uv + vec2(i,j) * src_size).rgb;
                    m0 += c;
                    s0 += c * c;
                }
            }
            
            for (j = -radius; j <= 0; ++j)  {
                for (i = 0; i <= radius; ++i)  {
                    c = texture2D(inputImageTexture, uv + vec2(i,j) * src_size).rgb;
                    m1 += c;
                    s1 += c * c;
                }
            }
            
            for (j = 0; j <= radius; ++j)  {
                for (i = 0; i <= radius; ++i)  {
                    c = texture2D(inputImageTexture, uv + vec2(i,j) * src_size).rgb;
                    m2 += c;
                    s2 += c * c;
                }
            }
            
            for (j = 0; j <= radius; ++j)  {
                for (i = -radius; i <= 0; ++i)  {
                    c = texture2D(inputImageTexture, uv + vec2(i,j) * src_size).rgb;
                    m3 += c;
                    s3 += c * c;
                }
            }
            
            
            float min_sigma2 = 1e+2;
            m0 /= n;
            s0 = abs(s0 / n - m0 * m0);
            
            float sigma2 = s0.r + s0.g + s0.b;
            if (sigma2 < min_sigma2) {
                min_sigma2 = sigma2;
                gl_FragColor = vec4(m0, 1.0);
            }
            
            m1 /= n;
            s1 = abs(s1 / n - m1 * m1);
            
            sigma2 = s1.r + s1.g + s1.b;
            if (sigma2 < min_sigma2) {
                min_sigma2 = sigma2;
                gl_FragColor = vec4(m1, 1.0);
            }
            
            m2 /= n;
            s2 = abs(s2 / n - m2 * m2);
            
            sigma2 = s2.r + s2.g + s2.b;
            if (sigma2 < min_sigma2) {
                min_sigma2 = sigma2;
                gl_FragColor = vec4(m2, 1.0);
            }
            
            m3 /= n;
            s3 = abs(s3 / n - m3 * m3);
            
            sigma2 = s3.r + s3.g + s3.b;
            if (sigma2 < min_sigma2) {
                min_sigma2 = sigma2;
                gl_FragColor = vec4(m3, 1.0);
            }
        }
    );
}