//
//  HalftoneFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/11/24.
//
//

#ifndef __ofxFilterLibraryExample__HalftoneFilter__
#define __ofxFilterLibraryExample__HalftoneFilter__

#include "PixelateFilter.h"

class HalftoneFilter : public PixelateFilter {
public:
    HalftoneFilter(float width, float height, float pixelRatio=0.05);
    virtual ~HalftoneFilter();
protected:
    
    string _getFragSrc();
};

#endif /* defined(__ofxFilterLibraryExample__HalftoneFilter__) */
