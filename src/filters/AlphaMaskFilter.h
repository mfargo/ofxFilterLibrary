//
//  AlphaMaskFilter.h
//  ofxFilterLibrary
//
//  Created by Matthew Fargo on 2014/09/24.
//
//

#ifndef __ShowWindowCentral__AlphaMaskFilter__
#define __ShowWindowCentral__AlphaMaskFilter__

#include "AbstractTwoInputFilter.h"

class AlphaMaskFilter : public AbstractTwoInputFilter {
public:
    AlphaMaskFilter();
    virtual ~AlphaMaskFilter();
    
protected:
    virtual string _getFragSrc();
    
};

#endif /* defined(__ShowWindowCentral__AlphaMaskFilter__) */
