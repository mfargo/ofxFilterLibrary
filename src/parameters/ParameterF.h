//
//  ParameterF.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#ifndef __filterSandbox__ParameterF__
#define __filterSandbox__ParameterF__

#include "AbstractParameter.h"

class ParameterF : public AbstractParameter {
public:
	ParameterF(string name, float value) : AbstractParameter(name) {
        _value = value;
        _type = FILTER_PARAMETER_FLOAT;
    }
	virtual ~ParameterF() {}
    
    float   getValue() { return _value; }
    void    setValue(float value) { _value = value; }

private:
    
    float   _value;
};

#endif /* defined(__filterSandbox__ParameterF__) */
