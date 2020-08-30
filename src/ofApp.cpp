#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);
	ofSetFrameRate(30);

	//makeHeart(line);
	//makeCircle1(line, ofGetWidth() / 2, ofGetHeight() / 2, ofGetHeight() / 2);

	drawables.push_back(new Circle1());
	drawables.push_back(new CrossLike());
	drawables.push_back(new Circle2());
	drawables.push_back(new Circle3());
	drawables.push_back(new Circle4());
	drawables.push_back(new Circle5());

	for (IDrawable* drawable : drawables) {
		drawable->setup();
	}
}

void ofApp::makeCircle1(ofPolyline& aLine, int centreX, int centreY, float radius) {
	float angle = 0;
	while (angle < TWO_PI)
	{
		float x = centreX + cos(angle) * radius;
		float y = centreY + sin(angle) * radius;
		aLine.addVertex(x, y, 0);
		angle += TWO_PI / 360;
	}
	aLine.close();
}

// http://openframeworks.cc/documentation/graphics/ofPolyline/
void ofApp::makeHeart(ofPolyline& aLine) {
	float angle = 0;
	while (angle < TWO_PI) {
		float r = (2 - 2 * sin(angle) + sin(angle) * sqrt(abs(cos(angle))) / (sin(angle) + 1.4)) * -80;
		float x = ofGetWidth() / 2 + cos(angle) * r;
		float y = ofGetHeight() / 2 + sin(angle) * r;
		aLine.addVertex(x, y, 0);
		angle += 0.005 * HALF_PI * 0.5;
	}
	aLine.close();
}





//--------------------------------------------------------------
void ofApp::update(){
	// print frame rate as window title
	// https://gist.github.com/izmhr/faa47662a3df8f4acd91
	std::stringstream strm;
	strm << "fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());

	for (IDrawable* drawable : drawables) {
		drawable->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (IDrawable* drawable : drawables) {
		drawable->draw();
	}
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
	/*ofPoint pt;
	pt.set(x, y);
	line.addVertex(pt);*/
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//line.clear();
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
