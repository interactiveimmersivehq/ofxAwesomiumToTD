#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// set framerate
	ofSetFrameRate(60);
	
	//setup inbound UDP connection, bind to port 12000, and non blocking
	udpConnection.Create();
	udpConnection.Bind(12000);
	udpConnection.SetNonBlocking(true);

	// setup browser and initial url, using res of 1280x720
	browser.setup(1280, 720);
	browser.loadURL("http://www.google.ca");
}

//--------------------------------------------------------------
void ofApp::update(){
	// update browser and set window title
	ofxAwesomium::updateCore();
	browser.update();
	ofSetWindowTitle(browser.getTitle());

	//send browser texture over spout
	spout.sendTexture(browser.frame.getTextureReference(),"ofxAwesomiumToTD");

	//get incoming UDP message
	char udpMessage[100000];
	udpConnection.Receive(udpMessage, 100000);
	string message = udpMessage;
	
	//if message isn't blank, load the url
	if(message != ""){
		browser.loadURL(message);
		cout << "loading   " << message << endl;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	//draw browser preview
	if(browser.getIsLoading()) {
		ofSetColor(0);
		ofDrawBitmapString("Loading...", 10, 15);
	}
	ofSetColor(255);
	browser.draw(0,0,300,200);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	browser.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	browser.keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	browser.mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	browser.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	browser.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	browser.mouseReleased(x, y, button);
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


void ofApp::exit() {
	spout.exit();
}
