//
//  SmoothToonFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/31.
//
//

#include "SmoothToonFilter.h"

SmoothToonFilter::SmoothToonFilter(float width, float height, float blur, float threshold, float quantization) : FilterChain(width, height, "Smooth Toon") {
    addFilter(new GaussianBlurFilter(width, height, blur));
    addFilter(new ToonFilter(width, height, threshold, quantization));
}
SmoothToonFilter::~SmoothToonFilter() {}



