#pragma once

#include "ofMain.h"
#include "ofPolyline.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofPolyline line;
		vector<ofPolyline> lineFromPoints;
		void makeCircle1(ofPolyline& aLine, int centreX, int centreY, float radius);
		void makeCircle1StepByStep(ofPolyline& aLine, int centreX, int centreY, float radius);
		void makeCrossLikeStepByStep(ofPolyline& aLine, int centreX, int centreY, float radius);
		void makeCircle2StepByStep(ofPolyline& aLine, int centreX, int centreY, float radius);
		void makeCircle3StepByStep(vector<ofPolyline> aLineFromPoints, int centreX, int centreY,
			float radius);
		void makeCircle4StepByStep(ofPolyline& aLine, int centreX, int centreY, float radius);
		void makeCircle5StepByStep(vector<ofPolyline> aLineFromPoints, int centreX, int centreY,
			float radius);
		void makeHeart(ofPolyline& aLine);
		void addPointToLineFromPoints(vector<ofPolyline> aLineFromPoints, ofVec2f point);

		int drawCounterForCircle1;
		int drawCounterForCrossLike;
		
		int drawCounterForCircle2;
		float dForCircle2;
		int yForCircle2;

		int drawCounterForCircle3;
		float dForCircle3;
		int yForCircle3;

		int drawCounterForCircle4;
		float dForCircle4;
		int yForCircle4;

		int drawCounterForCircle5;
		float dForCircle5;
		int yForCircle5;
};
