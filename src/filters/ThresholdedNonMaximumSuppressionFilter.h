//
//  ThresholdedNonMaximumSuppressionFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef __ofxFilterLibraryExample__ThresholdedNonMaximumSuppressionFilter__
#define __ofxFilterLibraryExample__ThresholdedNonMaximumSuppressionFilter__

#include "Abstract3x3TextureSamplingFilter.h"

class ThresholdedNonMaximumSuppressionFilter : public Abstract3x3TextureSamplingFilter {
public:
	ThresholdedNonMaximumSuppressionFilter(float width, float height, bool usesPackedColorSpace=false, float texelSpacing=1.f);
	virtual ~ThresholdedNonMaximumSuppressionFilter();

protected:
    virtual string  _getFragSrc();
    
private:
    bool        _usesPackedColorSpace;
    
};

#endif /* defined(__ofxFilterLibraryExample__ThresholdedNonMaximumSuppressionFilter__) */
