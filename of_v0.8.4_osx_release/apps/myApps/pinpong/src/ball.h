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

class Table;

class Ball {
private:
    const Table& table;
public:
    ofVec3f velocity;
    ofVec3f acceleration;
    ofPoint position;

    const int BALL_R = 2; // 40m or 4.4m

    Ball(const Table& table);
    void draw();
    void move(int t);
};

#endif
