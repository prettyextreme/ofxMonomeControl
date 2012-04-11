ofxMonomeControl

Created by Josh Silverman on 3/28/2012.
prettyextreme.com

This is a basic class to simplify direct serial communications
between OF and a monome. I just got tired of interfacing with monomeSerial.
Does not include support for tracking LED or button statuses like the processing 
library does, but I prefer to do that in my host apps anyway.

I tested this code with a monome128 under Windows 7.
It SHOULD PROBABLY work on other platforms with other monomes.
Please let me know of your success or failures.
  
Tested under OF 007

Note: Not all features of the protocol have been included.
(Especially brightness and ADCs for the 40h)
 
Note: There is no reconnection functionality. Coming in Version 2, perhaps.
