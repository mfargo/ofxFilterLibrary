//
//  ErosionFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/25.
//
//

#ifndef __filterSandbox__ErosionFilter__
#define __filterSandbox__ErosionFilter__

#include "Abstract3x3PingPongFilter.h"

class ErosionFilter : public Abstract3x3PingPongFilter {
public:
	ErosionFilter(float width, float height, int erosionRadius=2);
	virtual ~ErosionFilter();

    
    int             getErosionRadius() { return _texelSpacing.x; }
    void            setErosionRadius(int erosionRadius);
    
protected:
    virtual string  _getFragSrc();
    virtual string  _getVertSrc();
    
private:
    string          _getFragSrcForRadius(int radius);
    string          _getVertSrcForRadius(int radius);
};

#endif /* defined(__filterSandbox__ErosionFilter__) */
