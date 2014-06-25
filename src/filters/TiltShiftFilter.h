//
//  TileShiftFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#ifndef __filterSandbox__TileShiftFilter__
#define __filterSandbox__TileShiftFilter__

#include "GaussianBlurFilter.h"

class TiltShiftFilter : public AbstractFilter {
public:
	TiltShiftFilter(ofTexture & texture, float topFocus=0.4f, float bottomFocus=0.6f, float falloff=0.2f);
	virtual ~TiltShiftFilter();

    virtual void    begin();
    virtual void    onKeyPressed(int key);

    virtual void    describeParameters();
    GaussianBlurFilter *getGaussianBlurFilter() { return _gaussianBlurFilter; }
    virtual string  getInstructions() { return _gaussianBlurFilter->getInstructions()+"\n< and > change focus falloff"; }

protected:
    virtual void        _setup();
    
private:
    
    GaussianBlurFilter *_gaussianBlurFilter;
    ofTexture           _texture;
    
};

#endif /* defined(__filterSandbox__TileShiftFilter__) */
