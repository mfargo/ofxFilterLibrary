//
//  MultiplyBlendFilter.h
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/09.
//
//

#ifndef __MultiplyBlendFilter__
#define __MultiplyBlendFilter__

#include "AbstractTwoInputFilter.h"

class MultiplyBlendFilter : public AbstractTwoInputFilter {
public:
	MultiplyBlendFilter();
	virtual ~MultiplyBlendFilter();

protected:
    virtual string  _getFragSrc();

};

#endif /* defined(__MultiplyBlendFilter__) */
