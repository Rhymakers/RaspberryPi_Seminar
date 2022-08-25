#include <stdio.h>		// c언어 표준입출력 라이브러리
#include <wiringPi.h>	// 라즈베리파이에서 gpio 제어를 위한 라이브러리

#define LED 1			// LED의 + 극에 연결된 라즈베리파이 핀
#define BUTTON 4		// BUTTON에 연결된 라즈베리파이 핀

int main() {
	/*
	Example code for controlling LED with hardware button
	Outputs result as console output
	*/
	if(wiringPiSetup() == -1) {
		return -1;
	}		
	//initializing wiringPi for GPIO control
	//uses wiringpi pinmap

	pinMode(LED, OUTPUT); 	//set "LED" pin as OUTPUT
	pinMode(BUTTON, INPUT); //set "BUTTON" pin as INPUT
	
	while(1) {
		if(digitalRead(BUTTON) == HIGH) {
			//read input from button and if it is HIGH, turns on connected LED
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


