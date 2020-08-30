#include "Circle4.h"

Circle4::Circle4() {
}

void Circle4::setup() {
	d = y = INT_MAX;
	drawCounter = 0;
}

void Circle4::update() {
	makeStepByStep(ofGetWidth() / 2, ofGetHeight() / 2,
		ofGetHeight() / 2);
}

void Circle4::draw() {
	line.draw();
	for (ofPolyline line : lineFromPoints) {
		line.draw();
	}
}

void Circle4::makeStepByStep(int centreX, int centreY, float radius) {
	if (y == INT_MAX && d == INT_MAX) {
		y = radius;
		d = 1.0f / 4 - radius;
	}

	if (drawCounter > 2 * radius / sqrtf(2)) {
		line.clear();
		drawCounter = 0;
		y = radius;
		d = 1.0f / 4 - radius;
	}

	int x = drawCounter;

	//line.addVertex(centreX + x, centreY + y, 0);
	line.addVertex(centreX + x, centreY - y, 0);
	line.addVertex(centreX - x, centreY + y, 0);
	//line.addVertex(ofVec2f(centreX - x, centreY - y));
	//line.addVertex(ofVec2f(centreX + y, centreY + x));
	//line.addVertex(ofVec2f(centreX - y, centreY + x));
	//line.addVertex(ofVec2f(centreX + y, centreY - x));
	//line.addVertex(ofVec2f(centreX - y, centreY - x));

	d += 2 * x + 1;
	if (d > 0)
	{
		d += 2 - 2 * y--;
	}

	drawCounter++;
}