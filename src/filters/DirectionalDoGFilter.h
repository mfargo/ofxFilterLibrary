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
	DirectionalDoGFilter(float width, float height, float sigma, float tau);
	virtual ~DirectionalDoGFilter();

    
protected:
    
    virtual string  _getFragSrc();
    float           _sigma;
};

#endif /* defined(__DirectionalDoGFilter__) */
