//
//  wiiplayer.cpp
//  wii
//
//  Created by 安田裕介 on 2015/06/21.
//
//

#include "wiiplayer.h"

using namespace std;

Player::Player(int number): number(number) {
    
}

void Player::setParams(const ofxOscMessage& m) {
    if (m.getAddress() == rollAddress()) {
        params.roll = m.getArgAsFloat(0);
        
    } else if (m.getAddress() == yawAddress()) {
        params.yaw = m.getArgAsFloat(0);
    }
    else if (m.getAddress() == pitchAddress()) {
        params.pitch = m.getArgAsFloat(0);
        
    } else if (m.getAddress() == accelAddress()) {
        params.accel = m.getArgAsFloat(0);
    }
}

WiiParams Player::getParams() {
    return params;
}

std::string Player::pitchAddress() {
    char buf[20];
    sprintf(buf, "/wii/%d/accel/pry/0", number);
    return string(buf);
}

std::string Player::rollAddress() {
    char buf[20];
    sprintf(buf, "/wii/%d/accel/pry/1", number);
    return string(buf);
}

std::string Player::yawAddress() {
    char buf[20];
    sprintf(buf, "/wii/%d/accel/pry/2", number);
    return string(buf);
}

std::string Player::accelAddress() {
    char buf[20];
    sprintf(buf, "/wii/%d/accel/pry/3", number);
    return string(buf);
}