//
//  ParameterT.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#ifndef __filterSandbox__ParameterT__
#define __filterSandbox__ParameterT__

#include "AbstractParameter.h"

class ParameterT : public AbstractParameter {
public:
	ParameterT(string name, ofTexture & texture, int textureIndex) : AbstractParameter(name) {
        _value = texture;
        _textureIndex = textureIndex;
        _type = FILTER_PARAMETER_TEXTURE;
    }
	virtual ~ParameterT() {}

    ofTexture & getValue() { return _value; }
    void        setValue(ofTexture & value) { _value = value; }
    int         getTextureIndex() { return _textureIndex; }
    
private:
    
    ofTexture   _value;
    int         _textureIndex;
};

#endif /* defined(__filterSandbox__ParameterT__) */
