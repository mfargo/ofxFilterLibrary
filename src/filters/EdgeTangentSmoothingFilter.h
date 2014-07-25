//
//  EdgeTangentSmoothingFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/23.
//
//

#ifndef __EdgeTangentSmoothingFilter__
#define __EdgeTangentSmoothingFilter__

#include "Abstract3x3PingPongFilter.h"

class EdgeTangentSmoothingFilter : public AbstractFilter {
public:
	EdgeTangentSmoothingFilter( float width, float height, ofVec2f offset, int halfWidth=4 );
	virtual ~EdgeTangentSmoothingFilter();

    void            setOffset(ofVec2f offset);
    
private:
    virtual string  _getVertSrc();
    virtual string  _getFragSrc();

};

#endif /* defined(__EdgeTangentSmoothingFilter__) */
