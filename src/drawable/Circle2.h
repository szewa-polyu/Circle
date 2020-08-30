#ifndef _Circle2
#define _Circle2

#include "ofMain.h"
#include "ofPolyline.h"
#include "IDrawable.h"

#pragma once
class Circle2 : public IDrawable {
public:
	Circle2();

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