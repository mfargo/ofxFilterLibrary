//
//  SketchDoGFilter.cpp
//  nigaoe
//
//  Created by Matthew Fargo on 2014/09/17.
//
//

#include "SketchDoGFilter.h"

SketchDoGFilter::SketchDoGFilter(float width, float height, float black, float sigma, float sigma3, float tau, int halfWidth, int smoothPasses, ofVec2f sketchiness) : DoGFilter(width, height, black, sigma, sigma3, tau, halfWidth, smoothPasses, sketchiness) {
    for (int i=1; i<_edgeTangentFilters->getNumFilters(); i++) {
        ((EdgeTangentSmoothingFilter*)_edgeTangentFilters->getFilterAt(i))->setOffset(ofVec2f(1, 1));
    }
}
SketchDoGFilter::~SketchDoGFilter() {}


