//
//  FilterChain.h
//  GlassTextureTest
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef __GlassTextureTest__FilterChain__
#define __GlassTextureTest__FilterChain__

#include "AbstractPingPongRenderer.h"
#include "AbstractFilter.h"

class FilterChain : public AbstractFilter, public AbstractPingPongRenderer {
public:
	FilterChain(float width, float height, string name="Chain");
	virtual ~FilterChain();
    
    virtual void    begin();
    virtual void    end();

    void            addFilter(AbstractFilter * filter) { _filters.push_back(filter); }

protected:
    
    vector<AbstractFilter *>    _filters;
};

#endif /* defined(__GlassTextureTest__FilterChain__) */
