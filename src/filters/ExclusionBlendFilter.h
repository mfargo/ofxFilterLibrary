//
//  ExclusionBlendFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/11/20.
//
//

#ifndef __ofxFilterLibraryExample__ExclusionBlendFilter__
#define __ofxFilterLibraryExample__ExclusionBlendFilter__

#include "AbstractTwoInputFilter.h"

class ExclusionBlendFilter : public AbstractTwoInputFilter {
public:
    ExclusionBlendFilter(string blendImageUri);
    ExclusionBlendFilter(ofTexture & texture);
    ExclusionBlendFilter();
    virtual ~ExclusionBlendFilter();
    
protected:
    virtual string  _getFragSrc();
};

#endif /* defined(__ofxFilterLibraryExample__ExclusionBlendFilter__) */
