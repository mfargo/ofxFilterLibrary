//
//  BloomFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2015/02/27.
//
//

#ifndef __ofxFilterLibraryExample__BloomFilter__
#define __ofxFilterLibraryExample__BloomFilter__

#include "AbstractFilter.h"

class BloomFilter : public AbstractFilter {
public:
    BloomFilter(float width, float height);
    virtual ~BloomFilter();
    
protected:
    virtual string  _getFragSrc();
};

#endif /* defined(__ofxFilterLibraryExample__BloomFilter__) */
