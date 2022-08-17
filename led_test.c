#include <stdio.h>
#include <wiringPi.h>

#define LED 1
#define SWITCH 4

int main()
{
	if(wiringPiSetup() == -1)
		return -1;
		
	// Gpio Mode Setting
	pinMode(LED, OUTPUT);
	pinMode(SWITCH, OUTPUT);
	
	while(1)
	{
		if(digitalRead(SWITCH) == HIGH)
		{
			printf("Button was pressed\n");
			digitalWrite(LED, HIGH);
		}
		else
		{
			printf("Button was Not pressed\n");
			digitalWrite(LED, LOW);
		}
		delay(1000);
	}
	return 0;
}


