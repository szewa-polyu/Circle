#pragma once

#include "ofMain.h"
#include "ofPolyline.h"
#include "drawable/IDrawable.h"
#include "drawable/Circle1.h"
#include "drawable/CrossLike.h"
#include "drawable/Circle2.h"
#include "drawable/Circle3.h"
#include "drawable/Circle4.h"
#include "drawable/Circle5.h"

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

		vector<IDrawable*> drawables;

		ofPolyline line;
		vector<ofPolyline> lineFromPoints;
		void makeCircle1(ofPolyline& aLine, int centreX, int centreY, float radius);
		void makeHeart(ofPolyline& aLine);
};
