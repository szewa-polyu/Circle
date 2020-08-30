#include "Circle5.h"

Circle5::Circle5() {
}

void Circle5::setup() {
	d = y = INT_MAX;
	drawCounter = 0;
}

void Circle5::update() {
	makeStepByStep(ofGetWidth() / 2, ofGetHeight() / 2,
		ofGetHeight() / 2);
}

void Circle5::draw() {
	line.draw();
	for (ofPolyline line : lineFromPoints) {
		line.draw();
	}
}

void Circle5::makeStepByStep(int centreX, int centreY, float radius) {
	if (y == INT_MAX && d == INT_MAX) {
		y = radius;
		d = 1.0f / 4 - radius;
	}

	if (drawCounter > 2 * radius / sqrtf(2)) {
		lineFromPoints.clear();
		drawCounter = 0;
		y = radius;
		d = 1.0f / 4 - radius;
	}

	int x = drawCounter;

	addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX + x, centreY + y));
	//addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX + x, centreY - y));
	//addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX - x, centreY + y));
	addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX - x, centreY - y));
	//addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX + y, centreY + x));
	//addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX - y, centreY + x));
	//addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX + y, centreY - x));
	//addPointToLineFromPoints(lineFromPoints, ofVec2f(centreX - y, centreY - x));

	d += 2 * x + 1;
	if (d > 0)
	{
		d += 2 - 2 * y--;
	}

	drawCounter++;
}