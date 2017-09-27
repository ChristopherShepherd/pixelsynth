//reader.h
//class to read pixels from an image and output sound

#ifndef reader_h
#define reader_h

#include "ofMain.h"
#include "ofxMaxim.h"

class Reader{

	public:
		void setup(int channels_, int numPixels_, int sampleWidth_, int sampleHeight_);
		void draw();

		//passes value to audioOut
		double readNext(vector<ofImage>& ims);

		int currentPixX, currentPixY, sampleWidth, sampleHeight;
		int numPixels, channels;

};

#endif
/////-----reader.h-------------------------------------------
