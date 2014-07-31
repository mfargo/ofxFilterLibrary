//
//  SaturationFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/27.
//
//

#ifndef __SaturationFilter__
#define __SaturationFilter__

#include "AbstractFilter.h"

class SaturationFilter : public AbstractFilter {
public:
	SaturationFilter(float saturation);
	virtual ~SaturationFilter();

    void    setSaturation(float saturation);
    
protected:
    
    virtual string  _getFragSrc();
};

#endif /* defined(__SaturationFilter__) */
