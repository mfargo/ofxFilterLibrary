//
//  Parameter2f.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#ifndef filterSandbox_Parameter2f_h
#define filterSandbox_Parameter2f_h

#include "AbstractParameter.h"

class Parameter2f : public AbstractParameter {
public:
	Parameter2f(string name, ofVec2f value) : AbstractParameter(name) {
        _value = value;
        _type = FILTER_PARAMETER_2F;
    }
	virtual ~Parameter2f() {}
    
    ofVec2f     getValue() { return _value; }
    void        setValue(ofVec2f value) { _value = value; }
    
private:
    
    ofVec2f   _value;
};


#endif
