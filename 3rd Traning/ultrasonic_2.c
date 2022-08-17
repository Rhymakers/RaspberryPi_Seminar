#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

#define trigPin 1     // wpi 1(= Physical 12)
#define echoPin 29    // wpi 29(= Physical 29)
 
int main(void) {
    /*
	Example code for ultrasonic sensor.
	gets distance between sensor and object and outputs result as console output
	*/
    int distance = 0; //initializing variable "distance" with 0
    long startTime, travelTime; //declaring startTime, travelTime variable
    
    if(wiringPiSetup () == -1) {
        printf("Unable GPIO Setup"); 
        return 1;
    }
        
    pinMode (trigPin, OUTPUT); //set trigPin as OUTPUT
    pinMode (echoPin, INPUT); //set echoPin as INPUT
    
    for(;;) {
        digitalWrite(trigPin, LOW);
        usleep(2);
        digitalWrite(trigPin, HIGH);
        usleep(20);
        digitalWrite(trigPin, LOW);
        
        while(digitalRead(echoPin) == LOW);
        
        startTime = micros();
        
        while(digitalRead(echoPin) == HIGH);
        travelTime = micros() - startTime;
        
        distance = travelTime / 58;
        
        printf("Distance: %dcm\n", distance);
        delay(200);
    }
}