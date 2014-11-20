//
//  PoissonBlendFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/30.
//
//

#ifndef __ofxFilterLibraryExample__PoissonBlendFilter__
#define __ofxFilterLibraryExample__PoissonBlendFilter__

#include "AbstractTwoInputCrossTextureSamplingFilter.h"

class PoissonBlendFilter : public AbstractTwoInputCrossTextureSamplingFilter {
public:
	PoissonBlendFilter(string blendImageUri, float width, float height, float mix=0.5, int numIterations=10);
    PoissonBlendFilter(ofTexture & texture, float width, float height, float mix=0.5, int numIterations=10);
	PoissonBlendFilter(float width, float height, float mix=0.5, int numIterations=10);
	virtual ~PoissonBlendFilter();

protected:
    
    virtual string  _getFragSrc();
};

#endif /* defined(__ofxFilterLibraryExample__PoissonBlendFilter__) */
