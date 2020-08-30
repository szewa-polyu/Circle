#include "Circle1.h"

Circle1::Circle1() {
}

void Circle1::setup() {
	drawCounter = 0;
}

void Circle1::update() {
	makeStepByStep(ofGetWidth() / 2, ofGetHeight() / 2,
		ofGetHeight() / 2);
}

void Circle1::draw() {
	line.draw();

	for (ofPolyline line : lineFromPoints) {
		line.draw();
	}
}

void Circle1::makeStepByStep(int centreX, int centreY, float radius) {
	float angle = drawCounter * TWO_PI / 360;
	if (angle > TWO_PI) {
		line.clear();
		angle = 0;
		drawCounter = 0;
	}
	float x = centreX + cos(angle) * radius;
	float y = centreY + sin(angle) * radius;
	line.addVertex(x, y, 0);
	//aLine.close();
	drawCounter++;
}