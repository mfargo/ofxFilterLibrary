//
//  CornerDetectionFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef __ofxFilterLibraryExample__CornerDetectionFilter__
#define __ofxFilterLibraryExample__CornerDetectionFilter__

#include "AbstractFilter.h"

class CornerDetectionFilter : public AbstractFilter {
public:
	CornerDetectionFilter(float width, float height, float sensitivity=0.1f);
	virtual ~CornerDetectionFilter();

protected:
    virtual string  _getFragSrc();
};

#endif /* defined(__ofxFilterLibraryExample__CornerDetectionFilter__) */
