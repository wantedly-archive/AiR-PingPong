//
//  table.cpp
//  pinpong
//
//  Created by Naoyoshi Aikawa on 6/21/15.
//
//

#include "table.h"

#include "ofColor.h"
#include "ofApp.h"

Table::Table(): ball(Ball(ofPoint(0, 0, 0))) {

}

void Table::draw() {
    // draw self
    ofSetColor(ofColor::white);
    ofFill();
    ofRect(0, 0, TABLE_WIDTH, TABLE_HEIGHT);

    // draw objects
    ball.draw();
}

void Table::update() {
    ball.move(1);
}

void Table::swingRacket(int direction) {
    if (ball.velocity.x * direction < 0) {
        ball.velocity.x *= -1;
    }
}