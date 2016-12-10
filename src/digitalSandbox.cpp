/****************************************************************
Main CPP for digitalSandbox. 

08 Dec 2016- Brian Huang, SparkFun Electronics
Code developed in Arduino 1.6.12, on an SparkFun DigitalSandbox v1
****************************************************************/

#include "digitalSandbox.h"
#include <avr/interrupt.h>
#include <Arduino.h>

digitalSandbox::digitalSandbox()
{
  for(int x=4; x<=11; x++)
	  pinMode(x, OUTPUT); 
  pinMode(13, OUTPUT);
//  Serial.begin(9600);
}

// sets the state of all 8 LEDs
void digitalSandbox::leds(byte d4_state, byte d5_state, byte d6_state, byte d7_state, byte d8_state) 
{
  digitalWrite(4, d4_state);
  digitalWrite(5, d5_state);
  digitalWrite(6, d6_state);
  digitalWrite(7, d7_state);
  digitalWrite(8, d8_state);
}

void digitalSandbox::setRGB(byte _red, byte _green, byte _blue)
{
  analogWrite(9, _red);
  analogWrite(10, _green);
  analogWrite(11, _blue);
}

void digitalSandbox::setRGB(byte _red, byte _green, byte _blue, unsigned int _timeDelay)
{
  analogWrite(9, _red);
  analogWrite(10, _green);
  analogWrite(11, _blue);
  delay(_timeDelay);
}

void digitalSandbox::LEDon(byte _pin)
{
	digitalWrite(_pin, HIGH);
}

void digitalSandbox::LEDoff(byte _pin)
{
	digitalWrite(_pin, LOW);
}	

void digitalSandbox::LEDon(byte _pin, unsigned int _timeDelay)
{
	digitalWrite(_pin, HIGH);
	delay(_timeDelay);
}

void digitalSandbox::LEDoff(byte _pin, unsigned int _timeDelay)
{
	digitalWrite(_pin, LOW);
	delay(_timeDelay);
}	

void digitalSandbox::blink(byte _pin)
{
	digitalWrite(_pin, HIGH);
	delay(500);
	digitalWrite(_pin, LOW);
	delay(500);
}	

void digitalSandbox::blink(byte _pin, unsigned int _timeDelay)
{
	digitalWrite(_pin, HIGH);
	delay(_timeDelay);
	digitalWrite(_pin, LOW);
	delay(_timeDelay);	
}

unsigned int digitalSandbox::readSlider()
{
	return analogRead(SLIDER);
}
unsigned int digitalSandbox::readSound()
{
	return analogRead(SOUND);
}
unsigned int digitalSandbox::readLight()
{
	return analogRead(LIGHT);
}
float digitalSandbox::readTemp()
{   
    // returns the voltage in degrees C
	float voltage = analogRead(TEMP) * AREF;
	voltage /= 1023.0;
	return (voltage - 0.5)*100;
}
boolean digitalSandbox::readButton()
{
	return digitalRead(BUTTON);
}
boolean digitalSandbox::readSwitch()
{
	return digitalRead(SWITCH);
}