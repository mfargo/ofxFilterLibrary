//
//  AbstractDoGFilter.h
//
//  Created by Matthew Fargo on 2014/07/25.
//
//

#ifndef __AbstractDoGFilter__
#define __AbstractDoGFilter__

#include "AbstractTwoInputFilter.h"

class AbstractDoGFilter : public AbstractTwoInputFilter {
public:
	AbstractDoGFilter(float width, float height, float sigma);
	virtual ~AbstractDoGFilter();

    ParameterV *    makeGaussianVector(double sigma, string parameterName);
    
    void            setSigma(float sigma);

protected:
    
    float           _sigma;
};

#endif /* defined(__AbstractDoGFilter__) */
