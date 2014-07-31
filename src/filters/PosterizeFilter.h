//
//  PosterizeFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/29.
//
//

#ifndef __ofxFilterLibraryExample__PosterizeFilter__
#define __ofxFilterLibraryExample__PosterizeFilter__

#include "AbstractFilter.h"

class PosterizeFilter : public AbstractFilter {
public:
	PosterizeFilter(float colorLevels);
	virtual ~PosterizeFilter();

private:
    
    virtual string  _getFragSrc();
};

#endif /* defined(__ofxFilterLibraryExample__PosterizeFilter__) */
