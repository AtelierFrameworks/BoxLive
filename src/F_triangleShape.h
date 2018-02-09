//
//  F_triangleShape.h
//  avoidingObject
//
//  Created by AtelierFrameworks on 2017/12/14.
//
//

#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"

static int hexColors[4] = {0x31988A, 0xFDB978, 0xFF8340, 0xE8491B};

class F_triangleShape {
    
public:
    
    
    ofImage    *    texturePtr;
    ofMesh          mesh;
    ofColor         color;
    ofxBox2dPolygon polyShape;
    
    F_triangleShape() {
        texturePtr = NULL;
    }
    void setup(ofxBox2d &world, float cx, float cy, float r) {
        
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        int   nPts  = 4;
        float scale = r / (float)texturePtr->getWidth();
        
        for (int i = 0; i < nPts; i++) {
            float n = ofMap(i, 0, nPts - 1, 0.0, TWO_PI);
            float x = cos(n);
            float y = sin(n);
            polyShape.addVertex(ofPoint(cx + (x * r), cy + (y * r)));
            mesh.addTexCoord(ofPoint(0, 0));
            mesh.addTexCoord(ofPoint(x * scale, y * scale));
        }
        
        polyShape.setPhysics(0.3, 0.5, 0.1);
        polyShape.create(world.getWorld());
        
        
    }
    
    
    void setTexture(ofImage * texture) {
        texturePtr = texture;
        texturePtr->getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
        texturePtr->getTextureReference().setTextureWrap(GL_REPEAT, GL_REPEAT);
    }
    void draw() {
        
        mesh.clearVertices();
        vector<ofPoint> &pts = polyShape.getPoints();
        
        ofPoint center       = polyShape.getCentroid2D();
        for (int i = 0; i < pts.size(); i++) {
            mesh.addVertex(center);
            mesh.addVertex(pts[i]);
        }
        mesh.addVertex(center);
        mesh.addVertex(pts.front());
        
        ofSetColor(color);
        texturePtr->bind();
        mesh.draw();
        texturePtr->unbind();
        
    }
    
};
