#include "ofApp.h"

void ofApp::setup(){
    ofDisableArbTex();
    _video.initGrabber(640, 480);
    _currentFilter = 0;

        // here's how you add individual filters
    
    _filters.push_back(new KuwaharaFilter());
    _filters.push_back(new PerlinPixellationFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new XYDerivativeFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new ZoomBlurFilter());
    _filters.push_back(new EmbossFilter(_video.getWidth(), _video.getHeight(), 2.f));
    _filters.push_back(new BilateralFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new SobelEdgeDetectionFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new TiltShiftFilter(_video.getTextureReference()));
    _filters.push_back(new VoronoiFilter(_video.getTextureReference()));    
    _filters.push_back(new CGAColorspaceFilter());
    _filters.push_back(new ErosionFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new LookupFilter(_video.getWidth(), _video.getHeight(), "img/lookup_amatorka.png"));
    _filters.push_back(new LookupFilter(_video.getWidth(), _video.getHeight(), "img/lookup_miss_etikate.png"));
    _filters.push_back(new LookupFilter(_video.getWidth(), _video.getHeight(), "img/lookup_soft_elegance_1.png"));
    _filters.push_back(new VignetteFilter());
    _filters.push_back(new ToonFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new PixelateFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new HarrisCornerDetectionFilter(_video.getTextureReference()));

        // and here's how you might daisy-chain a bunch of filters
    
    FilterChain * foggyTexturedGlassChain = new FilterChain(_video.getWidth(), _video.getHeight(), "Weird Glass");
    foggyTexturedGlassChain->addFilter(new PerlinPixellationFilter(_video.getWidth(), _video.getHeight(), 13.f));
    foggyTexturedGlassChain->addFilter(new EmbossFilter(_video.getWidth(), _video.getHeight(), 0.5));
    foggyTexturedGlassChain->addFilter(new GaussianBlurFilter(_video.getWidth(), _video.getHeight(), 3.f));
    _filters.push_back(foggyTexturedGlassChain);
    
        // here's another unimaginative filter chain
    
    FilterChain * watercolorChain = new FilterChain(_video.getWidth(), _video.getHeight(), "Monet");
    watercolorChain->addFilter(new KuwaharaFilter(9));
    watercolorChain->addFilter(new LookupFilter(_video.getWidth(), _video.getHeight(), "img/lookup_miss_etikate.png"));
    watercolorChain->addFilter(new BilateralFilter(_video.getWidth(), _video.getHeight()));
    watercolorChain->addFilter(new VignetteFilter());
    _filters.push_back(watercolorChain);
    
    
}

void ofApp::update(){
    _video.update();
}

void ofApp::draw(){
    ofSetColor(255);
    ofPushMatrix();
    ofScale(2, 2);
    _filters[_currentFilter]->begin();
    _video.draw(0,0);
    _filters[_currentFilter]->end();
    ofPopMatrix();
    ofSetColor(255);
    ofDrawBitmapString( _filters[_currentFilter]->getName() + " Filter\n"+ _filters[_currentFilter]->getInstructions(), ofPoint(40, 20));
}

void ofApp::keyPressed(int key){
    if (key==' ') {
        _currentFilter ++;
        if (_currentFilter>=_filters.size()) _currentFilter = 0;
    }
    else _filters[_currentFilter]->onKeyPressed(key);
}
