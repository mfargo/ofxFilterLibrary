//
//  PerlinNoiseFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/24.
//
//

#ifndef __filterSandbox__PerlinNoiseFilter__
#define __filterSandbox__PerlinNoiseFilter__

#include "AbstractFilter.h"

class PerlinNoiseFilter : public AbstractFilter {
public:
	PerlinNoiseFilter(float scale = 8.f);
	virtual ~PerlinNoiseFilter();

    
protected:
    virtual string  _getFragSrc();
    float           _scale;
};

#endif /* defined(__filterSandbox__PerlinNoiseFilter__) */
