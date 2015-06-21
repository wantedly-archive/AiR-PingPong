//
//  table.cpp
//  pinpong
//
//  Created by Naoyoshi Aikawa on 6/21/15.
//
//

#include "table.h"

Table::Table(): ball(Ball(ofPoint(0, 0, 0))) {

}

void Table::draw(const ofMatrix4x4& mat) {
    glPushMatrix();
    glMultMatrixf(mat.getPtr());

    // draw self
    ofSetColor(ofColor::white);
    ofFill();
    ofRect(0, 0, TABLE_WIDTH, TABLE_HEIGHT);


    // draw objects
    ball.draw();
    
    glPopMatrix();
}

void Table::update() {
    ball.move(1);
}