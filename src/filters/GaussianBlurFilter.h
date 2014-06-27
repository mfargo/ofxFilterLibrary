//
//  GaussianBlurFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#ifndef __filterSandbox__GaussianBlurFilter__
#define __filterSandbox__GaussianBlurFilter__

#include "Abstract3x3PingPongFilter.h"

class GaussianBlurFilter : public Abstract3x3PingPongFilter {
public:
	GaussianBlurFilter(float width, float height, float blurSize=7.f, float bloom=1.f);
	virtual ~GaussianBlurFilter();

    virtual void    onKeyPressed(int key);
    
    virtual string  getInstructions() { return "Left and Right change blur size: " + ofToString(_blurSize) + "\nUp and Down change bloom: " + ofToString(_bloom); }
    

    
protected:
    virtual string  _getVertSrc();
    virtual string  _getFragSrc();
    float           _blurSize;
    float           _bloom;

};

#endif /* defined(__filterSandbox__GaussianBlurFilter__) */
