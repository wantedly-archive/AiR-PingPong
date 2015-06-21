//
//  vectorField.h
//  pinpong
//
//  Created by Naoyoshi Aikawa on 6/21/15.
//
//

#ifndef __pinpong__vectorField__
#define __pinpong__vectorField__

#include "ofMain.h"
#include "ofVec2f.h"

class vectorField {

public:

    // the internal dimensions of the field:    (ie, 60x40, etc)
    int fieldWidth;
    int fieldHeight;
    int fieldSize;   // total number of "pixels", ie w * h

    // the external dimensions of the field:   (ie, 1024x768)
    int externalWidth;
    int externalHeight;

    vector <ofVec2f> field;

    vectorField();
    virtual ~vectorField();

    void setupField(int innerW, int innerH, int outerW, int outerH);   // pass in internal dimensions and outer dimensions

    void clear();
    void fadeField(float fadeAmount);
    void randomizeField(float scale);
    void draw();

    ofVec2f	getForceFromPos(float xpos, float ypos);

    void addOutwardCircle(float x, float y, float radius, float strength);
    void addInwardCircle(float x, float y, float radius, float strength);
    void addClockwiseCircle(float x, float y, float radius, float strength);
    void addCounterClockwiseCircle(float x, float y, float radius, float strength);
    void addVectorCircle(float x, float y, float vx, float vy, float radius, float strength);

    void setFromPixels(unsigned char * pixels, bool bMoveTowardsWhite, float strength);

protected:
private:
};

#endif /* defined(__pinpong__vectorField__) */
