#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	 

	//check the console to see your options for devices. With only one device plugged in, 
	//you probably want #0
	monomeControl.setup(0);	

	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
			LEDs[i][j]=true;

	monomeControl.ClearLEDs(true);

	ofSetFrameRate(30);
}

//--------------------------------------------------------------
void testApp::update(){

	//Get any recent presses
	int x=0,y=0;
	bool down = false;
	while(monomeControl.GetButtonPress(x,y,down))
	{
		if(down == false && x<16 && y<16)
		{
			LEDs[x][y] = true;
		}
	}

	//Update animation. Move TRUEs to the right 
	if(ofGetFrameNum()>30)
	{
		for(int i=15;i>0;i--)
			for(int j=0;j<16;j++)
				LEDs[i][j]=LEDs[i-1][j];
		for(int j=0;j<16;j++)
			LEDs[0][j]=false;
	}

	//send update to monome.

	//By Full Row:
	for(int row=0;row<8;row++)
	{
		unsigned char val1 = 0;
		unsigned char val2 = 0;
		for(int i=0;i<8;i++)
			if(LEDs[i][row])
				val1 |= 1<<i;
		for(int i=8;i<16;i++)
			if(LEDs[i][row])
				val2 |= 1<<(i-8);
		monomeControl.SetRow2(row,val1,val2);
	}

	/*
	//By column... for the m128
	for(int col=0;col<16;col++)
	{
		unsigned char val1 = 0;
		for(int i=0;i<8;i++)
			if(LEDs[col][i])
				val1 |= 1<<i;
		monomeControl.SetCol1(col,val1);
	}*/
}


//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0,0,0);
	int w = ofGetWidth();
	for(int x=0;x<16;x++)
		for(int y=0;y<16;y++)
		{
			if(LEDs[x][y])
				ofSetColor(255,100,50);
			else
				ofSetColor(50,50,50);
			ofRect(20+50*x,20+50*y,40,40);
		}
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 

}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){

}
