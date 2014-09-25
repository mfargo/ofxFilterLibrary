//
//  EmbossFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/24.
//
//

#ifndef __filterSandbox__EmbossFilter__
#define __filterSandbox__EmbossFilter__

#include "Abstract3x3ConvolutionFilter.h"

class EmbossFilter : public Abstract3x3ConvolutionFilter {
public:
	EmbossFilter(float width, float height, float intensity=1.f);
	virtual ~EmbossFilter();

    float           getIntensity() { return _intensity; }
    void            setIntensity(float intensity);
  
protected:
    
    float           _intensity;
};

#endif /* defined(__filterSandbox__EmbossFilter__) */
