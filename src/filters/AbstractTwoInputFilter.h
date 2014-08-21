//
//  AbstractTwoInputFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/30.
//
//

#ifndef __ofxFilterLibraryExample__AbstractTwoInputFilter__
#define __ofxFilterLibraryExample__AbstractTwoInputFilter__

#include "AbstractFilter.h"

class AbstractTwoInputFilter : public AbstractFilter {
public:
    AbstractTwoInputFilter();
	AbstractTwoInputFilter(string secondTextureUrl);
	AbstractTwoInputFilter(float width, float height);
	virtual ~AbstractTwoInputFilter();
    
    void            setSecondTexture(ofTexture & texture);
    
    
protected:
    
    virtual string  _getVertSrc();

    ofTexture       _secondTexture;
    
};

#endif /* defined(__ofxFilterLibraryExample__AbstractTwoInputFilter__) */
