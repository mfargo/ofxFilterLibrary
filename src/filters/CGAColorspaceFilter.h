//
//  CGAColorspaceFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#ifndef __filterSandbox__CGAColorspaceFilter__
#define __filterSandbox__CGAColorspaceFilter__

#include "AbstractFilter.h"

class CGAColorspaceFilter : public AbstractFilter {
public:
	CGAColorspaceFilter();
	virtual ~CGAColorspaceFilter();

protected:
    virtual string  _getFragSrc();

};

#endif /* defined(__filterSandbox__CGAColorspaceFilter__) */
