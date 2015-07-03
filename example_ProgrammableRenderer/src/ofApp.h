//
//  ofApp.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/25.
//
//
//  This is an example of how to use all the filters in this library.
//  They should be as easy as coffee filters, but not as easy as
//  cigarette filters.

#pragma once

#include "ofMain.h"
#include "ofxFilterLibrary.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
    
    private:
        int                         _currentFilter;
        vector<AbstractFilter *>    _filters;
        ofVideoGrabber              _video;

};
