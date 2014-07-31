//
//  ColorReplacementFilter.h
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/26.
//
//

#ifndef __ArtNouveau__ColorReplacementFilter__
#define __ArtNouveau__ColorReplacementFilter__

#include "AbstractFilter.h"

class ColorReplacementFilter : public AbstractFilter {
public:
	ColorReplacementFilter(vector<ofVec3f> fromColors, vector<ofVec3f>toColors);
	virtual ~ColorReplacementFilter();

protected:
    virtual string  _getFragSrc();
    
};

#endif /* defined(__ArtNouveau__ColorReplacementFilter__) */
