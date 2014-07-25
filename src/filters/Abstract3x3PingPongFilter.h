//
//  Abstract3x3PingPongFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef __ofxFilterLibraryExample__Abstract3x3PingPongFilter__
#define __ofxFilterLibraryExample__Abstract3x3PingPongFilter__

#include "AbstractPingPongRenderer.h"
#include "Abstract3x3TextureSamplingFilter.h"

class Abstract3x3PingPongFilter : public Abstract3x3TextureSamplingFilter, public AbstractPingPongRenderer {
public:
	Abstract3x3PingPongFilter(float width, float height, ofVec2f texelSpacing, int internalFormat=GL_RGBA );
	virtual ~Abstract3x3PingPongFilter();

    virtual void    begin();
    virtual void    end();

protected:
    
};

#endif /* defined(__ofxFilterLibraryExample__Abstract3x3PingPongFilter__) */
