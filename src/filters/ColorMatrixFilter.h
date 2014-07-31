//
//  ColorMatrixFilter.h
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/27.
//
//

#ifndef __ArtNouveau__ColorMatrixFilter__
#define __ArtNouveau__ColorMatrixFilter__

#include "AbstractFilter.h"

class ColorMatrixFilter : AbstractFilter {
public:
	ColorMatrixFilter();
	virtual ~ColorMatrixFilter();

protected:
    virtual string  _getFragSrc();

    
};

#endif /* defined(__ArtNouveau__ColorMatrixFilter__) */
