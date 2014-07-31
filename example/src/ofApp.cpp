#include "ofApp.h"

void ofApp::setup(){
    ofDisableArbTex();
    _video.initGrabber(1280, 720);
    _currentFilter = 0;
    
    
    
    _filters.push_back(new DoGFilter(_video.getWidth(), _video.getHeight(), 11, 1.7, 8.5, 0.983, 4, 4));
    _filters.push_back(new KuwaharaFilter());
    _filters.push_back(new SobelEdgeDetectionFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new BilateralFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new SketchFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new DilationFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new PerlinPixellationFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new XYDerivativeFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new ZoomBlurFilter());
    _filters.push_back(new EmbossFilter(_video.getWidth(), _video.getHeight(), 2.f));
    _filters.push_back(new SmoothToonFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new TiltShiftFilter(_video.getTextureReference()));
    _filters.push_back(new VoronoiFilter(_video.getTextureReference()));    
    _filters.push_back(new DoGFilter(_video.getWidth(), _video.getHeight(), 56, 1.36, 0.01, 0.987, 4, 0, ofVec2f(3.3, 0.0)));
    _filters.push_back(new CGAColorspaceFilter());
    _filters.push_back(new ErosionFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new LookupFilter(_video.getWidth(), _video.getHeight(), "img/lookup_amatorka.png"));
    _filters.push_back(new LookupFilter(_video.getWidth(), _video.getHeight(), "img/lookup_miss_etikate.png"));
    _filters.push_back(new LookupFilter(_video.getWidth(), _video.getHeight(), "img/lookup_soft_elegance_1.png"));
    _filters.push_back(new VignetteFilter());
    _filters.push_back(new PosterizeFilter(8));
    _filters.push_back(new LaplacianFilter(_video.getWidth(), _video.getHeight(), ofVec2f(1, 1)));
    _filters.push_back(new PixelateFilter(_video.getWidth(), _video.getHeight()));
    _filters.push_back(new HarrisCornerDetectionFilter(_video.getTextureReference()));
    _filters.push_back(new MotionDetectionFilter(_video.getTextureReference()));
    _filters.push_back(new LowPassFilter(_video.getWidth(), _video.getHeight(), 0.9));
    _filters.push_back(new DisplacementFilter("img/mandel.jpg", _video.getWidth(), _video.getHeight(), 25.f));
    _filters.push_back(new PoissonBlendFilter("img/wes.jpg", _video.getWidth(), _video.getHeight(), 2.0));

    
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
    watercolorChain->addFilter(new PoissonBlendFilter("img/canvas_texture.jpg", _video.getWidth(), _video.getHeight(), 2.0));
    watercolorChain->addFilter(new VignetteFilter());
    _filters.push_back(watercolorChain);
    
        // and here's a random gradient map for posterity
    
    vector<GradientMapColorPoint> colors;
    for (float percent=0.0; percent<=1.0; percent+= 0.1)
        colors.push_back( GradientMapColorPoint(ofRandomuf(),ofRandomuf(),ofRandomuf(),percent) );
    _filters.push_back(new GradientMapFilter(colors));

    
}

void ofApp::update(){
    _video.update();
}

void ofApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofPushMatrix();
    ofScale(-1, 1);
    ofTranslate(-_video.getWidth(), 0);
    _filters[_currentFilter]->begin();
    _video.draw(0,0);
    _filters[_currentFilter]->end();
    ofPopMatrix();
    ofSetColor(255);
    ofDrawBitmapString( _filters[_currentFilter]->getName() + " Filter\n(press SPACE to change filters)", ofPoint(40, 20));
}

void ofApp::keyPressed(int key){
    if (key==' ') {
        _currentFilter ++;
        if (_currentFilter>=_filters.size()) _currentFilter = 0;
    }
    else if (key=='f') ofToggleFullscreen();
}
