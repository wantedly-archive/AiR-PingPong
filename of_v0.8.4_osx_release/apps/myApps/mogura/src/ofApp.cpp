#include "ofApp.h"

using namespace cv;
using namespace ofxCv;

Vec2f pos(100,100);
Vec2f vec(0,0);
int radius = 20;

//--------------------------------------------------------------
void ofApp::setup(){
    
#ifdef _USE_LIVE_VIDEO
    vidGrabber.setVerbose(true);
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    vidGrabber.setDeviceID(devices[devices.size()-1].id);
    vidGrabber.initGrabber(320,240);
#else
    vidPlayer.loadMovie("fingers.mov");
    vidPlayer.play();
#endif
    
    colorImg.allocate(320,240);
    grayImage.allocate(320,240);
    grayBg.allocate(320,240);
    grayDiff.allocate(320,240);
    
    bLearnBakground = true;
    threshold = 80;
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(100,100,100);
    
    bool bNewFrame = false;
    
#ifdef _USE_LIVE_VIDEO
    vidGrabber.update();
	   bNewFrame = vidGrabber.isFrameNew();
#else
    vidPlayer.update();
    bNewFrame = vidPlayer.isFrameNew();
#endif
    
    if (bNewFrame){
        
#ifdef _USE_LIVE_VIDEO
        colorImg.setFromPixels(vidGrabber.getPixels(), 320,240);
#else
        colorImg.setFromPixels(vidPlayer.getPixels(), 320,240);
#endif
        
        grayImage = colorImg;
        if (bLearnBakground == true){
            grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
            bLearnBakground = false;
        }
        
        // take the abs value of the difference between background and incoming and then threshold:
        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(threshold);
        
        // find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
        // also, find holes is set to true so we will get interior contours as well....
        contourFinder.findContours(grayDiff, 20, (340*240)/3, 10, true);	// find holes
    }
    
    Mat m = toCv(grayDiff);
    
    float sx = 0;
    float sy = 0;
    for (int x=-radius; x<=radius; ++x) {
        for (int y=-radius; y<=radius; ++y) {
            if (x*x+y*y <= radius * radius) {
                uint32 value = m.at<uint8>((int)pos[1] + y, (int)pos[0] + x);
                if (value == 255) {
                    sx += (x>0) ? - radius + x : x + radius;
                    sy += (y>0) ? - radius + y : y + radius;
                    m.at<uint8>((int)pos[1] + y, (int)pos[0] + x) = 0;
                }
            }
        }
    }
    vec[0] += sx * 0.1;
    vec[1] += sy * 0.1;
    pos[0] += vec[0] * 0.016;
    pos[1] += vec[1] * 0.016;
    if (pos[0] < radius) {
        pos[0] = radius;
        if (vec[0] < 0) {
            vec[0] = 0;
            //            vec[0] = -vec[0];
        }
    } else if (pos[0] > m.cols - radius) {
        pos[0] = m.cols - radius;
        if (vec[0] > 0) {
            vec[0] = 0;
            //            vec[0] = -vec[0];
        }
    }
    if (pos[1] < radius) {
        pos[1] = radius;
        if (vec[1] < 0) {
            vec[1] = 0;
            //            vec[1] = -vec[1];
        }
    } else if (pos[1] > m.rows - radius) {
        pos[1] = m.rows - radius;
        if (vec[1] > 0) {
            vec[1] = 0;
            //            vec[1] = -vec[1];
        }
    }
    
    cv::circle(m, cv::Point((int)pos[0], (int)pos[1]), radius, cv::Scalar(255,255,255,255));
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw the incoming, the grayscale, the bg and the thresholded difference
    ofSetHexColor(0xffffff);
    colorImg.draw(20,20);
    grayImage.draw(360,20);
    grayBg.draw(20,280);
    grayDiff.draw(360,280);
    
    // then draw the contours:
    
    ofFill();
    ofSetHexColor(0x333333);
    ofRect(360,540,320,240);
    ofSetHexColor(0xffffff);
    
    // we could draw the whole contour finder
    //contourFinder.draw(360,540);
    
    // or, instead we can draw each blob individually from the blobs vector,
    // this is how to get access to them:
    for (int i = 0; i < contourFinder.nBlobs; i++){
        contourFinder.blobs[i].draw(360,540);
        
        // draw over the centroid if the blob is a hole
        ofSetColor(255);
        if(contourFinder.blobs[i].hole){
            ofDrawBitmapString("hole",
                               contourFinder.blobs[i].boundingRect.getCenter().x + 360,
                               contourFinder.blobs[i].boundingRect.getCenter().y + 540);
        }
    }
    
    // finally, a report:
    ofSetHexColor(0xffffff);
    stringstream reportStr;
    reportStr << "bg subtraction and blob detection" << endl
    << "press ' ' to capture bg" << endl
    << "threshold " << threshold << " (press: +/-)" << endl
    << "num blobs found " << contourFinder.nBlobs << ", fps: " << ofGetFrameRate() << endl
    << "speed " << (int)vec[0] << " ," << (int)vec[1];
    ofDrawBitmapString(reportStr.str(), 20, 600);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key){
        case ' ':
            bLearnBakground = true;
            break;
        case '+':
            threshold ++;
            if (threshold > 255) threshold = 255;
            break;
        case '-':
            threshold --;
            if (threshold < 0) threshold = 0;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
