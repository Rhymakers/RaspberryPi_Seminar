#include <stdio.h>      // c언어 표준입출력 라이브러리
#include <wiringPi.h>   // 라즈베리파이에서 gpio 제어를 위한 라이브러리
#include <unistd.h>     // 윈도우 환경에서 Windows.h 처럼 POSIX(=리눅스)운영 체제 API에 대한 엑세스를 제공하는 라이브러리

#define trigPin 1       // 초음파 센서의 trigPin 에 연결된 라즈베리파이 핀 wpi 1(= Physical 12)
#define echoPin 29      // 초음파 센서의 echoPin 에 연결된 라즈베리파이 핀 wpi 29(= Physical 29)
 
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
        
    pinMode (trigPin, OUTPUT);  //set trigPin as OUTPUT
    pinMode (echoPin, INPUT);   //set echoPin as INPUT
    
    for(;;) { // = while(1)
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