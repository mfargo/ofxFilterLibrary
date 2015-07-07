//
//  InvertFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2015/07/07.
//
//

#ifndef __ofxFilterLibraryExample__InvertFilter__
#define __ofxFilterLibraryExample__InvertFilter__

#include "AbstractFilter.h"

class InvertFilter : public AbstractFilter {
public:
    InvertFilter();
    virtual ~InvertFilter();
    
protected:
    virtual string  _getFragSrc();
};

#endif /* defined(__ofxFilterLibraryExample__InvertFilter__) */
