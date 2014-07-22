//
//  SobelEdgeDetectionFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#ifndef __filterSandbox__SobelEdgeDetectionFilter__
#define __filterSandbox__SobelEdgeDetectionFilter__

#include "AbstractFilter.h"

class SobelEdgeDetectionFilter : public AbstractFilter {
public:
	SobelEdgeDetectionFilter(float width, float height, float edgeStrength=1.f);
	virtual ~SobelEdgeDetectionFilter();
    
    
protected:
    virtual string  _getFragSrc();
    virtual string  _getVertSrc();
    
    float           _edgeStrength;
};

#endif /* defined(__filterSandbox__SobelEdgeDetectionFilter__) */