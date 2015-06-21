//
//  ball.cpp
//  pinpong
//
//  Created by 安田裕介 on 2015/06/20.
//
//

#include "ball.h"
#include "ofApp.h"

Ball::Ball(const Table& table):
    table(table),
    position(position),
    velocity(ofVec3f(10, 1, 0)) {
}

void Ball::draw() {
    ofSetColor(244, 103, 0);
    ofFill();
    ofCircle(position.x, position.y, BALL_R);
    ofSetColor(ofColor::white);
}

void Ball::move(int t) {
    position.x += t * velocity.x;
    position.y += t * velocity.y;

    if (table.AIR_HOCKEY_MODE) {
        if (position.y > table.TABLE_HEIGHT && velocity.y > 0) {
            velocity.y *= -1;
        }

        if (position.y < 0 && velocity.y < 0) {
            velocity.y *= -1;
        }
    }
}
