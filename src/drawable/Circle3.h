#ifndef _Circle3
#define _Circle3

#include "ofMain.h"
#include "ofPolyline.h"
#include "IDrawable.h"

#pragma once
class Circle3 : public IDrawable {
public:
	Circle3();

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