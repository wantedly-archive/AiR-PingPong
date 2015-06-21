#pragma once

#include "ofMain.h"
#include "ofxQuadWarp.h"
#include "table.h"
#include "vectorField.h"

class ofApp : public ofBaseApp {
    
public:
		
    void setup();
    void update();
    void draw();
    void exit();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofxQuadWarp warper;
    
    Table table;

    ofVideoGrabber vidGrabber;

    ofxCvColorImage colorImage;
    ofxCvGrayscaleImage grayImage;
    ofFbo cameraFbo;
    bool showCamera;
    bool showHelp;

private:
    int t;
    int threshold;
    ofxCvGrayscaleImage baseImage;
    ofxCvGrayscaleImage imageDiff;
    ofxCvGrayscaleImage smallImageDiff;
    vectorField vf;
    bool isToGetBaseImage;
};
