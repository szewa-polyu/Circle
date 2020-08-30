#include "IDrawable.h"

void IDrawable::addPointToLineFromPoints(vector<ofPolyline>& aLineFromPoints, ofVec2f point) {
	ofPolyline line;
	line.addVertex(point.x, point.y, 0);
	line.addVertex(point.x + 1, point.y + 1, 0);
	aLineFromPoints.push_back(line);
}