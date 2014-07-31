//
//  GradientMapFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/30.
//
//

#ifndef __ofxFilterLibraryExample__GradientMapFilter__
#define __ofxFilterLibraryExample__GradientMapFilter__

#include "AbstractFilter.h"

class GradientMapColorPoint {
public:
    GradientMapColorPoint(float red, float green, float blue, float percent){
        r = red;
        g = green;
        b = blue;
        p = percent;
    }
    virtual ~GradientMapColorPoint() {}
    float r, g, b, p;
};

class GradientMapFilter : public AbstractFilter {
public:
	GradientMapFilter(vector<GradientMapColorPoint> colorPoints);
	virtual ~GradientMapFilter();

protected:
    
    virtual string  _getFragSrc();
    
private:


};

#endif /* defined(__ofxFilterLibraryExample__GradientMapFilter__) */
