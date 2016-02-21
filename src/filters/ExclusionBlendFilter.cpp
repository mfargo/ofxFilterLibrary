//
//  ExclusionBlendFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/11/20.
//
//

#include "ExclusionBlendFilter.h"

ExclusionBlendFilter::ExclusionBlendFilter(string blendImageUri) {
    _name = "Exclusion Blend";
    ofImage blendImage = ofImage(blendImageUri);
    setSecondTexture(blendImage.getTexture());
    _setupShader();
}
ExclusionBlendFilter::ExclusionBlendFilter(ofTexture & texture) {
    _name = "Exclusion Blend";
    setSecondTexture(texture);
    _setupShader();
}
ExclusionBlendFilter::ExclusionBlendFilter() {
    _name = "Exclusion Blend";
    _setupShader();
}
ExclusionBlendFilter::~ExclusionBlendFilter() {}

string ExclusionBlendFilter::_getFragSrc() {
     return GLSL_STRING(120,
         varying vec2 textureCoordinate;
         
         uniform sampler2D inputImageTexture;
         uniform sampler2D inputImageTexture2;
         
         void main()
         {
             vec4 base = texture2D(inputImageTexture, textureCoordinate);
             vec4 overlay = texture2D(inputImageTexture2, textureCoordinate);
             
             //     Dca = (Sca.Da + Dca.Sa - 2.Sca.Dca) + Sca.(1 - Da) + Dca.(1 - Sa)
             
             gl_FragColor = vec4((overlay.rgb * base.a + base.rgb * overlay.a - 2.0 * overlay.rgb * base.rgb) + overlay.rgb * (1.0 - base.a) + base.rgb * (1.0 - overlay.a), base.a);
         }
     );
}