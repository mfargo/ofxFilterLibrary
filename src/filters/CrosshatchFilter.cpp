//
//  CrosshatchFilter.cpp
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/11/25.
//
//

#include "CrosshatchFilter.h"

CrosshatchFilter::CrosshatchFilter(float width, float height, float crosshatchSpacing, float lineWidth) : AbstractFilter(width, height) {
    if (crosshatchSpacing<1.f/getWidth()) crosshatchSpacing = 1.f/getWidth();
    _addParameter(new ParameterF("crosshatchSpacing", crosshatchSpacing));
    _addParameter(new ParameterF("lineWidth", lineWidth));
    _setupShader();
}
CrosshatchFilter::~CrosshatchFilter() {
    
}

string CrosshatchFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       
                       uniform sampler2D inputImageTexture;
                       
                       uniform float crosshatchSpacing;
                       uniform float lineWidth;
                       
                       const vec3 W = vec3(0.2125, 0.7154, 0.0721);
                       
                       void main() {
                           vec2 textureCoordinate = gl_TexCoord[0].xy;
                           float luminance = dot(texture2D(inputImageTexture, textureCoordinate).rgb, W);

                           vec4 colorToDisplay = vec4(1.0, 1.0, 1.0, 1.0); // use sample color?
                           if (luminance < 1.00)
                           {
                               if (mod(textureCoordinate.x + textureCoordinate.y, crosshatchSpacing) <= lineWidth)
                               {
                                   colorToDisplay = vec4(0.0, 0.0, 0.0, 1.0);
                               }
                           }
                           if (luminance < 0.75)
                           {
                               if (mod(textureCoordinate.x - textureCoordinate.y, crosshatchSpacing) <= lineWidth)
                               {
                                   colorToDisplay = vec4(0.0, 0.0, 0.0, 1.0);
                               }
                           }
                           if (luminance < 0.50)
                           {
                               if (mod(textureCoordinate.x + textureCoordinate.y - (crosshatchSpacing / 2.0), crosshatchSpacing) <= lineWidth)
                               {
                                   colorToDisplay = vec4(0.0, 0.0, 0.0, 1.0);
                               }
                           }
                           if (luminance < 0.3)
                           {
                               if (mod(textureCoordinate.x - textureCoordinate.y - (crosshatchSpacing / 2.0), crosshatchSpacing) <= lineWidth)
                               {
                                   colorToDisplay = vec4(0.0, 0.0, 0.0, 1.0);
                               }
                           }
                           
                           gl_FragColor = colorToDisplay;
                       }
                       );
}