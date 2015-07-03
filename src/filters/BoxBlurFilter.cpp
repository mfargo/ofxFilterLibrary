//
//  BoxBlurFilter.cpp
//  oval_kickstarter
//
//  Created by Matthew Fargo on 2015/03/02.
//
//

#include "BoxBlurFilter.h"

BoxBlurFilter::BoxBlurFilter(float width, float height, float blurSize, float bloom) :GaussianBlurFilter(width, height, blurSize, bloom) {
    _name = "Box Blur";
    _setupShader();
}
BoxBlurFilter::~BoxBlurFilter() {}

string BoxBlurFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       
                       );
}