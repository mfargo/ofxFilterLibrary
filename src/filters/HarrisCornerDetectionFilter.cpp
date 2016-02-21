//
//  HarrisCornerDetectionFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#include "HarrisCornerDetectionFilter.h"

HarrisCornerDetectionFilter::HarrisCornerDetectionFilter(ofTexture & texture, float sensitivity, float threshold, float blur) : FilterChain(texture.getWidth(), texture.getHeight()) {
    _name = "Harris Corner Detection";
    _texture = texture;
    addFilter(new XYDerivativeFilter(getWidth(), getHeight()));
    addFilter(new GaussianBlurFilter(getWidth(), getHeight(), blur));
    addFilter(new CornerDetectionFilter(getWidth(), getHeight(), sensitivity));
    addFilter(new ThresholdedNonMaximumSuppressionFilter(getWidth(), getHeight()));
}
HarrisCornerDetectionFilter::~HarrisCornerDetectionFilter() {}

void HarrisCornerDetectionFilter::end() {
    FilterChain::end();
    _pong.readToPixels(_filteredPixels);
    ofSetColor(255);
    _texture.draw(0, 0);

    ofSetColor(0,255,0);
    for (int y=0; y<_filteredPixels.getHeight(); y++)
        for (int x=0; x<_filteredPixels.getWidth(); x++)
            if (_filteredPixels.getColor(x, y).r==0) {
                ofDrawLine(x, y-2, x, y+2);
                ofDrawLine(x-2, y, x+2, y);
            }

    ofSetColor(255);
}
