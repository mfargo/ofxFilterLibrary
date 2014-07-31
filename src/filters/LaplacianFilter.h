//
//  LaplacianFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/30.
//
//

#ifndef __ofxFilterLibraryExample__LaplacianFilter__
#define __ofxFilterLibraryExample__LaplacianFilter__

#include "Abstract3x3ConvolutionFilter.h"

class LaplacianFilter : public Abstract3x3ConvolutionFilter {
public:
	LaplacianFilter(float width, float height, ofVec2f texelSpacing);
	virtual ~LaplacianFilter();

protected:
    
    virtual string  _getFragSrc();
};

#endif /* defined(__ofxFilterLibraryExample__LaplacianFilter__) */
