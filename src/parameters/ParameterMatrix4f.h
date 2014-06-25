//
//  ParameterMatrix4f.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/24.
//
//

#ifndef filterSandbox_ParameterMatrix4f_h
#define filterSandbox_ParameterMatrix4f_h

#include "AbstractParameter.h"

class ParameterMatrix4f : public AbstractParameter {
public:
	ParameterMatrix4f(string name, ofMatrix4x4 & value) : AbstractParameter(name) {
        _value = value;
        _type = FILTER_PARAMETER_MATRIX4F;
    }
	virtual ~ParameterMatrix4f() {}
    
    ofMatrix4x4 getValue() { return _value; }
    void        setValue(ofMatrix4x4 value) { _value = value; }
    
private:
    
    ofMatrix4x4 _value;
};


#endif
