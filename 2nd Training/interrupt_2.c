#include <stdio.h>
#include <wiringPi.h>

#define RED_LED 23
#define YELLOW_LED 24
#define GREEN_LED 25
#define BTN_PIN 13

void on_off(int flag)
{
	digitalWrite(RED_LED, flag);
	digitalWrite(YELLOW_LED, !flag);
}

void btn_interrupt()
{
	printf("%s\n","Interrupt start");
	digitalWrite(GREEN_LED, HIGH);
	delay(4000);
	digitalWrite(GREEN_LED,LOW);
	printf("%s\n","Interrupt stop");
}


int main()
{
	int flag = 0;
	
	wiringPiSetupGpio();
	
	pinMode(RED_LED, OUTPUT);
	pinMode(YELLOW_LED, OUTPUT);
	pinMode(GREEN_LED, OUTPUT);
	
	if(wiringPiISR(BTN_PIN,INT_EDGE_FALLING, &btn_interrupt)<0)
	{
		printf("%s\n","Interrupt setup fail");
	}
	for(;;)
	{
		on_off(flag);
		printf("%s\n","execute loop");
		delay(1000);
		flag = !flag;
	}
	return 0;
}


