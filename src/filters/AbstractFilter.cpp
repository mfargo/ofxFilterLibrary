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
    string s = (ofGetGLProgrammableRenderer()) ?
        GLSL_STRING(150,
            varying highp vec2 textureCoordinate;
            
            uniform sampler2D inputImageTexture;
            
            void main()
            {
                gl_FragColor = texture2D(inputImageTexture, textureCoordinate);
            }
        ) :
        GLSL_STRING(120,
            uniform sampler2D inputImageTexture;
            
            void main() {
                vec2 uv = gl_TexCoord[0].xy;
                gl_FragColor = texture2D(inputImageTexture, uv );
            }
        );
    return s;
}

string AbstractFilter::_getVertSrc() {
    string s = (ofGetGLProgrammableRenderer()) ?
        GLSL_STRING(150,
            uniform sampler2D tex;
            
            in vec4 colorVarying;
            
            out vec4 fragColor;
            
            void main (void) {
                fragColor = texture(tex, gl_PointCoord) * colorVarying;
            }
        ) :
        GLSL_STRING(120,
           void main() {
               gl_TexCoord[0] = gl_MultiTexCoord0;
               gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
           }
        );
    return s;
}

