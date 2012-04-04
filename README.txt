ofxMonomeControl

Created by Josh Silverman on 3/28/2012.
prettyextreme.com

This is a basic class to simplify direct serial communications
between OF and a monome. I just got tired of interfacing with monomeSerial.
Does not include support for tracking LED or button statuses like the processing library does, but I prefer to do that in my host apps anyway.

Creative Commons... Free for whatever you want to do with it. Sell it. Whatever. To that nice wide monome user base.

No warrantee... obvi.

I tested this code with a monome128 under Windows 7.
It SHOULD PROBABLY work on other platforms with other monomes.
  
Tested under of 007

Note: Not all features of the protocol have been included.
(Especially brightness and ADCs for the 40h)
But you've gotten this far. I'm sure you can figure it out!
 
Note: I admit, there is no reconnection functionality here.
Not the most "robust" thing in the world. But it works for me.
