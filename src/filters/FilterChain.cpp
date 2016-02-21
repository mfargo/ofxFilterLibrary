//
//  FilterChain.cpp
//  GlassTextureTest
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#include "FilterChain.h"

FilterChain::FilterChain(float width, float height, string name, int internalFormat) : AbstractFilter(width, height), AbstractPingPongRenderer(width, height, internalFormat) {
    _name = name;
        // don't set up shader, cuz there ain't neccesarily one
}
FilterChain::~FilterChain() {
    while (_filters.size()>0)
        _filters.erase(_filters.begin());
}


void FilterChain::begin() {
    _ping.begin();
    ofClear(0, 0, 0, 0);
    if (_filters.size()>0) _filters[0]->begin();
}

void FilterChain::end() {
    if (_filters.size()>0) _filters[0]->end();
    _ping.end();
    
    
    int filterIndex = 1;
    while (filterIndex<_filters.size()) {
        bool isPong = (filterIndex%2==1);
        if (isPong) _pong.begin();
        else _ping.begin();
        ofClear(0, 0, 0, 0);
        
        _filters[filterIndex]->begin();
        if (isPong) _ping.draw(0,0);
        else _pong.draw(0,0);
        _filters[filterIndex]->end();
        
        if (isPong) _pong.end();
        else _ping.end();
        filterIndex++;
    }
    if (filterIndex%2==1) _ping.draw(0,0);
    else _pong.draw(0,0);
}

ofTexture & FilterChain::getTextureReference() {
    if (_filters.size()%2==1 || _filters.size()==0) return _ping.getTexture();
    else return _pong.getTexture();
}



void FilterChain::readToPixels(ofPixels & pixels) {
    if (_filters.size()%2==1) _ping.readToPixels(pixels);
    else _pong.readToPixels(pixels);
}