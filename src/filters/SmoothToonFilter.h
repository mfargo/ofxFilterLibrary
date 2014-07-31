//
//  SmoothToonFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/31.
//
//

#ifndef __ofxFilterLibraryExample__SmoothToonFilter__
#define __ofxFilterLibraryExample__SmoothToonFilter__

#include "FilterChain.h"
#include "GaussianBlurFilter.h"
#include "ToonFilter.h"

class SmoothToonFilter : public FilterChain {
public:
	SmoothToonFilter(float width, float height, float blur=3.0, float threshold=0.2f, float quantization=10.f);
	virtual ~SmoothToonFilter();

private:
};

#endif /* defined(__ofxFilterLibraryExample__SmoothToonFilter__) */
