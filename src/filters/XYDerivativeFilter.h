//
//  XYDerivativeFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef __ofxFilterLibraryExample__XYDerivativeFilter__
#define __ofxFilterLibraryExample__XYDerivativeFilter__

#include "SobelEdgeDetectionFilter.h"

class XYDerivativeFilter : public SobelEdgeDetectionFilter {
public:
	XYDerivativeFilter(float width, float height, float edgeStrength=1.f);
	virtual ~XYDerivativeFilter();

    
protected:
    virtual string  _getFragSrc();
};

#endif /* defined(__ofxFilterLibraryExample__XYDerivativeFilter__) */
