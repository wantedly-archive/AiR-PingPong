//
//  ball.h
//  pinpong
//
//  Created by 安田裕介 on 2015/06/20.
//
//

#ifndef pinpong_ball_h
#define pinpong_ball_h

#include "ofPoint.h"
#include "ofVec3f.h"

class Ball {
public:
    ofVec3f velocity;
    ofVec3f acceleration;
    ofPoint position;

    Ball(ofPoint position);
    void draw();
    void move(int t);
};

#endif
