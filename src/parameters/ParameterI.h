//
//  ParameterI.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#ifndef __filterSandbox__ParameterI__
#define __filterSandbox__ParameterI__

#include "AbstractParameter.h"

class ParameterI : public AbstractParameter{
public:
	ParameterI(string name, int value) : AbstractParameter(name) {
        _value = value;
        _type = FILTER_PARAMETER_INT;
    }
	virtual ~ParameterI() {}

    int     getValue() { return _value; }
    void    setValue(int value) { _value = value; }
    
private:
    
    int     _value;
};

#endif /* defined(__filterSandbox__ParameterI__) */
