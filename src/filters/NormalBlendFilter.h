//
//  NormalBlendFilter.h
//  ImageComparisonShader
//
//  Created by Matthew Fargo on 2014/08/11.
//
//

#ifndef __ImageComparisonShader__NormalBlendFilter__
#define __ImageComparisonShader__NormalBlendFilter__

#include "AbstractTwoInputFilter.h"

class NormalBlendFilter : public AbstractTwoInputFilter {
public:
	NormalBlendFilter();
	virtual ~NormalBlendFilter();

protected:
    virtual string  _getFragSrc();

};

#endif /* defined(__ImageComparisonShader__NormalBlendFilter__) */
