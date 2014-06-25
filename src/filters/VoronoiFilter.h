//
//  VoronoiFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#ifndef __filterSandbox__VoronoiFilter__
#define __filterSandbox__VoronoiFilter__

#include "AbstractFilter.h"

class VoronoiFilter : public AbstractFilter {
public:
	VoronoiFilter(ofTexture & texture, int numPasses=5);
	virtual ~VoronoiFilter();

    virtual void    begin();
    virtual void    end();
    
protected:
    virtual void    _setup();
    int             _nextPowerOfTwo(ofVec2f v);
    
    int             _numPasses;
    ofTexture       _texture;
    ofPixels        _pixels;
    ofFbo           _ping;
    ofFbo           _pong;
    ofMesh          _mesh;
};

#endif /* defined(__filterSandbox__VoronoiFilter__) */
