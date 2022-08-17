#include <stdio.h>
#include <wiringPi.h>

#define LED 1
#define SWITCH 4

int main() {
	/*
	Example code for controlling LED with hardware switch
	Outputs result as console output
	*/
	if(wiringPiSetup() == -1) {
		return -1;
	}		
	//initializing wiringPi for GPIO control
	//uses wiringpi pinmap

	pinMode(LED, OUTPUT); //set "LED" pin as OUTPUT
	pinMode(SWITCH, INPUT); //set "SWITCH" pin as INPUT
	
	while(1) {
		if(digitalRead(SWITCH) == HIGH) {
			//read input from switch and if it is HIGH, turns on connected LED
			printf("Button pressed\n");
			digitalWrite(LED, HIGH);
		}
		else {
			printf("Button Not pressed\n");
			digitalWrite(LED, LOW);
		}
		delay(1000);
	}

	return 0;
}


