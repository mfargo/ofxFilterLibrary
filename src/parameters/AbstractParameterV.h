//
//  AbstractParameterV.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef ofxFilterLibraryExample_AbstractParameterV_h
#define ofxFilterLibraryExample_AbstractParameterV_h

#include "AbstractParameter.h"

class AbstractParameterV : public AbstractParameter {
public:
	AbstractParameterV(string name, float * value, int numValues) : AbstractParameter(name) {
        _value = value;
        _numValues = numValues;
    }
	virtual ~AbstractParameterV() {}
    
    float *     getValue() { return _value; }
    void        setValue(float * value) { _value = value; }
    int         getNumValues() { return _numValues; }
    
private:
    
    float *     _value;
    int         _numValues;
};


#endif
