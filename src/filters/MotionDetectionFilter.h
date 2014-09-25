//
//  MotionDetectionFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/30.
//
//

#ifndef __ofxFilterLibraryExample__MotionDetectionFilter__
#define __ofxFilterLibraryExample__MotionDetectionFilter__

#include "LowPassFilter.h"

class MotionDetectionFilter : public AbstractTwoInputFilter {
public:
	MotionDetectionFilter(ofTexture & texture, float intensity=0.5f, bool showImage=true);
	virtual ~MotionDetectionFilter();

    
    virtual void    begin();
    virtual void    end();
    
protected:
    
    virtual string  _getFragSrc();
    
    ofTexture       _texture;
    LowPassFilter * _lowPassFilter;
    
};

#endif /* defined(__ofxFilterLibraryExample__MotionDetectionFilter__) */
