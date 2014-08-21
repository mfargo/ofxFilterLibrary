//
//  ColorBlendFilter.h
//  ImageComparisonShader
//
//  Created by Matthew Fargo on 2014/08/10.
//
//

#ifndef __ImageComparisonShader__ColorBlendFilter__
#define __ImageComparisonShader__ColorBlendFilter__

#include "AbstractTwoInputFilter.h"

class ColorBlendFilter : public AbstractTwoInputFilter {
public:
	ColorBlendFilter();
	virtual ~ColorBlendFilter();

protected:
    virtual string  _getFragSrc();
    
};

#endif /* defined(__ImageComparisonShader__ColorBlendFilter__) */
