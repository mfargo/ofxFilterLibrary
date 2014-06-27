//
//  LookupFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#ifndef __filterSandbox__LookupFilter__
#define __filterSandbox__LookupFilter__

#include "AbstractFilter.h"

class LookupFilter : public AbstractFilter {
public:
	LookupFilter(float width, float height, string lookupImageUrl);
	virtual ~LookupFilter();

    
protected:
    ofTexture       _lookupTexture;
    virtual string  _getFragSrc();
};

#endif /* defined(__filterSandbox__LookupFilter__) */
