//
//  BilateralFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/24.
//
//

#ifndef __filterSandbox__BilateralFilter__
#define __filterSandbox__BilateralFilter__

#include "Abstract3x3PingPongFilter.h"

class BilateralFilter : public Abstract3x3PingPongFilter {
public:
	BilateralFilter(float width, float height, float blurOffset=4.f, float normalization=6.f);
	virtual ~BilateralFilter();

    
    float           getBlurOffset() { return _texelSpacing.x; }
    void            setBlurOffset(float blurOffset) { _texelSpacing = ofVec2f(blurOffset, blurOffset); }
    
protected:
    virtual string  _getFragSrc();
    virtual string  _getVertSrc();
    
    float           _normalization;

};

#endif /* defined(__filterSandbox__BilateralFilter__) */
