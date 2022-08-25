#include <stdio.h>		// c언어 표준입출력 라이브러리
#include <wiringPi.h>	// 라즈베리파이에서 gpio 제어를 위한 라이브러리

#define RED_LED 23		// RED_LED의 + 극에 연결된 라즈베리파이 핀
#define YELLOW_LED 24	// YELLOW_LED의 + 극에 연결된 라즈베리파이 핀
#define GREEN_LED 25	// GREEN_LED의 + 극에 연결된 라즈베리파이 핀
#define BTN_PIN 13		// BUTTON에 연결된 라즈베리파이 핀

/** 함수 호출시 RED, YELLOW LED를 blink */
void on_off(int flag) {
	//controls red & yellow LED
	digitalWrite(RED_LED, flag);
	digitalWrite(YELLOW_LED, !flag);
}

/** 인터럽트 발생시 실행시킬 핸들러 함수 */
void btn_interrupt() {
	//interrupt function
	//turns on green LED
	printf("%s\n","Interrupt start");
	digitalWrite(GREEN_LED, HIGH);
	delay(4000);
	digitalWrite(GREEN_LED,LOW);
	printf("%s\n","Interrupt stop");
}


int main() {
	/*
	Example code for interrupt function of Raspberry Pi
	turns on green LED when there's input in interrupt pin
	*/
	int flag = 0;
	
	wiringPiSetupGpio();
	//uses broadcom pinmap
	
	/** LED에 연결된 각 핀들을 OUTPUT(출력) 모드로 설정 */
	pinMode(RED_LED, OUTPUT);
	pinMode(YELLOW_LED, OUTPUT);
	pinMode(GREEN_LED, OUTPUT);
	
	if(wiringPiISR(BTN_PIN,INT_EDGE_FALLING, &btn_interrupt)<0) {
		printf("%s\n","Interrupt setup fail");
	}

	for(;;) { // = while(1)
		on_off(flag);
		printf("%s\n","execute loop");
		delay(1000);
		flag = !flag;
	}
	
	return 0;
}


