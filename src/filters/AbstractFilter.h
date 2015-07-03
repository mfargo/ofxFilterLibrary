//
//  AbstractFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#ifndef __filterSandbox__AbstractFilter__
#define __filterSandbox__AbstractFilter__

#define GLSL_STRING(version, shader)  "#version " #version "\n" #shader

#include "ParametricObject.h"


class AbstractFilter : public ParametricObject {
public:
	AbstractFilter(float width=0, float height=0);
	virtual ~AbstractFilter();
    
    virtual void    begin();
    virtual void    end();
    
    float           getWidth() { return _width; }
    float           getHeight() { return _height; }
    virtual void    setWidth(float width) { _width = width; }
    virtual void    setHeight(float height) { _height = height; }
    ofShader &      getShader() { return _shader; }
    
protected:
    virtual void    _setupShader();
    virtual string  _getFragSrc();  // override these
    virtual string  _getVertSrc();  // with yr shader src

    ofShader        _shader;
    
private:
    float           _width;
    float           _height;
    
    
};

#endif /* defined(__filterSandbox__AbstractFilter__) */
