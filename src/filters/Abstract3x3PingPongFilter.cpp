//
//  Abstract3x3PingPongFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#include "Abstract3x3PingPongFilter.h"

Abstract3x3PingPongFilter::Abstract3x3PingPongFilter(float width, float height, ofVec2f texelSpacing, int internalFormat) : AbstractPingPongRenderer(width, height, internalFormat), Abstract3x3TextureSamplingFilter(width, height, texelSpacing) {
}
Abstract3x3PingPongFilter::~Abstract3x3PingPongFilter() {}



void Abstract3x3PingPongFilter::begin() {
    updateParameter("texelWidthOffset", _texelSpacing.x/getWidth());
    updateParameter("texelHeightOffset", 0.f);
    AbstractFilter::begin();
    ping();
}
void Abstract3x3PingPongFilter::end() {
    updateParameter("texelWidthOffset", 0.f);
    updateParameter("texelHeightOffset", _texelSpacing.y/getHeight());
    _updateParameters(&_shader);
    pong();
    _shader.end();
    _pong.getTexture().draw(0, 0);
}
