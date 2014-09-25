//
//  EmbossFilter.cpp
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/24.
//
//

#include "EmbossFilter.h"

EmbossFilter::EmbossFilter(float width, float height, float intensity) : Abstract3x3ConvolutionFilter(width, height, ofVec2f(1, 1)) {
    _name = "Emboss";
    setIntensity(intensity);
    _setupShader();
}
EmbossFilter::~EmbossFilter() {}


void EmbossFilter::setIntensity(float intensity) {
    _intensity = intensity;
        // really just need a Matrix3x3, but ofShader doesn't support that so whatevs
    setMatrix(_intensity * (-2.0), -_intensity, 0,
              -_intensity, 1.0, _intensity,
              0.0f, _intensity, _intensity*2.f);
}
