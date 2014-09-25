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
	FilterChain(float width, float height, string name="Chain", int internalFormat=GL_RGBA);
	virtual ~FilterChain();
    
    virtual void    begin();
    virtual void    end();

    void            addFilter(AbstractFilter * filter) { _filters.push_back(filter); }
    AbstractFilter *getFilterAt(int index) { return _filters[index]; }
    int             getNumFilters() { return _filters.size(); }

    virtual ofTexture &     getTextureReference();
    virtual void            readToPixels(ofPixels & pixels);
    
protected:
    
    vector<AbstractFilter *>    _filters;
};

#endif /* defined(__GlassTextureTest__FilterChain__) */
