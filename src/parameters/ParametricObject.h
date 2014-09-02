//
//  ParametricObject.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/25.
//
//

#ifndef __filterSandbox__ParametricObject__
#define __filterSandbox__ParametricObject__

#include "ParameterV.h"
#include "ParameterF.h"
#include "ParameterI.h"
#include "ParameterT.h"
#include "Parameter2f.h"
#include "Parameter3f.h"
#include "Parameter4f.h"
#include "ParameterMatrix4f.h"
#include "Parameter2fv.h"
#include "Parameter3fv.h"


class ParametricObject {
public:
	ParametricObject();
	virtual ~ParametricObject();

    template<class T>
    void updateParameter(string name, T value) { _parameters[name]->setValue(value); }
    void updateParameter(string name, float value) { ((ParameterF *)_parameters[name])->setValue(value); }
    void updateParameter(string name, int value) { ((ParameterI *)_parameters[name])->setValue(value); }
    void updateParameter(string name, ofVec2f value) { ((Parameter2f *)_parameters[name])->setValue(value); }
    void updateParameter(string name, ofVec3f value) { ((Parameter3f *)_parameters[name])->setValue(value); }
    void updateParameter(string name, ofVec4f value) { ((Parameter4f *)_parameters[name])->setValue(value); }
    void updateParameter(string name, ofMatrix4x4 value) { ((ParameterMatrix4f *)_parameters[name])->setValue(value); }
    void updateParameter(string name, ofTexture value) { ((ParameterT *)_parameters[name])->setValue(value); }
    void updateParameter(string name, float * value) { ((ParameterV *)_parameters[name])->setValue(value); }
    AbstractParameter * getParameter(string name) { return _parameters[name]; }
    
    // utility
    virtual void    describeParameters();
    string          getName() { return _name; }
    
protected:
    string          _name;
    void            _updateParameters(ofShader * shader);
    void            _addParameter(AbstractParameter * parameter);
    void            _clearParameters();
    
private:
    
    map<string, AbstractParameter *> _parameters;
    void            _updateParameter(ofShader * shader, AbstractParameter * parameter);
    string          _getNameForParameterType(OFX_FILTER_PARAMETER_TYPE type);
};

#endif /* defined(__filterSandbox__ParametricObject__) */
