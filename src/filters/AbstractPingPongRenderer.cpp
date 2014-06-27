//
//  AbstractPingPongRenderer.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#include "AbstractPingPongRenderer.h"

AbstractPingPongRenderer::AbstractPingPongRenderer(float width, float height) {
    _ping.allocate(width, height);
    _pong.allocate(width, height);

}
AbstractPingPongRenderer::~AbstractPingPongRenderer() {}


void AbstractPingPongRenderer::ping() {
    _ping.begin();
    ofClear(0, 0, 0, 0);
}

void AbstractPingPongRenderer::pong() {
    _ping.end();
    _pong.begin();
    _ping.draw(0, 0);
    _pong.end();
}

