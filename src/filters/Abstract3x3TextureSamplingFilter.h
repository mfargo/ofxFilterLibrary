//
//  Abstract3x3TextureSamplingFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef __ofxFilterLibraryExample__Abstract3x3TextureSamplingFilter__
#define __ofxFilterLibraryExample__Abstract3x3TextureSamplingFilter__

#include "AbstractFilter.h"

class Abstract3x3TextureSamplingFilter : public AbstractFilter {
public:
	Abstract3x3TextureSamplingFilter(float width, float height, ofVec2f texelSpacing);
	virtual ~Abstract3x3TextureSamplingFilter();

protected:
    virtual string  _getVertSrc();

    ofVec2f         _texelSpacing;

};

#endif /* defined(__ofxFilterLibraryExample__Abstract3x3TextureSamplingFilter__) */
