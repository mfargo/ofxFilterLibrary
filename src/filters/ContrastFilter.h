//
//  ContrastFilter.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/07/27.
//
//

#ifndef __ContrastFilter__
#define __ContrastFilter__

#include "AbstractFilter.h"

class ContrastFilter : public AbstractFilter {
public:
	ContrastFilter(float contrast=1.0);
	virtual ~ContrastFilter();

    void    setContrast(float contrast);

protected:
    virtual string  _getFragSrc();
    

};

#endif /* defined(__ContrastFilter__) */
