//
//  AbstractTwoPassFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/25.
//
//

#ifndef __filterSandbox__AbstractTwoPassFilter__
#define __filterSandbox__AbstractTwoPassFilter__

#include "AbstractFilter.h"

class AbstractTwoPassFilter : public AbstractFilter {
public:
	AbstractTwoPassFilter(float width, float height, ofVec2f texelSpacing);
	virtual ~AbstractTwoPassFilter();

    ofTexture &     getTextureReference() { return _pong.getTextureReference(); }    
    virtual void    setWidth(float width);
    virtual void    setHeight(float height);

    virtual void    begin();
    virtual void    end();
    
    
protected:
    void        _allocateFBOs();

    ofFbo       _ping;
    ofFbo       _pong;
    ofVec2f     _texelSpacing;

private:
};

#endif /* defined(__filterSandbox__AbstractTwoPassFilter__) */
