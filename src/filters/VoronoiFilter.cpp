//
//  VoronoiFilter.cpp
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#include "VoronoiFilter.h"

VoronoiFilter::VoronoiFilter(ofTexture & texture) : AbstractFilter(texture.getWidth(), texture.getHeight()) {
    _name = "Voronoi";
    _texture = texture;
    for (int i=0; i<NUM_POINTS; i++) {
        _vertices[i*2] = ofRandomuf();
        _vertices[i*2+1] = ofRandomuf();
        _colors[i*3] = ofRandomuf();
        _colors[i*3+1] = ofRandomuf();
        _colors[i*3+2] = ofRandomuf();
    }
    _addParameter(new Parameter2fv("verts", _vertices, NUM_POINTS));
    _addParameter(new Parameter3fv("colors", _colors, NUM_POINTS));
    _setupShader();
}
VoronoiFilter::~VoronoiFilter() {}

string VoronoiFilter::_getFragSrc() {
    string fragSrc = GLSL_STRING(120,
         uniform vec2 verts[%%MAX%%];
         uniform vec3 colors[%%MAX%%];
         void main() {
             vec2 coord = gl_TexCoord[0].xy;
             float dist = 1e10;
             vec3 color = vec3(1.0, 0.0, 0.0);
             for (int i = 0; i < %%MAX%%; i++) {
                 float newdist = distance(verts[i], coord);
                 if (newdist < dist) {
                     if (dist - newdist < 0.01) {
                         float d = dist - newdist;
                         color = mix(vec3(0, 0, 0), colors[i], d/0.01);
                     }
                     else {
                         color = colors[i];
                     }
                     dist = newdist;
                 }
             }
             gl_FragColor = vec4(color, 1.0);
         }
    );
    ofStringReplace(fragSrc, "%%MAX%%", ofToString(NUM_POINTS));
    return fragSrc;
}

void VoronoiFilter::begin() {
    
    _texture.readToPixels(_pixels);
    for (int i=0; i<NUM_POINTS; i++) {
        ofColor c = _pixels.getColor(_vertices[i*2]*getWidth(), _vertices[i*2+1]*getHeight());
        _colors[i*3] = c.r/255.;
        _colors[i*3+1] = c.g/255.;
        _colors[i*3+2] = c.b/255.;
    }
    AbstractFilter::begin();
}
