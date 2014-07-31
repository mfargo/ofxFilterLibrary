//
//  HueFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/07/27.
//
//

#ifndef __HueFilter__
#define __HueFilter__

#include "AbstractFilter.h"

class HueFilter : public AbstractFilter {
public:
	HueFilter(float hue=90.0);
	virtual ~HueFilter();

    void    setHue(float hue);
    
protected:
    
    virtual string  _getFragSrc();

};

#endif /* defined(__HueFilter__) */
