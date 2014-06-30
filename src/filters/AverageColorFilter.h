//
//  AverageColorFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/30.
//
//

#ifndef __ofxFilterLibraryExample__AverageColorFilter__
#define __ofxFilterLibraryExample__AverageColorFilter__

#include "AbstractFilter.h"

class AverageColorFilter : public AbstractFilter {
public:
	AverageColorFilter(ofTexture & texture, float percentReduction=0.1);
	virtual ~AverageColorFilter();

    
    virtual void    begin();
    virtual void    end();
    
    ofColor         getAverageColor() { return _averageColor; }
    
protected:
    
    ofTexture       _texture;
    ofFbo           _sampleFbo;
    ofPixels        _pixels;
    ofFloatColor    _averageColor;
    
    virtual string  _getFragSrc();
    virtual string  _getVertSrc();

};

#endif /* defined(__ofxFilterLibraryExample__AverageColorFilter__) */
