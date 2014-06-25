//
//  Parameter3f.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#ifndef filterSandbox_Parameter3f_h
#define filterSandbox_Parameter3f_h

#include "AbstractParameter.h"

class Parameter3f : public AbstractParameter {
public:
	Parameter3f(string name, ofVec3f value) : AbstractParameter(name) {
        _value = value;
        _type = FILTER_PARAMETER_3F;
    }
	virtual ~Parameter3f() {}
    
    ofVec3f     getValue() { return _value; }
    void        setValue(ofVec3f value) { _value = value; }
    
private:
    
    ofVec3f   _value;
};


#endif
