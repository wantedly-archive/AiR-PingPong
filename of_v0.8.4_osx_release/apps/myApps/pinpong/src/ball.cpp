//
//  ball.cpp
//  pinpong
//
//  Created by 安田裕介 on 2015/06/20.
//
//

#include "ball.h"
#include "ofMain.h"


Ball::Ball(ofPoint position): position(position) {
    
}

void Ball::draw() {
    ofSetColor(244, 103, 0);
    ofFill();
    ofCircle(position.x, position.y, 10);
    ofSetColor(ofColor::white);
}

void Ball::draw(const ofMatrix4x4& mat) {
    ofSetColor(244, 103, 0);
    ofFill();
    ofVec3f p = mat.preMult(ofVec3f(position.x, position.y, 0));
    ofCircle(p.x, p.y, 10);
    ofSetColor(ofColor::white);
}

void Ball::move(int t) {
    position.x = 1/2 * acceleration.x * t * t + velocity.x * t;
    position.y = 1/2 * acceleration.y * t * t + velocity.y * t;
}
