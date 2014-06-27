//
//  ColorPackingFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef __ofxFilterLibraryExample__ColorPackingFilter__
#define __ofxFilterLibraryExample__ColorPackingFilter__

#include "AbstractFilter.h"

class ColorPackingFilter : public AbstractFilter {
public:
	ColorPackingFilter(float width, float height, ofVec2f texelSize);
	virtual ~ColorPackingFilter();

protected:
    virtual string  _getVertSrc();
    virtual string  _getFragSrc();
    
    ofVec2f         _texelSize;
    
};

#endif /* defined(__ofxFilterLibraryExample__ColorPackingFilter__) */
