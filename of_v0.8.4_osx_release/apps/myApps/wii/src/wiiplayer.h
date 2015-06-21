//
//  wiiplayer.h
//  wii
//
//  Created by 安田裕介 on 2015/06/21.
//
//

#ifndef __wii__wiiplayer__
#define __wii__wiiplayer__

#include <string.h>
#include "ofxOsc.h"

struct WiiParams {
    float roll;
    float yaw;
    float pitch;
    float accel;
};

class Player {
public:
    Player(int number);
    void setParams(const ofxOscMessage& m);
    WiiParams getParams();
    std::string rollAddress();
    std::string yawAddress();
    std::string pitchAddress();
    std::string accelAddress();
    
    
private:
    int number;
    WiiParams params;
};


#endif /* defined(__wii__wiiplayer__) */
