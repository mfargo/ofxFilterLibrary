//
//  Abstract3x3ConvolutionFilter.h
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/30.
//
//

#ifndef __ArtNouveau__Abstract3x3ConvolutionFilter__
#define __ArtNouveau__Abstract3x3ConvolutionFilter__

#include "Abstract3x3TextureSamplingFilter.h"

class Abstract3x3ConvolutionFilter : public Abstract3x3TextureSamplingFilter{
public:
	Abstract3x3ConvolutionFilter(float width, float height, ofVec2f texelSpacing);
	virtual ~Abstract3x3ConvolutionFilter();

protected:
    
    virtual string  _getFragSrc();
    
    ofMatrix4x4     _matrix;

};

#endif /* defined(__ArtNouveau__Abstract3x3ConvolutionFilter__) */
