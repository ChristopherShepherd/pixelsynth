#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	sampleRate = 44100;
	bufferSize = 512;
	numberBuffers = 4;
	numberOutputChannels = 2;

	//be ready to draw new images, playback of sound toggled with spacebar
	writing = true;
	reading = false;

	maxiSettings::setup(sampleRate, numberOutputChannels, bufferSize);

	//setup writer object with number of different 'samples' to play
	writer.setup(4);

	//setup reader with calculated writer 'sample' sizes
	ofPixels & p = writer.sampleImages[0].getPixels(); 	
	reader.setup(4, p.size(), writer.sampleImages[0].getWidth(), writer.sampleImages[0].getHeight());

	ofSoundStreamSetup(numberOutputChannels, 0, this, sampleRate, bufferSize, numberBuffers);

}

//--------------------------------------------------------------
void ofApp::update(){

	if(writing){
	
		//writing when mouse is pressed
		writer.update(mouseX);//write sample values to image

	}else if(reading){
	
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

		writer.draw();//draw current sample-values images to screen

		reader.draw();//make obvious the pixel being played

}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels){

	for(int i = 0; i < bufferSize; i++){

		if(reading){

			//if reading ask reader to calculate next amp value from the writer
			//immages being drawn
			double sampOut = reader.readNext(writer.sampleImages);

			output[i*nChannels] = sampOut; 
			output[i*nChannels + 1] = sampOut;
		}

	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	//increase and decrease frequency with arrow up and down
	if(key == OF_KEY_UP){
		writer.frequencyUp();
	}

	if(key == OF_KEY_DOWN){
		writer.frequencyDown();
	}

	//toggle resultant sound with spacebar
	if(key == 32){

		reading = !reading;
	}

	//use numbers to select preset frequency values
	if(key == '0'){
		
		writer.setFrequency(0.013);
	}
	if(key == '1'){
		
		writer.setFrequency(80.013);
	}
	if(key == '2'){
		
		writer.setFrequency(160.413);
	}
	if(key == '3'){
		
		writer.setFrequency(200.013);
	}
	if(key == '4'){
		
		writer.setFrequency(320.813);
	}


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	writer.setBeginEdit(mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	writer.endEdit();

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
