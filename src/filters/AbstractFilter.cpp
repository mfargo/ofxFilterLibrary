//
//  AbstractFilter.cpp
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#include "AbstractFilter.h"


AbstractFilter::AbstractFilter(float width, float height) {
    setWidth(width);
    setHeight(height);
}
AbstractFilter::~AbstractFilter() {}

void AbstractFilter::_setupShader() {
    if (_shader.isLoaded()) _shader.unload();
    _shader.setupShaderFromSource(GL_VERTEX_SHADER, _getVertSrc());
    _shader.setupShaderFromSource(GL_FRAGMENT_SHADER, _getFragSrc());
    _shader.linkProgram();    
}

void AbstractFilter::begin() {
    _shader.begin();
    _updateParameters(&_shader);
}

void AbstractFilter::end() {
    _shader.end();
}

string AbstractFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;
        
        void main() {
            vec2 uv = gl_TexCoord[0].xy;
            gl_FragColor = texture2D(inputImageTexture, uv );
        }
    );
}

string AbstractFilter::_getVertSrc() {
    return GLSL_STRING(120,
           void main() {
               gl_TexCoord[0] = gl_MultiTexCoord0;
               gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
           }
        );
}

