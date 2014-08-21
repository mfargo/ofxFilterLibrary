//
//  Parameter3fv.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef ofxFilterLibraryExample_Parameter3fv_h
#define ofxFilterLibraryExample_Parameter3fv_h

#include "ParameterV.h"

class Parameter3fv : public ParameterV {
public:
	Parameter3fv(string name, float * value, int numValues) : ParameterV(name, value, numValues) {
        _type = FILTER_PARAMETER_3FV;
    }
    Parameter3fv(string name, vector<ofVec3f> value) : ParameterV(name, NULL, value.size()*3) {
        _type = FILTER_PARAMETER_3FV;
        float * v = new float[value.size()*3];
        for (int i = 0; i<value.size(); i++) {
            v[i*3] = value[i].x;
            v[i*3+1] = value[i].y;
            v[i*3+2] = value[i].z;
        }
        this->setValue(v);
    }
	virtual ~Parameter3fv() {}
};

#endif
