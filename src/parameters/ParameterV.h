//
//  ParameterV.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef ofxFilterLibraryExample_ParameterV_h
#define ofxFilterLibraryExample_ParameterV_h

#include "AbstractParameter.h"

class ParameterV : public AbstractParameter {
public:
	ParameterV(string name, float * value, int numValues) : AbstractParameter(name) {
        _numValues = numValues;
        _value = value;
        _type = FILTER_PARAMETER_FV;
    }
	virtual ~ParameterV() {}
    
    float *     getValue() { return _value; }
    void        setValue(float * value) { _value = value; }
    void        setFloatAt(int index, float val) { _value[index] = val; }
    int         getNumValues() { return _numValues; }
    
    
private:
    
    float *     _value;
    int         _numValues;
};


#endif
