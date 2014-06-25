//
//  AbstractTwoPassFilter.cpp
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/25.
//
//

#include "AbstractTwoPassFilter.h"

AbstractTwoPassFilter::AbstractTwoPassFilter(float width, float height, ofVec2f texelSpacing) : AbstractFilter(width, height) {
    _texelSpacing = texelSpacing;
    _addParameter(new ParameterF("texelWidthOffset", _texelSpacing.x/getWidth()));
    _addParameter(new ParameterF("texelHeightOffset", _texelSpacing.y/getHeight()));
    _allocateFBOs();
}
AbstractTwoPassFilter::~AbstractTwoPassFilter() {}

void AbstractTwoPassFilter::_allocateFBOs() {
    if (_ping.getWidth() != getWidth() || _ping.getHeight() != getHeight()) {
        _ping.allocate(getWidth(), getHeight());
        _pong.allocate(getWidth(), getHeight());
    }
}

void AbstractTwoPassFilter::begin() {
    _ping.begin();
    _shader.begin();
    updateParameter("texelWidthOffset", _texelSpacing.x/getWidth());
    updateParameter("texelHeightOffset", 0.f);
    _updateParameters(&_shader);
    
}

void AbstractTwoPassFilter::end() {
    _shader.end();
    _ping.end();
    
    _pong.begin();
    _shader.begin();
    updateParameter("texelWidthOffset", 0.f);
    updateParameter("texelHeightOffset", _texelSpacing.y/getHeight());
    _updateParameters(&_shader);
    _ping.draw(0, 0);
    _shader.end();
    _pong.end();
    _pong.draw(0, 0);
}

void AbstractTwoPassFilter::setWidth(float width) {
    AbstractFilter::setWidth(width);
    _allocateFBOs();
}

void AbstractTwoPassFilter::setHeight(float height) {
    AbstractFilter::setHeight(height);
    _allocateFBOs();
}
