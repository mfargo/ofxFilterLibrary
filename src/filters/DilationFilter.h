//
//  DilationFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/17.
//
//

#ifndef __ofxFilterLibraryExample__DilationFilter__
#define __ofxFilterLibraryExample__DilationFilter__

#include "Abstract3x3PingPongFilter.h"

class DilationFilter : public Abstract3x3PingPongFilter {
public:
	DilationFilter(float width, float height, int dilationRadius=2);
	virtual ~DilationFilter();

    int             getDilationRadius() { return _texelSpacing.x; }
    void            setDilationRadius(int dilationRadius);
    
protected:
    virtual string  _getFragSrc();
    virtual string  _getVertSrc();
    
private:
    string          _getFragSrcForRadius(int radius);
    string          _getVertSrcForRadius(int radius);
};

#endif /* defined(__ofxFilterLibraryExample__DilationFilter__) */
