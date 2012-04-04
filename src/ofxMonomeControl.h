#ifndef ___MONOME_CONTROL__
#define ___MONOME_CONTROL__


// ofxMonomeControl.h
// ofxMonomeControl.cpp
//
// Created by Josh Silverman on 3/28/2012.
// prettyextreme.com
// Creative Commons... Free for whatever the hell you want to do with it. 
// Sell it. Whatever.
// No warrantee... blah blah blah
//
// This is just a basic class to simplify direct serial communications
// between OF and a monome. I just got tired of interfacing with monomeSerial.
//  
// monome.org
//
// I tested this code with a monome128 under Windows 7.
// It SHOULD PROBABLY work on other platforms with other monomes.
// But I make no promises.
//  
// Tested under of 007
//
// Note: Not all features of the protocol have been included.
// (Especially brightness and ADCs for the 40h)
// But you've gotten this far. I'm sure you can figure it out!
//  
// Note: I admit, there is no reconnection functionality here.
// Not the most "robust" thing in the world. But it works for me.


#include "ofSerial.h"

//We're just polling for button presses on every frame.
//This buffer is WAY bigger than necessary. But whatevs.
#define INCOMING_BUFFER_LEN 10000

class ofxMonomeControl
{
	public:
		ofxMonomeControl();
		~ofxMonomeControl();
		bool setup(int deviceID){
			isInit = serialPort.setup(deviceID,9600);
			return isInit;
		}
		bool GetButtonPress(int& x, int& y, bool& down);
		void SetLED(int x, int y, bool ON);
		void ClearLEDs(bool ON = false);
		void SetRow1(int row, unsigned char val);
		void SetCol1(int col, unsigned char val);
		void SetRow2(int row, unsigned char valLeft8, unsigned char valRight8);
		void SetCol2(int col, unsigned char valTop8, unsigned char valBottom8);

	protected:

		bool isInit;

		ofSerial serialPort;

		unsigned char incomingBuffer[INCOMING_BUFFER_LEN];
		int incomingCount;
		int incomingPosition;
};

#endif