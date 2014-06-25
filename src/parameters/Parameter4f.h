//
//  Parameter4f.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#ifndef filterSandbox_Parameter4f_h
#define filterSandbox_Parameter4f_h

#include "AbstractParameter.h"

class Parameter4f : public AbstractParameter {
public:
	Parameter4f(string name, ofVec4f value) : AbstractParameter(name) {
        _value = value;
        _type = FILTER_PARAMETER_4F;
    }
	virtual ~Parameter4f() {}
    
    ofVec4f     getValue() { return _value; }
    void        setValue(ofVec4f value) { _value = value; }
    
private:
    
    ofVec4f   _value;
};

#endif
