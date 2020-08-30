#include "Circle2.h"

Circle2::Circle2() {
}

void Circle2::setup() {
	d = y = INT_MAX;
	drawCounter = 0;
}

void Circle2::update() {
	makeStepByStep(ofGetWidth() / 2, ofGetHeight() / 2,
		ofGetHeight() / 2);
}

void Circle2::draw() {
	line.draw();

	for (ofPolyline line : lineFromPoints) {
		line.draw();
	}
}

void Circle2::makeStepByStep(int centreX, int centreY, float radius) {
	if (y == INT_MAX && d == INT_MAX) {
		y = radius;
		d = 1.0f / 4 - radius;
	}

	if (drawCounter > radius / sqrtf(2)) {
		line.clear();
		drawCounter = 0;
		y = radius;
		d = 1.0f / 4 - radius;
	}

	int x = drawCounter;

	line.addVertex(centreX + x, centreY + y, 0);
	line.addVertex(centreX + x, centreY - y, 0);
	line.addVertex(centreX - x, centreY + y, 0);
	line.addVertex(centreX - x, centreY - y, 0);
	line.addVertex(centreX + y, centreY + x, 0);
	line.addVertex(centreX - y, centreY + x, 0);
	line.addVertex(centreX + y, centreY - x, 0);
	line.addVertex(centreX - y, centreY - x, 0);

	d += 2 * x + 1;
	if (d > 0)
	{
		d += 2 - 2 * y--;
	}

	drawCounter++;
}