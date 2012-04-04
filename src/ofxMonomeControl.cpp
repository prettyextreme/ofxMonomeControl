#include "ofxMonomeControl.h"

/*
Based on spec from 
http://docs.monome.org/doku.php?id=tech:protocol:serial:series
*/

ofxMonomeControl::ofxMonomeControl(){

	char buf[1000];
	char** b;
	serialPort.enumerateDevices();

	incomingCount = 0;
	incomingPosition = 0;
}

ofxMonomeControl::~ofxMonomeControl(){

	if(!isInit)
		return;

	serialPort.close();
}

bool ofxMonomeControl::GetButtonPress(int& x, int& y, bool& down){

	if(!isInit)
		return false;

	if(incomingPosition >= incomingCount){
		incomingPosition = 0;
		incomingCount = serialPort.readBytes(incomingBuffer,INCOMING_BUFFER_LEN);
	}

	if(incomingPosition >= incomingCount){
		return false;
	}

	if(incomingCount > incomingPosition+1)
	{
		unsigned char downup = incomingBuffer[incomingPosition];
		unsigned char xy = incomingBuffer[incomingPosition+1];
		x = (xy>>4)&0x0F;
		y = xy&0x0F;
		if(((downup>>4)&0x01) == 1) down = false;
		else			down = true;

		incomingPosition+=2;		
	}

	return true;
}

void ofxMonomeControl::SetLED(int x, int y, bool ON){

	if(!isInit){
		return;
	}

	unsigned char buf[2];
	int on = ON?2:3;
	buf[0] = on<<4;
	buf[1] = ((x&0x0F)<<4 | (y&0x0F));
	if(serialPort.writeBytes(buf, 2) == OF_SERIAL_ERROR){
		isInit = false;	
	}
}


void ofxMonomeControl::ClearLEDs(bool ON){

	if(!isInit){
		return;
	}

	unsigned char buf[1];
	int id = 9;
	buf[0] = id<<4;
	if(ON){
		buf[0] |= 0x01;
	}

	if(serialPort.writeBytes(buf, 1) == OF_SERIAL_ERROR){
		isInit = false;	
	}
}

void ofxMonomeControl::SetRow1(int row, unsigned char val){

	if(!isInit){
		return;
	}

	unsigned char buf[2];
	int id = 4;
	buf[0] = id<<4;
	buf[0] |= (row & 0x0F);
	buf[1] = val & 0xFF;

	if(serialPort.writeBytes(buf, 2) == OF_SERIAL_ERROR)
		isInit = false;	
}

void ofxMonomeControl::SetCol1(int col, unsigned char val){

	if(!isInit){
		return;
	}

	unsigned char buf[2];
	int id = 5;
	buf[0] = id<<4;
	buf[0] |= (col & 0x0F);
	buf[1] = val & 0xFF;

	if(serialPort.writeBytes(buf, 2) == OF_SERIAL_ERROR){
		isInit = false;	
	}
}

void ofxMonomeControl::SetRow2(int row, unsigned char valLeft8, unsigned char valRight8){

	if(!isInit){
		return;
	}

	unsigned char buf[3];
	int id = 6;
	buf[0] = id<<4;
	buf[0] |= (row & 0x0F);
	buf[1] = valLeft8;
	buf[2] = valRight8;

	if(serialPort.writeBytes(buf, 3) == OF_SERIAL_ERROR){
		isInit = false;	
	}
}


void ofxMonomeControl::SetCol2(int col, unsigned char valTop8, unsigned char valBottom8){

	if(!isInit){
		return;
	}

	unsigned char buf[3];
	int id = 7;
	buf[0] = id<<4;
	buf[0] |= (col & 0x0F);
	buf[1] = valTop8;
	buf[2] = valBottom8;

	if(serialPort.writeBytes(buf, 3) == OF_SERIAL_ERROR){
		isInit = false;	
	}
}