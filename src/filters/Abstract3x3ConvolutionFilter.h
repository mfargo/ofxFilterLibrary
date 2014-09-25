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
	Abstract3x3ConvolutionFilter(float width, float height, ofVec2f texelSpacing=ofVec2f(1,1));
	virtual ~Abstract3x3ConvolutionFilter();

    void            setMatrix(float a=0.0, float b=0.0, float c=0.0, float d=0.0, float e=0.0, float f=0.0, float g=0.0, float h=0.0, float i=0.0);
    
protected:
    virtual string  _getFragSrc();
    
    ofMatrix4x4     _matrix;

};

#endif /* defined(__ArtNouveau__Abstract3x3ConvolutionFilter__) */
