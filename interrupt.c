#include <stdio.h>
#include <stdlib.h> //exit함수를 사용하기 위함
#include <wiringPi.h>

#define INTERRUPT_GPIO 23
#define LED 24


void twinkle(void)
{
 static int i = 0; // static으로 선언하지 않아도 됩니다. 작성자는 twinkle함수가 자주 호출되기 때문에 static으로 선언하였습니다.

 printf("interrupt on !!\n");
 
 for (i = 0, digitalWrite(LED, 0); i < 5; i++)
 {
  digitalWrite(LED, 1);
  delay(1000);
  digitalWrite(LED, 0);
  delay(1000);
 }

}

int main(void)
{
 if (wiringPiSetupGpio() == -1)
 {
  fputs("wiringPiGpioSetup error occured\n", stderr);
  exit(1);
 }

 pinMode(INTERRUPT_GPIO, INPUT);
 pinMode(LED, OUTPUT); digitalWrite(LED, 0);

 if (wiringPiISR(INTERRUPT_GPIO, INT_EDGE_FALLING, twinkle) < 0)
 {
  {
   fputs("wiringPiISR error occured\n", stderr);
   exit(1);
  }
 }

 while (1)
  switch (waitForInterrupt(INTERRUPT_GPIO, 5000000))
  
 {
  case 2:
   fputs("Time Out\n", stderr);
   break;
  case -1:
   fputs("waitForInterrupt error occured\n", stderr);
   exit(1);
 }

 return 0;
}
