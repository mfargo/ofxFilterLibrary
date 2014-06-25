//
//  ErosionFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/25.
//
//

#ifndef __filterSandbox__ErosionFilter__
#define __filterSandbox__ErosionFilter__

#include "AbstractTwoPassFilter.h"

class ErosionFilter : public AbstractTwoPassFilter {
public:
	ErosionFilter(float width, float height, int erosionRadius=2);
	virtual ~ErosionFilter();

    virtual void    onKeyPressed(int key);
    
    virtual string  getInstructions() { return "Up and Down change erosion radius: " + ofToString(getErosionRadius()); }

    
    int             getErosionRadius() { return _texelSpacing.x; }
    void            setErosionRadius(int erosionRadius);
    
protected:
    virtual void    _setup();
    
private:
    string          _getFragSrcForRadius(int radius);
    string          _getVertSrcForRadius(int radius);
};

#endif /* defined(__filterSandbox__ErosionFilter__) */
