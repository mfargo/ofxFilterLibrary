//
//  AbstractTwoInputFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/30.
//
//

#include "AbstractTwoInputFilter.h"
AbstractTwoInputFilter::AbstractTwoInputFilter() : AbstractFilter() {
    _addParameter(new ParameterT("inputImageTexture2", _secondTexture, 1));
}
AbstractTwoInputFilter::AbstractTwoInputFilter(string secondTextureUri) : AbstractFilter() {
    ofLoadImage(_secondTexture, secondTextureUri);
    setWidth(_secondTexture.getWidth());
    setHeight(_secondTexture.getHeight());
    _addParameter(new ParameterT("inputImageTexture2", _secondTexture, 1));
}

AbstractTwoInputFilter::AbstractTwoInputFilter(float width, float height) : AbstractFilter(width, height) {
    _secondTexture.allocate(getWidth(), getHeight(), GL_RGB16);
    _addParameter(new ParameterT("inputImageTexture2", _secondTexture, 1));
}
AbstractTwoInputFilter::~AbstractTwoInputFilter() {}


string AbstractTwoInputFilter::_getVertSrc() {
    return GLSL_STRING(120,
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