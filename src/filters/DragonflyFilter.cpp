//
//  VoronoiFilter.cpp
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/23.
//
//

#include "VoronoiFilter.h"

VoronoiFilter::VoronoiFilter(ofTexture & texture, int numPasses) : AbstractFilter(texture.getWidth(), texture.getHeight()) {
    _name = "Voronoi";
    _texture = texture;
    _pixels.allocate(getWidth(), getHeight(), 3);
    _numPasses = numPasses;
    _setup();
    _ping.allocate(getWidth(), getHeight());
    _pong.allocate(getWidth(), getHeight());    
    
        // prolly move this to the begin function before the iterative part
    _mesh.setMode(OF_PRIMITIVE_POINTS);
    for (int i=0; i<240; i++) {
        ofVec2f v = ofVec2f(ofRandom(getWidth()), ofRandom(getHeight()));
        _mesh.addVertex(v);
        _mesh.addTexCoord(_texture.getCoordFromPoint(v.x, v.y) );
        _mesh.addColor(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
    }
    _addParameter(new Parameter2f("size", ofVec2f(getWidth(), getHeight())));
    _addParameter(new ParameterF("sampleStep", 0.5f));

}
VoronoiFilter::~VoronoiFilter() {}

void VoronoiFilter::_setup() {
    string vertSrc = GLSL_STRING(120,
         uniform float sampleStep;
         
         varying vec2 textureCoordinate;
         varying vec2 leftTextureCoordinate;
         varying vec2 rightTextureCoordinate;
         
         varying vec2 topTextureCoordinate;
         varying vec2 topLeftTextureCoordinate;
         varying vec2 topRightTextureCoordinate;
         
         varying vec2 bottomTextureCoordinate;
         varying vec2 bottomLeftTextureCoordinate;
         varying vec2 bottomRightTextureCoordinate;
         
         void main() {
             gl_TexCoord[0] = gl_MultiTexCoord0;
             gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
             
             vec2 widthStep = vec2(sampleStep, 0.0);
             vec2 heightStep = vec2(0.0, sampleStep);
             vec2 widthHeightStep = vec2(sampleStep);
             vec2 widthNegativeHeightStep = vec2(sampleStep, -sampleStep);
             
             textureCoordinate = gl_TexCoord[0].xy;
             leftTextureCoordinate = textureCoordinate.xy - widthStep;
             rightTextureCoordinate = textureCoordinate.xy + widthStep;
             
             topTextureCoordinate = textureCoordinate.xy - heightStep;
             topLeftTextureCoordinate = textureCoordinate.xy - widthHeightStep;
             topRightTextureCoordinate = textureCoordinate.xy + widthNegativeHeightStep;
             
             bottomTextureCoordinate = textureCoordinate.xy + heightStep;
             bottomLeftTextureCoordinate = textureCoordinate.xy - widthNegativeHeightStep;
             bottomRightTextureCoordinate = textureCoordinate.xy + widthHeightStep;
         }
    );
    
    string fragSrc = GLSL_STRING(120,
         varying vec2 textureCoordinate;
         varying vec2 leftTextureCoordinate;
         varying vec2 rightTextureCoordinate;
         
         varying vec2 topTextureCoordinate;
         varying vec2 topLeftTextureCoordinate;
         varying vec2 topRightTextureCoordinate;
         
         varying vec2 bottomTextureCoordinate;
         varying vec2 bottomLeftTextureCoordinate;
         varying vec2 bottomRightTextureCoordinate;
         
         uniform sampler2D inputImageTexture;
         uniform vec2 size;
         
         vec2 getCoordFromColor(vec4 color) {
            float z = color.z * 256.0;
            float yoff = floor(z / 8.0);
            float xoff = mod(z, 8.0);
            float x = color.x*256.0 + xoff*256.0;
            float y = color.y*256.0 + yoff*256.0;
            return vec2(x,y) / size;
         }
                                 
         void main(void) {
             
             vec2 sub;
             vec4 dst;
             vec4 local = texture2D(inputImageTexture, textureCoordinate);
             vec4 sam;
             float l;
             float smallestDist;
             if(local.a == 0.0){
                 
                 smallestDist = dot(1.0,1.0);
             }else{
                 sub = getCoordFromColor(local)-textureCoordinate;
                 smallestDist = dot(sub,sub);
             }
             dst = local;
             
             
             sam = texture2D(inputImageTexture, topRightTextureCoordinate);
             if(sam.a == 1.0){
                 sub = (getCoordFromColor(sam)-textureCoordinate);
                 l = dot(sub,sub);
                 if(l < smallestDist){
                     smallestDist = l;
                     dst = sam;
                 }
             }
             
             sam = texture2D(inputImageTexture, topTextureCoordinate);
             if(sam.a == 1.0){
                 sub = (getCoordFromColor(sam)-textureCoordinate);
                 l = dot(sub,sub);
                 if(l < smallestDist){
                     smallestDist = l;
                     dst = sam;
                 }
             }
             
             sam = texture2D(inputImageTexture, topLeftTextureCoordinate);
             if(sam.a == 1.0){
                 sub = (getCoordFromColor(sam)-textureCoordinate);
                 l = dot(sub,sub);
                 if(l < smallestDist){
                     smallestDist = l;
                     dst = sam;
                 }
             }
             
             sam = texture2D(inputImageTexture, bottomRightTextureCoordinate);
             if(sam.a == 1.0){
                 sub = (getCoordFromColor(sam)-textureCoordinate);
                 l = dot(sub,sub);
                 if(l < smallestDist){
                     smallestDist = l;
                     dst = sam;
                 }
             }
             
             sam = texture2D(inputImageTexture, bottomTextureCoordinate);
             if(sam.a == 1.0){
                 sub = (getCoordFromColor(sam)-textureCoordinate);
                 l = dot(sub,sub);
                 if(l < smallestDist){
                     smallestDist = l;
                     dst = sam;
                 }
             }
             
             sam = texture2D(inputImageTexture, bottomLeftTextureCoordinate);
             if(sam.a == 1.0){
                 sub = (getCoordFromColor(sam)-textureCoordinate);
                 l = dot(sub,sub);
                 if(l < smallestDist){
                     smallestDist = l;
                     dst = sam;
                 }
             }
             
             sam = texture2D(inputImageTexture, leftTextureCoordinate);
             if(sam.a == 1.0){
                 sub = (getCoordFromColor(sam)-textureCoordinate);
                 l = dot(sub,sub);
                 if(l < smallestDist){
                     smallestDist = l;
                     dst = sam;
                 }
             }
             
             sam = texture2D(inputImageTexture, rightTextureCoordinate);
             if(sam.a == 1.0){
                 sub = (getCoordFromColor(sam)-textureCoordinate);
                 l = dot(sub,sub);
                 if(l < smallestDist){
                     smallestDist = l;
                     dst = sam;
                 }
             }
             gl_FragColor = dst;
         }
    );
    _shader.setupShaderFromSource(GL_VERTEX_SHADER, vertSrc);
    _shader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragSrc);
    _shader.linkProgram();
}

void VoronoiFilter::begin() {
        /// this will be used to color my verts
    
    //_texture.readToPixels(_pixels);
    //for (int i=0; i<_mesh.getNumVertices(); i++)
        //_mesh.getColors()[i].set(ofFloatColor(1., 1., 1., 1.));
        //_mesh.getColors()[i].set(_pixels.getColor(_mesh.getVertex(i).x, _mesh.getVertex(i).y));
    
    updateParameter("sampleStep", 0.5);
    _shader.begin();
    _updateParameters(&_shader);
    _ping.begin();
    //_texture.bind();
    ofClear(0,0,0,0);
    _mesh.draw();
    //_texture.unbind();
    _ping.end();
    for (int i=1; i<=_numPasses; i++) {
        _shader.begin();
        float step = pow(2.0, _numPasses - i) / pow(2.0, _numPasses);
        updateParameter("sampleStep", step);
        _updateParameters(&_shader);
        if (i%2==1) {
            _pong.begin();
            _ping.draw(0,0);
            _pong.end();
        }
        else {
            _ping.begin();
            _pong.draw(0,0);
            _ping.end();
        }
        _shader.end();
    }
}

void VoronoiFilter::end() {
        //テクスチャーの描写を素通りして
    _pong.draw(0, 0);
}
