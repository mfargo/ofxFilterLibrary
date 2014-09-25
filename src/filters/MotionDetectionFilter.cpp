//
//  MotionDetectionFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/30.
//
//

#include "MotionDetectionFilter.h"

MotionDetectionFilter::MotionDetectionFilter(ofTexture & texture, float intensity, bool showImage) : AbstractTwoInputFilter(texture.getWidth(), texture.getHeight()) {
    _name = "Motion Detection";
    _texture = texture;
    _lowPassFilter = new LowPassFilter(getWidth(), getHeight(), 0.6);
    setSecondTexture(_lowPassFilter->getTextureReference());
    _addParameter(new ParameterF("intensity", intensity));
    _addParameter(new ParameterF("showImage", (float)showImage));
    _setupShader();
}
MotionDetectionFilter::~MotionDetectionFilter() {}


void MotionDetectionFilter::begin() {
    _lowPassFilter->begin();
    _texture.draw(0, 0);
    _lowPassFilter->end();
    AbstractFilter::begin();
}

void MotionDetectionFilter::end() {
    AbstractFilter::end();
}


string MotionDetectionFilter::_getFragSrc() {
    return GLSL_STRING(120,
        varying vec2 textureCoordinate;
        
        uniform sampler2D inputImageTexture;
        uniform sampler2D inputImageTexture2;
        
        uniform float intensity;
        uniform float showImage;
        
        void main()
        {
            vec3 currentImageColor = texture2D(inputImageTexture, textureCoordinate).rgb;
            vec3 lowPassImageColor = texture2D(inputImageTexture2, textureCoordinate).rgb;
            
            float colorDistance = distance(currentImageColor, lowPassImageColor); // * 0.57735
            float movementThreshold = step(0.2, colorDistance);
            
            if (showImage>0.5)
                gl_FragColor = movementThreshold * vec4(textureCoordinate.x, textureCoordinate.y, 1.0, 1.0);
            else
                gl_FragColor = vec4(movementThreshold, movementThreshold, movementThreshold, 1.0);
            //gl_FragColor = vec4(movementThreshold, movementThreshold, movementThreshold, 1.0);
        }
    );
}