//
//  ColorBurnFilter.h
//  ImageComparisonShader
//
//  Created by Matthew Fargo on 2014/08/10.
//
//

#ifndef __ImageComparisonShader__ColorBurnFilter__
#define __ImageComparisonShader__ColorBurnFilter__

#include "AbstractTwoInputFilter.h"

class ColorBurnFilter : public AbstractTwoInputFilter {
public:
	ColorBurnFilter();
	virtual ~ColorBurnFilter();

protected:
    virtual string  _getFragSrc();

    
};

#endif /* defined(__ImageComparisonShader__ColorBurnFilter__) */
