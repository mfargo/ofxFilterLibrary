//
//  ZoomBlurFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/25.
//
//

#ifndef __filterSandbox__ZoomBlurFilter__
#define __filterSandbox__ZoomBlurFilter__

#include "AbstractFilter.h"

class ZoomBlurFilter : public AbstractFilter {
public:
	ZoomBlurFilter(float blurSize=1.f);
	virtual ~ZoomBlurFilter();

    virtual void    begin();
    virtual void    onKeyPressed(int key);
    
    virtual string  getInstructions() { return "Use the mouse to center zoom.\nUp and Down change blur size: " + ofToString(_blurSize); }

protected:
    virtual string  _getFragSrc();
    float           _blurSize;
    
};

#endif /* defined(__filterSandbox__ZoomBlurFilter__) */
