//reader.cpp

#include "reader.h"

void Reader::setup(int channels_, int numPixels_, int sampleWidth_, int sampleHeight_){

	channels = channels_;
	numPixels = numPixels_;
	sampleWidth = sampleWidth_;
	sampleHeight = sampleHeight_;

	//initialise pixels to be read as 0, 0
	currentPixX = 0;
	currentPixY = 0;

}

void Reader::draw(){

	//show where the x-playhead is currently reading
	ofDrawLine(currentPixX, 0, currentPixX, ofGetWindowHeight());

}

double Reader::readNext(vector<ofImage>& ims){

	//keep a running total of the hue value
	double theHue = 0.0;

	for(int i = 0; i < channels; i++){

		//get the hue values for pixels under the current playhead
		ofColor c1 = ims[i].getColor(currentPixX, currentPixY);
		theHue += c1.getHueAngle();
	}

	//as with audio divide the total by the number of inputs
	theHue /= channels;
	theHue = ofMap(theHue, 0, 360, 0, TWO_PI, true);

	//move to the next pixel
	currentPixY ++;
	//if y axis playhead has reached sample height, reset it and increment x-playhead
	if(currentPixY > sampleHeight){

		currentPixY = 0;
		currentPixX = (currentPixX+1)%sampleWidth;
	}

	//return sin of the cumulative hue value
	return sin(theHue);
}
