#ifndef _Circle4
#define _Circle4

#include "ofMain.h"
#include "ofPolyline.h"
#include "IDrawable.h"

#pragma once
class Circle4 : public IDrawable {
public:
	Circle4();

	void setup();
	void update();
	void draw();

private:
	float d;
	int y;

	int drawCounter = 0;
	ofPolyline line;
	vector<ofPolyline> lineFromPoints;

	void makeStepByStep(int centreX, int centreY, float radius);
};

#endif