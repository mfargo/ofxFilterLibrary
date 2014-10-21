//
//  AdditiveBlendFilter.h
//  ofxFilterLibrary
//
//  Created by Matthew Fargo on 2014/09/24.
//
//

#ifndef __ShowWindowCentral__AdditiveBlendFilter__
#define __ShowWindowCentral__AdditiveBlendFilter__

#include "AbstractTwoInputFilter.h"

class AdditiveBlendFilter : public AbstractTwoInputFilter {
public:
    AdditiveBlendFilter();
    virtual ~AdditiveBlendFilter();
    
protected:
    virtual string  _getFragSrc();
    
};

#endif /* defined(__ShowWindowCentral__AdditiveBlendFilter__) */
