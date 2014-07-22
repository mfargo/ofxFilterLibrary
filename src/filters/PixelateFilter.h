//
//  PixelateFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/24.
//
//

#ifndef __filterSandbox__PixelateFilter__
#define __filterSandbox__PixelateFilter__

#include "AbstractFilter.h"

class PixelateFilter : public AbstractFilter {
public:
	PixelateFilter(float width, float height, float pixelRatio=0.05);
	virtual ~PixelateFilter();

    
protected:
    virtual string  _getFragSrc();
    float           _pixelRatio;
};

#endif /* defined(__filterSandbox__PixelateFilter__) */
