#include "ofApp.h"

void ofApp::setup(){
    ofDisableArbTex();
    _video.initGrabber(1280, 720);
    _filters = new FilterChain(_video.getWidth(), _video.getHeight(), "Suisaiga");
    _filters->addFilter(new KuwaharaFilter(6)); //9
    _filters->addFilter(new BilateralFilter(_video.getWidth(), _video.getHeight(), 6.f, 4.f));
    
    _alphaFilter = new LineDrawingAlphaFilter();
    _dogFilter = new DoGFilter(_video.getWidth(), _video.getHeight(), 11, 1.7, 8.5, 0.973, 4);
    setMode(DOG_MODE_ANIME);
    _dogFbo.allocate(_video.getWidth(), _video.getHeight());
}

void ofApp::update(){
    _video.update();

}

void ofApp::draw(){
    ofBackground(255);
    ofPushMatrix();
    ofScale(-1, 1);
    ofTranslate(-ofGetWidth(), 0);
    ofEnableAlphaBlending();
    
    ofSetColor(255);
    
    if (_mode==DOG_MODE_ANIME) {
        _filters->begin();
        _video.draw(0,0);
        _filters->end();
    }
    
    _dogFbo.begin();
    //ofClear(255);
    _dogFilter->begin();
    _video.draw(0, 0);
    _dogFilter->end();
    _dogFbo.end();

    _alphaFilter->begin();
    _dogFbo.draw(0, 0);
    _alphaFilter->end();

    ofPopMatrix();
}

void ofApp::setMode(DogMode mode) {
    _mode = mode;
    switch (mode) {
        case DOG_MODE_ANIME:
            _dogFilter->setBlack(11);
            _dogFilter->setSigma(1.7);
            _dogFilter->setSigma3(8.5);
            _dogFilter->setTau(0.973);
            _dogFilter->setHalfWidth(4);
            _dogFilter->setSketchiness(ofVec2f(1.0, 1.0));

            break;
        case DOG_MODE_TAKE_ON_ME:
            
            _dogFilter->setBlack(56);
            _dogFilter->setSigma(1.36);
            _dogFilter->setSigma3(0.01);
            _dogFilter->setTau(0.897);
            _dogFilter->setHalfWidth(4);
            _dogFilter->setSketchiness(ofVec2f(5.3, 0.0));
                                 
            break;
            
    }
}

void ofApp::keyPressed(int key){
    if (key==' ') {
        if (_mode==DOG_MODE_ANIME) setMode(DOG_MODE_TAKE_ON_ME);
        else setMode(DOG_MODE_ANIME);
    }
    else if (key=='f') ofToggleFullscreen();
}
