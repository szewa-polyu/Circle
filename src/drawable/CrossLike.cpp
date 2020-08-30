#include "CrossLike.h"
CrossLike::CrossLike() {
}

void CrossLike::setup() {
	drawCounter = 0;
}

void CrossLike::update() {
	makeStepByStep(ofGetWidth() / 2, ofGetHeight() / 2,
		ofGetHeight() / 2);
}

void CrossLike::draw() {
	line.draw();

	for (ofPolyline line : lineFromPoints) {
		line.draw();
	}
}

void CrossLike::makeStepByStep(int centreX, int centreY, float radius) {
	if (drawCounter > radius / sqrtf(2)) {
		line.clear();
		drawCounter = 0;
	}

	int x = drawCounter;
	int y = radius - drawCounter;
	line.addVertex(centreX + x, centreY + y, 0);
	line.addVertex(centreX + x, centreY - y, 0);
	line.addVertex(centreX - x, centreY + y, 0);
	line.addVertex(centreX - x, centreY - y, 0);
	line.addVertex(centreX + y, centreY + x, 0);
	line.addVertex(centreX - y, centreY + x, 0);
	line.addVertex(centreX + y, centreY - x, 0);
	line.addVertex(centreX - y, centreY - x, 0);

	drawCounter++;
}