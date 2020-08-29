#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);
	ofSetFrameRate(30);

	//makeHeart(line);
	//makeCircle1(line, ofGetWidth() / 2, ofGetHeight() / 2, ofGetHeight() / 2);
	
	drawCounterForCircle1 = 0;
	drawCounterForCrossLike = 0;

	drawCounterForCircle2 = 0;
	dForCircle2 = yForCircle2 = INT_MAX;

	drawCounterForCircle3 = 0;
	dForCircle3 = yForCircle3 = INT_MAX;

	drawCounterForCircle4 = 0;
	dForCircle4 = yForCircle4 = INT_MAX;

	drawCounterForCircle5 = 0;
	dForCircle5 = yForCircle5 = INT_MAX;
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

void ofApp::makeCircle1StepByStep(ofPolyline& aLine, int centreX, int centreY, float radius) {
	float angle = drawCounterForCircle1 * TWO_PI / 360;
	if (angle > TWO_PI) {
		aLine.clear();
		angle = 0;
		drawCounterForCircle1 = 0;
	}
	float x = centreX + cos(angle) * radius;
	float y = centreY + sin(angle) * radius;
	aLine.addVertex(x, y, 0);
	//aLine.close();
	drawCounterForCircle1++;
}

void ofApp::makeCrossLikeStepByStep(ofPolyline& aLine, int centreX, int centreY, float radius) {
	if (drawCounterForCrossLike > radius / sqrtf(2)) {
		aLine.clear();
		drawCounterForCrossLike = 0;
	}

	int x = drawCounterForCrossLike;
	int y = radius - drawCounterForCrossLike;
	aLine.addVertex(centreX + x, centreY + y, 0);
	aLine.addVertex(centreX + x, centreY - y, 0);
	aLine.addVertex(centreX - x, centreY + y, 0);
	aLine.addVertex(centreX - x, centreY - y, 0);
	aLine.addVertex(centreX + y, centreY + x, 0);
	aLine.addVertex(centreX - y, centreY + x, 0);
	aLine.addVertex(centreX + y, centreY - x, 0);
	aLine.addVertex(centreX - y, centreY - x, 0);

	drawCounterForCrossLike++;
}

void ofApp::makeCircle2StepByStep(ofPolyline& aLine, int centreX, int centreY, float radius) {
	if (yForCircle2 == INT_MAX && dForCircle2 == INT_MAX) {
		yForCircle2 = radius;
		dForCircle2 = 1.0f / 4 - radius;
	}

	if (drawCounterForCircle2 > radius / sqrtf(2)) {
		aLine.clear();
		drawCounterForCircle2 = 0;
		yForCircle2 = radius;
		dForCircle2 = 1.0f / 4 - radius;
	}

	int x = drawCounterForCircle2;
	int y = yForCircle2;

	aLine.addVertex(centreX + x, centreY + y, 0);
	aLine.addVertex(centreX + x, centreY - y, 0);
	aLine.addVertex(centreX - x, centreY + y, 0);
	aLine.addVertex(centreX - x, centreY - y, 0);
	aLine.addVertex(centreX + y, centreY + x, 0);
	aLine.addVertex(centreX - y, centreY + x, 0);
	aLine.addVertex(centreX + y, centreY - x, 0);
	aLine.addVertex(centreX - y, centreY - x, 0);

	dForCircle2 += 2 * x + 1;
	if (dForCircle2 > 0)
	{
		dForCircle2 += 2 - 2 * yForCircle2--;
	}

	drawCounterForCircle2++;
}

void ofApp::makeCircle3StepByStep(vector<ofPolyline> aLineFromPoints, int centreX, int centreY,
	float radius) {
	if (yForCircle3 == INT_MAX && dForCircle3 == INT_MAX) {
		yForCircle3 = radius;
		dForCircle3 = 1.0f / 4 - radius;
	}

	if (drawCounterForCircle3 > radius / sqrtf(2)) {
		lineFromPoints.clear();
		drawCounterForCircle3 = 0;
		yForCircle3 = radius;
		dForCircle3 = 1.0f / 4 - radius;
	}

	int x = drawCounterForCircle3;
	int y = yForCircle3;

	addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX + x, centreY + y));
	addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX + x, centreY - y));
	addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX - x, centreY + y));
	addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX - x, centreY - y));
	addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX + y, centreY + x));
	addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX - y, centreY + x));
	addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX + y, centreY - x));
	addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX - y, centreY - x));

	dForCircle3 += 2 * x + 1;
	if (dForCircle3 > 0)
	{
		dForCircle3 += 2 - 2 * yForCircle3--;
	}

	drawCounterForCircle3++;
}

void ofApp::makeCircle4StepByStep(ofPolyline& aLine, int centreX, int centreY, float radius) {
	if (yForCircle4 == INT_MAX && dForCircle4 == INT_MAX) {
		yForCircle4 = radius;
		dForCircle4 = 1.0f / 4 - radius;
	}

	if (drawCounterForCircle4 > 2 * radius / sqrtf(2)) {
		aLine.clear();
		drawCounterForCircle4 = 0;
		yForCircle4 = radius;
		dForCircle4 = 1.0f / 4 - radius;
	}

	int x = drawCounterForCircle4;
	int y = yForCircle4;

	//aLine.addVertex(centreX + x, centreY + y, 0);
	aLine.addVertex(centreX + x, centreY - y, 0);
	aLine.addVertex(centreX - x, centreY + y, 0);
	//aLine.addVertex(ofVec2f(centreX - x, centreY - y));
	//aLine.addVertex(ofVec2f(centreX + y, centreY + x));
	//aLine.addVertex(ofVec2f(centreX - y, centreY + x));
	//aLine.addVertex(ofVec2f(centreX + y, centreY - x));
	//aLine.addVertex(ofVec2f(centreX - y, centreY - x));

	dForCircle4 += 2 * x + 1;
	if (dForCircle4 > 0)
	{
		dForCircle4 += 2 - 2 * yForCircle4--;
	}

	drawCounterForCircle4++;
}

void ofApp::makeCircle5StepByStep(vector<ofPolyline> aLineFromPoints, int centreX, int centreY,
	float radius) {
	if (yForCircle5 == INT_MAX && dForCircle5 == INT_MAX) {
		yForCircle5 = radius;
		dForCircle5 = 1.0f / 4 - radius;
	}

	if (drawCounterForCircle5 > 2 * radius / sqrtf(2)) {
		lineFromPoints.clear();
		drawCounterForCircle5 = 0;
		yForCircle5 = radius;
		dForCircle5 = 1.0f / 4 - radius;
	}

	int x = drawCounterForCircle5;
	int y = yForCircle5;

	addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX + x, centreY + y));
	//addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX + x, centreY - y));
	//addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX - x, centreY + y));
	addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX - x, centreY - y));
	//addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX + y, centreY + x));
	//addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX - y, centreY + x));
	//addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX + y, centreY - x));
	//addPointToLineFromPoints(aLineFromPoints, ofVec2f(centreX - y, centreY - x));

	dForCircle5 += 2 * x + 1;
	if (dForCircle5 > 0)
	{
		dForCircle5 += 2 - 2 * yForCircle5--;
	}

	drawCounterForCircle5++;
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

void ofApp::addPointToLineFromPoints(vector<ofPolyline> aLineFromPoints, ofVec2f point) {
	ofPolyline line;
	line.addVertex(point.x, point.y, 0);
	line.addVertex(point.x + 1, point.y + 1, 0);
	lineFromPoints.push_back(line);
}




//--------------------------------------------------------------
void ofApp::update(){
	// print frame rate as window title
	// https://gist.github.com/izmhr/faa47662a3df8f4acd91
	std::stringstream strm;
	strm << "fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());

	/*makeCircle1StepByStep(line, ofGetWidth() / 2, ofGetHeight() / 2,
		ofGetHeight() / 2);*/
	/*makeCrossLikeStepByStep(line, ofGetWidth() / 2, ofGetHeight() / 2,
		ofGetHeight() / 2);*/
	makeCircle2StepByStep(line, ofGetWidth() / 2, ofGetHeight() / 2,
		ofGetHeight() / 2);
	/*makeCircle3StepByStep(lineFromPoints, ofGetWidth() / 2, ofGetHeight() / 2,
		ofGetHeight() / 2);*/
	/*makeCircle4StepByStep(line, ofGetWidth() / 2, ofGetHeight() / 2,
		ofGetHeight() / 2);*/
}

//--------------------------------------------------------------
void ofApp::draw(){
	line.draw();

	for (ofPolyline line : lineFromPoints) {
		line.draw();
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
