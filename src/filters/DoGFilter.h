//
//  DoGFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/24.
//
//
//  This is a Difference of Gassian filter based on the one available
//  in the OpenCV library, which is awesome but too slow to run in real
//  time. Moving it into a series of shaders remedies this.

#ifndef __DoGFilter__
#define __DoGFilter__

#include "DirectionalDoGFilter.h"
#include "FlowDoGFilter.h"
#include "FilterChain.h"
#include "EdgeTangentFilter.h"
#include "EdgeTangentSmoothingFilter.h"

class DoGFilter : public AbstractFilter {
public:
	DoGFilter(float width, float height, float black, float sigma, float sigma3, float tau, int halfWidth, int smoothPasses=2, float pencil = 0.f);
	virtual ~DoGFilter();

    virtual void    begin();
    virtual void    end();

    void            setBlack(float black);
    void            setTau(float tau);
    void            setSigma(float sigma);
    void            setSigma3(float sigma3);
    void            setHalfWidth(int halfWidth);
    void            setPencil(float pencil);
    
private:
    
    
    virtual string  _getFragSrc();
    float           _pencil;
    
    FilterChain *           _edgeTangentFilters;
    DirectionalDoGFilter *  _directionalDoGFilter;
    FlowDoGFilter *         _flowDoGFilter;
    ofFbo                   _imageFbo, _edgeTangentFbo, _directionalFbo;

};

#endif /* defined(__DoGFilter__) */
