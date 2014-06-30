//
//  AbstractTwoInputFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/30.
//
//

#include "AbstractTwoInputFilter.h"

AbstractTwoInputFilter::AbstractTwoInputFilter(float width, float height) : AbstractFilter(width, height) {
    _secondTexture.allocate(getWidth(), getHeight(), GL_RGB16);
    _addParameter(new ParameterT("inputImageTexture2", _secondTexture, 1));
}
AbstractTwoInputFilter::~AbstractTwoInputFilter() {}


string AbstractTwoInputFilter::_getVertSrc() {
    return GLSL_STRING(120,
        attribute vec4 inputTextureCoordinate;
        attribute vec4 inputTextureCoordinate2;
        
        varying vec2 textureCoordinate;
        
        void main() {
            gl_TexCoord[0] = gl_MultiTexCoord0;
            gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
            textureCoordinate = gl_TexCoord[0].xy;
        }
    );
}


void AbstractTwoInputFilter::setSecondTexture(ofTexture &texture) {
    _secondTexture = texture;
    updateParameter("inputImageTexture2", _secondTexture);
}