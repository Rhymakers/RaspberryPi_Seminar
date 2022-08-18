#include <stdio.h>
#include <wiringPi.h>

#define PIRpin 7

int main() {
    /*
    Example code for PIR sensor
    When PIR sensor detects something, this code outputs result as console output
    */
    wiringPiSetup();

    pinMode(PIRpin, INPUT);

    for (;;) {
        //PIR sensor returns result as 1 (HIGH) & 0 (LOW)
        if (digitalRead(PIRpin) == HIGH) {
            printf("Detected\n");

            delay(30000);
        }
        else if (digitalRead(PIRpin) == LOW) {
            printf("Not Detected\n");

            delay(30000);
        }
        else {
            printf("Error\n");
            break;
        }
    }

    return 0;
}