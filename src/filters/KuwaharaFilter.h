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

    virtual void    onKeyPressed(int key);
    virtual string  getInstructions() { return "Up and Down change radius ("+ofToString(_radius)+")"; }
    
protected:
    int             _radius;
    virtual void    _setup();
};


#endif /* defined(__filterSandbox__KuwaharaFilter__) */
