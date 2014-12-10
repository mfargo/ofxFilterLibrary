//
//  GammaFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/12/10.
//
//

#ifndef __ofxFilterLibraryExample__GammaFilter__
#define __ofxFilterLibraryExample__GammaFilter__

#include "AbstractFilter.h"

class GammaFilter : public AbstractFilter {
public:
    GammaFilter(float gamma);
    virtual ~GammaFilter();
    
protected:
    virtual string  _getFragSrc();
};

#endif /* defined(__ofxFilterLibraryExample__GammaFilter__) */
