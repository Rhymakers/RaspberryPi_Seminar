#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define PWM_PIN 8 //RPi physical pin 3, BCM pin 2

int main() {
    /*
    Example code for softPWM (wiringPi PWM library)
    connect pwm controlled component's pwm control cable to Raspberry Pi's wiringPi pin 8
    */
    wiringPiSetup();

    pinMode(PWM_PIN, OUTPUT);

    softPwmCreate(PWM_PIN, 0, 100);
    //initializing softPwm on pin "PWM_PIN" with initial value of 0 and pwm range of 100

    while(1) {
        softPwmWrite(PWM_PIN, 50);
        //now PWM_PIN will output 50% of 3.3v

        delay(30);

        softPwmWrite(PWM_PIN, 100);
        //now PWM_PIN will output 100% of 3.3v
        
        delay(30);

        softPwmWrite(PWM_PIN, 50);

        delay(30);

        softPwmWrite(PWM_PIN, 0);

        delay(30);
    }
    
    return 0;
}