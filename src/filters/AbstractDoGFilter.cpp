//
//  AbstractDoGFilter.cpp
//
//  Created by Matthew Fargo on 2014/07/25.
//
//

#include "AbstractDoGFilter.h"

inline float gauss(float x, float mean, float sigma) {
	return ( exp( (-(x-mean)*(x-mean)) / (2*sigma*sigma) ) / sqrt(PI * 2.0 * sigma * sigma) );
}

AbstractDoGFilter::AbstractDoGFilter(float width, float height, float sigma) : AbstractTwoInputFilter(width, height) {
    _sigma = sigma;
    _addParameter(new ParameterF("width", getWidth()));
    _addParameter(new ParameterF("height", getHeight()));
    _addParameter(makeGaussianVector(sigma, "gau"));
}
AbstractDoGFilter::~AbstractDoGFilter() {}


ParameterV * AbstractDoGFilter::makeGaussianVector(double sigma, string parameterName) {
    int i = 0;
    float threshold = 0.001;
    while (1) {
        i++;
        if ( gauss((float)i, 0.0, sigma) < threshold) break;
    }
    int gauSize = i+1;
    float * gau = new float[gauSize];
    for (int j=0; j<gauSize; j++) gau[j] = 0.0;
    gau[0] = gauss((float)0.0, 0.0, sigma);
    for (int j=1; j<gauSize; j++) {
        gau[j] = gauss((float)j, 0.0, sigma);
    }
    return new ParameterV(parameterName, &gau[0], gauSize);
}

void AbstractDoGFilter::setSigma(float sigma) {
    if (_sigma != sigma) {
        _sigma = sigma;
        _shader.unload();
        _addParameter(makeGaussianVector(_sigma, "gau"));
        _setupShader();
    }
    
}
