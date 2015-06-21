#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(50);
    ofSetFrameRate(60);
    ofSetWindowShape(1280, 800);
    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetFullscreen(false);
    
    w = 0;
    h = 0;    // set in update()
    
    players.push_back(Player(1));
    players.push_back(Player(2));
    
    // listen on the given port
    cout << "listening for osc messages on port " << PORT << "\n";
    receiver.setup( PORT );
}

//--------------------------------------------------------------
void ofApp::update(){
    // check for waiting messages
    while( receiver.hasWaitingMessages() )
    {
        if(w == 0 || h == 0){
            w = ofGetWidth();
            h = ofGetHeight();
        }
        // get the next message
        ofxOscMessage m;
        float x,y;
        receiver.getNextMessage( &m );
        
        Player player1 = players[0];
        Player player2 = players[1];
        player1.setParams(m);
        player2.setParams(m);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if ((ofGetFrameNum() % 100) == 0) {
        Player player1 = players[0];
        Player player2 = players[1];
        WiiParams player1P = player1.getParams();
        WiiParams player2P = player2.getParams();
        printf("Player1");
        printf("roll = %f, pitch = %f, yaw = %f, accel = %f\n",
               player1P.roll,player1P.pitch,player1P.yaw,player1P.accel);
        printf("Player2");
        printf("roll = %f, pitch = %f, yaw = %f, accel = %f\n",
               player1P.roll,player1P.pitch,player1P.yaw,player1P.accel);
    }
    
    ofSetColor(255, 130, 0);
    //float radius = 50;
    ofFill();
    //ofCircle(wiiX, wiiY, radius);
    //ofCircle(roll *= ofGetWidth(), yaw *= ofGetHeight(),100);
    //ofCircle(accel *= ofGetWidth(), pitch *= ofGetWidth(), 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
