#ifndef _IDrawable // if this class hasn't been defined, the program can define it
#define _IDrawable // by using this if statement you prevent the class to be called more than once which would confuse the compiler
#include "ofMain.h" // we need to include this to have a reference to the openFrameworks framework
class IDrawable {

public: // place public functions or variables declarations here

// methods, equivalent to specific functions of your class objects
    virtual void setup() = 0;    // setup method, use this to setup your object's initial state
    virtual void update() = 0;  // update method, used to refresh your objects properties
    virtual void draw() = 0;    // draw method, this where you'll do the object's drawing

    //// variables
    //float x;        // position
    //float y;
    //float speedY;   // speed and direction
    //float speedX;
    //int dim;        // size
    //ofColor color;  // color using ofColor type

    //IDrawable();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value

    static void addPointToLineFromPoints(vector<ofPolyline>& aLineFromPoints, ofVec2f point);
private: // place private functions or variables declarations here
}; // don't forget the semicolon!
#endif