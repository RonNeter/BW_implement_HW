This is my solution for the assignment for the embedded SW position in Blue White.
A summary of what I have tried to do:
	1) I have used an Arduino Due board as it was the only one I got at home
	2) In assignment, it is implied to use cpp and oop so I have tried to build the code around clasees instead of structures like I am used to from my previous work.
	3) I have not gone into depth in the part of the communication drivers, it most likely is a bit more complex than what I did because there probably are way more communication busses that are managed with interrupts or with a kind of OS. (maybe)
	4) I gave an example of 2 types of implements, each can have one of three communication protocols (I2C, CAN, Serial). One of the types has some unique functions (just an example of a get and a set) and the other does not have any functions other than what it inherites from the base "Implement" class.
	5) I have created some sort of controller as an API to control the different implements where I use an array to store the  pointers to the implement objects that were created.
To compile, and upload to an Arduino board, it is possible to use the Arduino IDE or the Arduino extension for vscode.
Download all following files and open with Arduino IDE, download needed library and upload to board.
I have used a canbus library called CAN by sandeep mistry.

*I could not test all the SW functions but I could "control" and "get telemetry" from the an implement using serial comunication with an arduino and a serial port and it worked ok.

I hope most of this is clear :)