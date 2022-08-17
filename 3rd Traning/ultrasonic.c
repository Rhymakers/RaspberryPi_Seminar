#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

#define trigPin 28
#define echoPin 29

int main() {
	/*
	Example code for ultrasonic sensor.
	gets distance between sensor and object and outputs result as console output
	*/
	int distance = 0; //initializing variable "distance" with 0
	long startTime, travelTime; //declaring startTime, travelTime variable
	
	if(wiringPiSetup() == -1) {
		return 1;
	}
		
	pinMode(trigPin, OUTPUT); //set trigPin as OUTPUT
	pinMode(echoPin, INPUT); //set echoPin as INPUT
	printf("ultra: \n");
	
	while(1) {
		digitalWrite(trigPin, LOW);
		usleep(2);
		digitalWrite(trigPin, HIGH);
		usleep(20);
		digitalWrite(trigPin, LOW);
		while(digitalRead(echoPin) == LOW);
		startTime = micros();
		while(digitalRead(echoPin) == HIGH);
		travelTime = micros() + startTime;
		distance = travelTime/58;
		printf("Distance : %d cm \n", distance);
		sleep(1);
	}
		
	return 0;
}