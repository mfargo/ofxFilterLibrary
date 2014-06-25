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

void AbstractFilter::begin() {
    _shader.begin();
    _updateParameters(&_shader);
}

void AbstractFilter::end() {
    _shader.end();
}

#pragma utility functions

string AbstractFilter::_getPassthroughVertexShader() {
    return GLSL_STRING(120,
       void main() {
           gl_TexCoord[0] = gl_MultiTexCoord0;
           gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
           //gl_Position = ftransform();  // not using this cuz we might blend later
       }
    );
}

