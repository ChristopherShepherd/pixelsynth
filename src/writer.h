//writer.h
//class to write pixels to an image based on set frequency

#ifndef writer_h
#define writer_h

#include "ofMain.h"

class Writer{


	public:
		
		void setup(int channels);
		void update(int mouseCurrentX);
		void draw();

		double frequency;//map to hue
		//double amplitude;//map to brightness;

		double currentHue, hueStep;

		vector<ofImage> sampleImages;

		int channels, sampleHeight, mousePressX, mousePressY, currentSample;

		void setBeginEdit(int xStart, int yStart);
		void endEdit();

		void frequencyUp();
		void frequencyDown();
		void setFrequency(double freq);

		bool editing;

};

#endif
/////-----writer.h-----------------------------------------------
