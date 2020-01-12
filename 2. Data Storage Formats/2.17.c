// 2.17 Accessing the GPIO in C
// Uses the wiringPi lib to blink an LED.
// LED is connected to pin 11 of the RPi (GPIO 0) with a 220R resistor in series.
// 2020-01-12: Bruno Silvano Costa

#include <stdio.h>

#include <wiringPi.h>

#define LED_PIN 0


int main(void)
{
  if (wiringPiSetup() == -1)
  {
    printf("Unable to setup wiringPi\n");
    return 1;
  }

  pinMode(LED_PIN, OUTPUT);

  while(1) {
    digitalWrite(LED_PIN, LOW);
    delay(500);
    digitalWrite(LED_PIN, HIGH);
    delay(500);
  }

  return 0;
}
