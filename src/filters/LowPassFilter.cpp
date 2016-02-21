//
//  LowPassFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/30.
//
//

#include "LowPassFilter.h"

LowPassFilter::LowPassFilter(float width, float height, float mix) : DissolveBlendFilter(width, height, mix) {
    _name = "Low Pass";
    _buffer.allocate(getWidth(), getHeight());
    setSecondTexture(_buffer.getTexture());
}
LowPassFilter::~LowPassFilter() {}

void LowPassFilter::begin() {
    ofSetColor(255);
    _buffer.begin();
    DissolveBlendFilter::begin();
}

void LowPassFilter::end() {
    DissolveBlendFilter::end();
    _buffer.end();
    ofSetColor(255);
    _buffer.draw(0, 0);
}
