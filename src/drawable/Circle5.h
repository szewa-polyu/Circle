#ifndef _Circle5
#define _Circle5

#include "ofMain.h"
#include "ofPolyline.h"
#include "IDrawable.h"

#pragma once
class Circle5 : public IDrawable {
public:
	Circle5();

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