#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        ofSoundPlayer mySound;
        float * fft;
        int nBandsToGet;
};