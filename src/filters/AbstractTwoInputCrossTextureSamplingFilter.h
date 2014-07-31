//
//  AbstractTwoInputCrossTextureSamplingFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/30.
//
//

#ifndef __ofxFilterLibraryExample__AbstractTwoInputCrossTextureSamplingFilter__
#define __ofxFilterLibraryExample__AbstractTwoInputCrossTextureSamplingFilter__

#include "AbstractTwoInputFilter.h"

class AbstractTwoInputCrossTextureSamplingFilter : public AbstractTwoInputFilter {
public:
	AbstractTwoInputCrossTextureSamplingFilter(float width, float height, ofVec2f texelSpacing);
	virtual ~AbstractTwoInputCrossTextureSamplingFilter();

protected:
    virtual string  _getVertSrc();

    ofVec2f         _texelSpacing;

};

#endif /* defined(__ofxFilterLibraryExample__AbstractTwoInputCrossTextureSamplingFilter__) */
