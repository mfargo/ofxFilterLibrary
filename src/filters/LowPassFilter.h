//
//  LowPassFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/30.
//
//

#ifndef __ofxFilterLibraryExample__LowPassFilter__
#define __ofxFilterLibraryExample__LowPassFilter__

#include "DissolveBlendFilter.h"

class LowPassFilter : public DissolveBlendFilter {
public:
	LowPassFilter(float width, float height, float mix);
	virtual ~LowPassFilter();

    virtual void    begin();
    virtual void    end();
    
    ofTexture &     getTextureReference() { return _buffer.getTexture(); }

private:
    
    ofFbo           _buffer;    // buffer result and read back in
};

#endif /* defined(__ofxFilterLibraryExample__LowPassFilter__) */
