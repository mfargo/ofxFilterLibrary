//
//  BrightnessFilter.h
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/24.
//
//

#ifndef __ArtNouveau__BrightnessFilter__
#define __ArtNouveau__BrightnessFilter__

#include "AbstractFilter.h"

class BrightnessFilter : public AbstractFilter {
public:
	BrightnessFilter(float brightness);
	virtual ~BrightnessFilter();

    void    setBrightness(float brightness);
    
private:
    
    virtual string  _getFragSrc();
};

#endif /* defined(__ArtNouveau__BrightnessFilter__) */
