#include "Circle3.h"

Circle3::Circle3() {
}

void Circle3::setup() {
	d = y = INT_MAX;
	drawCounter = 0;
}

void Circle3::update() {
	makeStepByStep(ofGetWidth() / 2, ofGetHeight() / 2,
		ofGetHeight() / 2);
}

void Circle3::draw() {
	line.draw();
	ofLogNotice(ofToString(lineFromPoints.size()));
	for (ofPolyline line : lineFromPoints) {
		line.draw();
	}
}

void Circle3::makeStepByStep(int centreX, int centreY, float radius) {
	if (y == INT_MAX && d == INT_MAX) {
		y = radius;
		d = 1.0f / 4 - radius;
	}

	if (drawCounter > radius / sqrtf(2)) {
		lineFromPoints.clear();
		drawCounter = 0;
		y = radius;
		d = 1.0f / 4 - radius;
	}

	int x = drawCounter;

	addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX + x, centreY + y));
	addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX + x, centreY - y));
	addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX - x, centreY + y));
	addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX - x, centreY - y));
	addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX + y, centreY + x));
	addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX - y, centreY + x));
	addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX + y, centreY - x));
	addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX - y, centreY - x));

	d += 2 * x + 1;
	if (d > 0)
	{
		d += 2 - 2 * y--;
	}

	drawCounter++;
}