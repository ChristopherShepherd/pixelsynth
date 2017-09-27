//writer.cpp

#include "writer.h"

void Writer::setup(int channels_){
//setup images to be drawn
	channels = channels_;

	mousePressX = 0;
	mousePressY = 0;

	//initial frequencey and necessary hueStep to create that frequency
	frequency = 10.813;
	hueStep = (TWO_PI/(float)44100.0)*frequency;
	hueStep = ofMap(hueStep, 0, TWO_PI, 0, 255.0, true);

	currentHue = 0;

	editing = false;
	//pixel height of each sample
	sampleHeight = ofGetWindowHeight()/channels;

	for(int i = 0; i < channels; i++){

		//allocate the necessary image 'samples'
		sampleImages.push_back(ofImage());
		sampleImages[i].allocate(ofGetWindowWidth(), sampleHeight, OF_IMAGE_COLOR);
		ofColor c = ofColor(0);

		//to start set all samples to black
		sampleImages[i].setColor(c);
		sampleImages[i].update();

	}

}

//--------------------------------------------------------------
void Writer::update(int mouseCurrentX){

	if(editing){

		//if editing this sample update the pixels to the current frequency from where the
		//mouse was pressed to the current position
		for(int i = mousePressX; i < mouseCurrentX; i++){
			for(int j = 0; j < sampleHeight; j++){
			
				ofColor c = ofColor::fromHsb(currentHue, 255, 255);
				sampleImages[currentSample].setColor(i, j, c);

				currentHue = (currentHue + hueStep);

				//hue goes from 0 - 255
				while(currentHue>255){
					currentHue -= 255;
				}
			} 
		}

		//update the image once it has been edited
		sampleImages[currentSample].update();

	}

}

//-------------------------------------------------------------
void Writer::draw(){
//draw the images to screen

	for(int i = 0; i < sampleImages.size(); i++){
	
		sampleImages[i].draw(0, i*sampleHeight);
	}
	
	//display the current frequency
	string p = ofToString(frequency);
	ofDrawBitmapString(p, 10, 10);
}

//---------------------------------------------------------------
void Writer::setBeginEdit(int xStart, int yStart){

	//mousePressed so store the initial positions
	mousePressX = xStart;
	mousePressY = yStart;

	//find out which 'sample' is being edited
	currentSample = floor(mousePressY/(ofGetWindowHeight()/channels));
	editing = true;
}

//-------------------------------------------------------------
void Writer::endEdit(){

	editing = false;
}

//-------------------------------------------------------------
void Writer::frequencyUp(){

	//if 'UP Arrow' pressed, increase frequency and recalculate necessary
	//hue step
	frequency += 0.2;

	hueStep = (TWO_PI/(float)44100.0)*frequency;
	hueStep = ofMap(hueStep, 0, TWO_PI, 0, 255.0, true);
}

void Writer::frequencyDown(){

	//same as above but decrease frequency with down arrow
	frequency -= 0.2;
	
	hueStep = (TWO_PI/(float)44100.0)*frequency;
	hueStep = ofMap(hueStep, 0, TWO_PI, 0, 255.0, true);

}

void Writer::setFrequency(double freq){

	//set the frequency to input value
	frequency = freq;

	hueStep = (TWO_PI/(float)44100.0)*frequency;
	hueStep = ofMap(hueStep, 0, TWO_PI, 0, 255.0, true);

}



















