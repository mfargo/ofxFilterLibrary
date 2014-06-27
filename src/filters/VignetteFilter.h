//
//  VignetteFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#ifndef __filterSandbox__VignetteFilter__
#define __filterSandbox__VignetteFilter__

#include "AbstractFilter.h"

class VignetteFilter : public AbstractFilter {
public:
	VignetteFilter();
	virtual ~VignetteFilter();

protected:
    virtual string  _getFragSrc();
};

#endif /* defined(__filterSandbox__VignetteFilter__) */
