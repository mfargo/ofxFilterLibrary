//
//  KuwaharaFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#ifndef __filterSandbox__KuwaharaFilter__
#define __filterSandbox__KuwaharaFilter__

#include "AbstractFilter.h"

class KuwaharaFilter : public AbstractFilter {
public:
	KuwaharaFilter(int radius=7);
	virtual ~KuwaharaFilter();
    
protected:
    virtual string  _getFragSrc();
    int             _radius;
};


#endif /* defined(__filterSandbox__KuwaharaFilter__) */
