//
//  DarkenBlendFilter.h
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/27.
//
//

#ifndef __DarkenBlendFilter__
#define __DarkenBlendFilter__

#include "AbstractTwoInputFilter.h"

class DarkenBlendFilter : public AbstractTwoInputFilter {
public:
	DarkenBlendFilter();
	virtual ~DarkenBlendFilter();

protected:
    
    virtual string _getFragSrc();
};

#endif /* defined(__DarkenBlendFilter__) */
