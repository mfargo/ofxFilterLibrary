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
