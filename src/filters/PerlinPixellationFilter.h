//
//  PerlinPixellationFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/24.
//
//

#ifndef __filterSandbox__PerlinPixellationFilter__
#define __filterSandbox__PerlinPixellationFilter__

#include "AbstractFilter.h"

class PerlinPixellationFilter : public AbstractFilter {
public:
	PerlinPixellationFilter(float width, float height, float scale = 8.f);
	virtual ~PerlinPixellationFilter();

    virtual void    onKeyPressed(int key);
    virtual string  getInstructions() {
        return "Up and Down change scale: " + ofToString(_scale);
    }
    
protected:
    float           _scale;
    virtual void    _setup();
};

#endif /* defined(__filterSandbox__PerlinPixellationFilter__) */
