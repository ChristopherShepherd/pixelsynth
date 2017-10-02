# pixelsynth

#### aim:
The aim of this project was to create a simple synth based on the reading of pixel values.
The user selects a frequency and then clicks and drags on one of the 'channels' to draw a pattern of varying pixel hue corresponding to that fraquency.
Upon pressing play(spacebar) the channel pixel values are read independently top to bottom, left to right, to determine the audio phase step before the channels are combined to produce the final output sound.

* * *
#### dependencies:
The project requires openframeworks and the addon ofxMaxim

* * *
#### instructions:
* select a desired frequency using number keys for presets or the UP and DOWN arrows
* click and drag within the window to add that frequency to the channel, a longer pattern = sound plays for longer
* press SPACEBAR to start/stop audio playback, new sounds can still be added to channels during audio playback
* sounds can be removed by selecting a frequency of 0Hz and dragging over unwanted patterns


* * *
#### example:
Below is an image showing how the display might look following a performance. The process of making a song through adding and block-deleting patterns of colour can result in an interesting visual progression to match(and generate) the music.  
<br>

> ![pixelsynth image](/bin/images/pixelSynth.png)
