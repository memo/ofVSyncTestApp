// uncomment ONLY ONE of the below
#define HOST_OPENFRAMEWORKS
//#define HOST_CINDER

#include "common.h"

class VSyncTest : public ofBaseApp {
public:
	//--------------------------------------------------------------
	void setup() override {
		// init file logging
		ofLogToFile(msa::vsynctest::getLogPath(), true);

		msa::vsynctest::init();
	}

	//--------------------------------------------------------------
	void draw() override {
		ofBackground(0);
		ofSetColor(255);

		msa::vsynctest::renderStart();

		// draw text
		ofDrawBitmapString(msa::vsynctest::getAllDisplayStatsStr(), 10, 15);

		msa::vsynctest::logAllStats();

		msa::vsynctest::renderEnd();
	}

	//--------------------------------------------------------------
	// set any key to toggle fullscreen
	void keyPressed(int key) {
		ofToggleFullscreen();
	}
};



//========================================================================
int main() {
	ofSetupOpenGL(640, 480, OF_WINDOW);			// <-------- setup the GL context
	ofRunApp(new VSyncTest());
}