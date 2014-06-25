//
//  EmbossFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/24.
//
//

#ifndef __filterSandbox__EmbossFilter__
#define __filterSandbox__EmbossFilter__

#include "AbstractFilter.h"

class EmbossFilter : public AbstractFilter {
public:
	EmbossFilter(float width, float height, float intensity=1.f);
	virtual ~EmbossFilter();

    float           getIntensity() { return _intensity; }
    void            setIntensity(float intensity);
  
    virtual void    onKeyPressed(int key);
    
    virtual string  getInstructions() { return "Up and Down change intensity: " + ofToString(_intensity); }

protected:
    virtual void    _setup();
    ofMatrix4x4     _matrix;
    float           _intensity;
};

#endif /* defined(__filterSandbox__EmbossFilter__) */
