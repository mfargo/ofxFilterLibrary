//
//  MultiplyBlendFilter.h
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/09.
//
//

#ifndef __ArtNouveau__MultiplyBlendFilter__
#define __ArtNouveau__MultiplyBlendFilter__

#include "AbstractTwoInputFilter.h"

class MultiplyBlendFilter : public AbstractTwoInputFilter {
public:
	MultiplyBlendFilter(float width, float height);
	virtual ~MultiplyBlendFilter();

private:
    virtual string  _getFragSrc();

};

#endif /* defined(__ArtNouveau__MultiplyBlendFilter__) */
