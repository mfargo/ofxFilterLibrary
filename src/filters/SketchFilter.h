//
//  SketchFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/03.
//
//

#ifndef __ofxFilterLibraryExample__SketchFilter__
#define __ofxFilterLibraryExample__SketchFilter__

#include "SobelEdgeDetectionFilter.h"

class SketchFilter : public SobelEdgeDetectionFilter {
public:
	SketchFilter(float width, float height, float edgeStrength=1.f);
	virtual ~SketchFilter();

protected:
    virtual string  _getFragSrc();
    
    
};

#endif /* defined(__ofxFilterLibraryExample__SketchFilter__) */
