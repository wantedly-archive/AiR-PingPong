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

void Ball::move(int t) {
    position.x += t * velocity.x;
    position.y += t * velocity.y;
}
