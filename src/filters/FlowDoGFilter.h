//
//  FlowDoGFilter.h
//
//  Created by Matthew Fargo on 2014/07/25.
//
//

#ifndef __FlowDoGFilter__
#define __FlowDoGFilter__

#include "AbstractDoGFilter.h"

class FlowDoGFilter : public AbstractDoGFilter {
public:
	FlowDoGFilter(float width, float height, float sigma);
	virtual ~FlowDoGFilter();

private:
    virtual string  _getFragSrc();

};

#endif /* defined(__FlowDoGFilter__) */
