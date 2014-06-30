//
//  DissolveBlendFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/30.
//
//

#include "DissolveBlendFilter.h"

DissolveBlendFilter::DissolveBlendFilter(float width, float height, float mix) : AbstractTwoInputFilter(width, height) {
    _name = "Dissolve Blend";
    _addParameter(new ParameterF("mixturePercent", mix));
    setMix(mix);
    _setupShader();
}
DissolveBlendFilter::~DissolveBlendFilter() {}



string DissolveBlendFilter::_getFragSrc() {
    return GLSL_STRING(120,
        varying vec2 textureCoordinate;
        uniform sampler2D inputImageTexture;
        uniform sampler2D inputImageTexture2;
        uniform float mixturePercent;
        
        void main()
        {
            
            vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);
            vec4 textureColor2 = texture2D(inputImageTexture2, textureCoordinate);

            vec4 color;
            if (textureCoordinate.x > 0.5) color = textureColor;
            else color = textureColor2;
            //gl_FragColor = color;
            gl_FragColor = mix(textureColor, textureColor2, mixturePercent);
        }
    );
}


void DissolveBlendFilter::setMix(float mix)  {
    _mix = mix;
    updateParameter("mixturePercent", mix);
}