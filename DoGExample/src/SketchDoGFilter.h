//
//  SketchDoGFilter.h
//  nigaoe
//
//  Created by Matthew Fargo on 2014/09/17.
//
//

#ifndef __nigaoe__SketchDoGFilter__
#define __nigaoe__SketchDoGFilter__

#include "DoGFilter.h"

class SketchDoGFilter : public DoGFilter {
public:
	SketchDoGFilter(float width, float height, float black, float sigma, float sigma3, float tau, int halfWidth, int smoothPasses=2, ofVec2f sketchiness=ofVec2f(1.0, 1.0));
	virtual ~SketchDoGFilter();

private:
};

#endif /* defined(__nigaoe__SketchDoGFilter__) */
