//
//  DirectionalDoGFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/22.
//
//

#ifndef __DirectionalDoGFilter__
#define __DirectionalDoGFilter__

#include "AbstractDoGFilter.h"

class DirectionalDoGFilter : public AbstractDoGFilter {
public:
	DirectionalDoGFilter(float width, float height, float sigma, float tau, float sketchinessX=1.0, float sketchinessY=1.0);
	virtual ~DirectionalDoGFilter();

    
protected:
    
    virtual string  _getFragSrc();
    float           _sigma;
};

#endif /* defined(__DirectionalDoGFilter__) */
