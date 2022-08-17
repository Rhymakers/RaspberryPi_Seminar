#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

#define trigPin 28
#define echoPin 29

int main()
{
	int distance =0;
	long startTime, travelTime;
	
	if(wiringPiSetup() == -1)
		return 1;
		
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	printf("ultra: \n");
	
	while(1)
	{
		digitalWrite(trigPin,LOW);
		usleep(2);
		digitalWrite(trigPin,HIGH);
		usleep(20);
		digitalWrite(trigPin,LOW);
		while(digitalRead(echoPin) == LOW);
		startTime = micros();
		while(digitalRead(echoPin) == HIGH);
		travelTime = micros() + startTime;
		distance = travelTime/ 58;
		printf("Distance : %d cm \n", distance);
		sleep(1);
	}
		
	return 0;
}

