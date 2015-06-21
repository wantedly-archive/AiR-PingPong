//
//  ball.h
//  pinpong
//
//  Created by 安田裕介 on 2015/06/20.
//
//

#ifndef pinpong_ball_h
#define pinpong_ball_h

#include "ofxQuadWarp.h"

class Ball {
private:
    ofVec3f velocity;
    ofVec3f acceleration;
    ofPoint position;
    
public:
    Ball(ofPoint position);
    void draw();
    void draw(const ofMatrix4x4& mat);
    void move(int t);
};

#endif
