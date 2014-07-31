//
//  DisplacementFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/31.
//
//

#ifndef __ofxFilterLibraryExample__DisplacementFilter__
#define __ofxFilterLibraryExample__DisplacementFilter__

#include "AbstractTwoInputCrossTextureSamplingFilter.h"

class DisplacementFilter : public AbstractTwoInputCrossTextureSamplingFilter {
public:
	DisplacementFilter(string imageUri, float width, float height, float strength=10.f);
	DisplacementFilter(float width, float height, float strength=10.f);
	virtual ~DisplacementFilter();

protected:
    
    virtual string  _getVertSrc();
    virtual string  _getFragSrc();
    
};

#endif /* defined(__ofxFilterLibraryExample__DisplacementFilter__) */
