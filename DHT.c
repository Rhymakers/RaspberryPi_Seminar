#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define DHT_Pin 8

int data[5] = {0,};

void read_data() {
    int state = 1;
    int j = 0;
    int counter = 0;
    int i;

    pinMode(DHT_Pin, OUTPUT);
    digitalWrite(DHT_Pin, LOW);
    delay(18);

    pinMode(DHT_Pin, INPUT);

    for (i = 0; i < 85; i++) {
        while (digitalRead(DHT_Pin) == state) {
            counter++;
            delayMicroseconds(1);
            if (counter == 255) {
                break;
            }
        }

        state = digitalRead(DHT_Pin);

        if (counter == 255) {
            break;
        }

        if ((i >= 4) && (i % 2 == 0)) {
            data[j / 8] <<= 1;
            if (counter > 16) {
                data[j / 8] |= 1;
            }
            j++;
        }
    }

    if ((j >= 40) && (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF))) {
        printf("Humidity = %d.%d %% Temperature = %d.%d C\n", data[0], data[1], data[2], data[3]);
    }
    else {
        printf("Data error, skipping\n");
    }
}

int main() {
    /*
    Example code for DHT Humidity/Temperature sensor
    DHT sensor returns 40 bit data comprised of 16 bit of humidity, 16 bit of temperature, 8 bit of parity
    read_data() parses data and outputs as console output
    */
    wiringPiSetup();

    for (;;) {
        read_data();
        delay(2000);
    }

    return 0;
}