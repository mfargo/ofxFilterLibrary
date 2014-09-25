//
//  AlphaBlendFilter.h
//  ofxFilterLibrary
//
//  Created by Matthew Fargo on 2014/09/24.
//
//

#ifndef __ShowWindowCentral__AlphaBlendFilter__
#define __ShowWindowCentral__AlphaBlendFilter__

#include "AbstractTwoInputFilter.h"

class AlphaBlendFilter : public AbstractTwoInputFilter {
public:
    AlphaBlendFilter(float mixturePercent=1.f);
    virtual ~AlphaBlendFilter();
    
protected:
    virtual string  _getFragSrc();
    
};

#endif /* defined(__ShowWindowCentral__AlphaBlendFilter__) */
