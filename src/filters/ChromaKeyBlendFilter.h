//
//  ChromaKeyBlendFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2015/07/03.
//
//

#ifndef __ofxFilterLibraryExample__ChromaKeyBlendFilter__
#define __ofxFilterLibraryExample__ChromaKeyBlendFilter__

#include "AbstractTwoInputFilter.h"

class ChromaKeyBlendFilter : public AbstractTwoInputFilter {
public:
    ChromaKeyBlendFilter(ofVec3f keyColor=ofVec3f(0.f, 1.f, 0.f), float thresholdSensitivity=0.3, float smoothing=0.1);
    virtual ~ChromaKeyBlendFilter();
    
protected:
    virtual string  _getFragSrc();

    
};

#endif /* defined(__ofxFilterLibraryExample__ChromaKeyBlendFilter__) */
