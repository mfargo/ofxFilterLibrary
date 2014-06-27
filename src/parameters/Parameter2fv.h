//
//  Parameter2fv.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef ofxFilterLibraryExample_Parameter2fv_h
#define ofxFilterLibraryExample_Parameter2fv_h

#include "AbstractParameterV.h"

class Parameter2fv : public AbstractParameterV {
public:
	Parameter2fv(string name, float * value, int numValues) : AbstractParameterV(name, value, numValues) {
        _type = FILTER_PARAMETER_2FV;
    }
	virtual ~Parameter2fv() {}
    
};

#endif
