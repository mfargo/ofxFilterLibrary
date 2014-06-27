//
//  GrayscaleFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef __ofxFilterLibraryExample__GrayscaleFilter__
#define __ofxFilterLibraryExample__GrayscaleFilter__

#include "AbstractFilter.h"

class GrayscaleFilter : public AbstractFilter {
public:
	GrayscaleFilter();
	virtual ~GrayscaleFilter();

private:
    virtual string  _getFragSrc();
};

#endif /* defined(__ofxFilterLibraryExample__GrayscaleFilter__) */
