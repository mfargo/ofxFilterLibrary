//
//  LineDrawingAlphaFilter.h
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/07.
//
//

#ifndef __LineDrawingAlphaFilter__
#define __LineDrawingAlphaFilter__

// custom filter to drop white pix



#include "AbstractFilter.h"

class LineDrawingAlphaFilter : public AbstractFilter {
public:
	LineDrawingAlphaFilter();
	virtual ~LineDrawingAlphaFilter();

protected:
    
    virtual string _getFragSrc();
};

#endif /* defined(__LineDrawingAlphaFilter__) */
