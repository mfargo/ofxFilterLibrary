//
//  BoxBlurFilter.h
//  oval_kickstarter
//
//  Created by Matthew Fargo on 2015/03/02.
//
//

#ifndef __oval_kickstarter__BoxBlurFilter__
#define __oval_kickstarter__BoxBlurFilter__

#include "GaussianBlurFilter.h"

class BoxBlurFilter : public GaussianBlurFilter {
public:
    BoxBlurFilter(float width, float height, float blurSize=7.f, float bloom=1.f);
    virtual ~BoxBlurFilter();
    
protected:
    virtual string  _getFragSrc();
    
};

#endif /* defined(__oval_kickstarter__BoxBlurFilter__) */
