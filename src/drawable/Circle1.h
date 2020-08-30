#ifndef _Circle1
#define _Circle1

#include "ofMain.h"
#include "ofPolyline.h"
#include "IDrawable.h"

#pragma once
class Circle1: public IDrawable {
public: 
	Circle1();

	void setup();
	void update();
	void draw();

private:
	int drawCounter = 0;
	ofPolyline line;
	vector<ofPolyline> lineFromPoints;

	void makeStepByStep(int centreX, int centreY, float radius);
};

#endif