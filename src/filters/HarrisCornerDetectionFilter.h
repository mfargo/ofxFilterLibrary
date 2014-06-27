//
//  HarrisCornerDetectionFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef __ofxFilterLibraryExample__HarrisCornerDetectionFilter__
#define __ofxFilterLibraryExample__HarrisCornerDetectionFilter__

#include "ThresholdedNonMaximumSuppressionFilter.h"
#include "CornerDetectionFilter.h"
#include "GaussianBlurFilter.h"
#include "GrayscaleFilter.h"
#include "XYDerivativeFilter.h"
#include "ColorPackingFilter.h"
#include "FilterChain.h"

class HarrisCornerDetectionFilter : public FilterChain {
public:
	HarrisCornerDetectionFilter(ofTexture & texture, float sensitivity=0.1f, float threshold=0.2, float blur=2.f);
	virtual ~HarrisCornerDetectionFilter();

    virtual void    end();

private:
    
    ofPixels                                    _filteredPixels;
    ofTexture                                   _texture;
};

#endif /* defined(__ofxFilterLibraryExample__HarrisCornerDetectionFilter__) */
