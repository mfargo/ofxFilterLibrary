//
//  AbstractPingPongRenderer.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef __ofxFilterLibraryExample__AbstractPingPongRenderer__
#define __ofxFilterLibraryExample__AbstractPingPongRenderer__

#include "ofMain.h"

class AbstractPingPongRenderer {
public:
	AbstractPingPongRenderer(float width, float height, int internalFormat=GL_RGBA);
	virtual ~AbstractPingPongRenderer();

    void            ping();
    void            pong();
    
    virtual ofTexture &     getTexture() { return _pong.getTexture(); }
    
    ofFbo &     getPing() { return _ping; }
    ofFbo &     getPong() { return _pong; }

protected:
    
    ofFbo       _ping;
    ofFbo       _pong;
};

#endif /* defined(__ofxFilterLibraryExample__AbstractPingPongRenderer__) */
