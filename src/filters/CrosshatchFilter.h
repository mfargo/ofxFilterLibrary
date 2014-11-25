//
//  CrosshatchFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/11/25.
//
//

#ifndef __ofxFilterLibraryExample__CrosshatchFilter__
#define __ofxFilterLibraryExample__CrosshatchFilter__

#include "AbstractFilter.h"

class CrosshatchFilter : public AbstractFilter {
public:
    CrosshatchFilter(float width, float height, float crosshatchSpacing=0.013, float lineWidth=0.003);
    virtual ~CrosshatchFilter();
    
protected:
    virtual string  _getFragSrc();
};

#endif /* defined(__ofxFilterLibraryExample__CrosshatchFilter__) */
