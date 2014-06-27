//
//  HarrisCornerDetectionFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef __ofxFilterLibraryExample__HarrisCornerDetectionFilter__
#define __ofxFilterLibraryExample__HarrisCornerDetectionFilter__

#include "ThresholdedNonMaximumSuppressionFilter.h"
#include "GaussianBlurFilter.h"
#include "GrayscaleFilter.h"
#include "XYDerivativeFilter.h"
#include "ColorPackingFilter.h"

class HarrisCornerDetectionFilter : public AbstractFilter, public AbstractPingPongRenderer {
public:
	HarrisCornerDetectionFilter(ofTexture & texture, float sensitivity=0.1f, float threshold=0.2, float blur=2.f);
	virtual ~HarrisCornerDetectionFilter();

    virtual void    begin();
    virtual void    end();


protected:
    virtual string  _getFragSrc();

    float           _threshold, _blur, _sensitivity;
    
private:
    ThresholdedNonMaximumSuppressionFilter *    _suppresionFilter;
    GaussianBlurFilter *                        _blurFilter;
    XYDerivativeFilter *                        _derivativeFilter;
    ColorPackingFilter *                        _colorPackingFilter;
    
    ofPixels                                    _filteredPixels;
    ofTexture                                   _texture;
};

#endif /* defined(__ofxFilterLibraryExample__HarrisCornerDetectionFilter__) */
