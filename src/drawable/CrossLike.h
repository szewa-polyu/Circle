#ifndef _CrossLike
#define _CrossLike

#include "ofMain.h"
#include "ofPolyline.h"
#include "IDrawable.h"

#pragma once
class CrossLike : public IDrawable {
public:
	CrossLike();

	void setup();
	void update();
	void draw();

private:
	int drawCounter;
	ofPolyline line;
	vector<ofPolyline> lineFromPoints;

	void makeStepByStep(int centreX, int centreY, float radius);
};

#endif