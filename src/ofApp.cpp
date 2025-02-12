#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofAddListener(ofGetWindowPtr()->events().keyPressed, this, &ofApp::keycodePressed);
}

//--------------------------------------------------------------
void ofApp::update(){
	//x += ofGetLastFrameTime() * 100;
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofDrawCircle(x, 100, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'q')
	{
		//Insert node at the head of linkedList
		//ofApp::
	}
	else if (key == 'w')
	{
		//Insert node at the tail of linkedList
		//ofApp::
	}
	else if (key == 'a')
	{
		//Delete node at the head
		//ofApp::
	}
	else if (key == 's')
	{
		//Delete node at the tail
		//ofApp::
	}
	else if (key == 'e')
	{
		//Sort the linkedList by ascending order
		//ofApp::
	}
	else if (key == 'z')
	{
		//Increase the amplitude
		//ofApp::
	}
	else if (key == 'x')
	{
		//Decrease the amplitude
		//ofApp::
	}
}

//Code inspire de https://gist.github.com/stungeye/23580e5fef648e2798c069d9e7f83816
void ofApp::keycodePressed(ofKeyEventArgs& e){

	//cout << "KEY : " << e.key << endl;
	//cout << "KEYCODE : " << e.keycode << endl;
	//cout << "MODIFIERS : " << e.modifiers << endl;

	if (e.keycode == 262)
	{
		cout << "RightArrow";
	}
	if (e.keycode == 263)
	{
		cout << "LeftArrow";
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
