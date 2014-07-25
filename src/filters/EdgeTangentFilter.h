//
//  EdgeTangentFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/22.
//
//

#ifndef __EdgeTangentFilter__
#define __EdgeTangentFilter__

#include "Abstract3x3TextureSamplingFilter.h"

class EdgeTangentFilter : public Abstract3x3TextureSamplingFilter {
public:
	EdgeTangentFilter(float width, float height);
	virtual ~EdgeTangentFilter();

    
private:
    virtual string  _getFragSrc();
    
    
};

#endif /* defined(__EdgeTangentFilter__) */
