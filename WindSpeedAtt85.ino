/*
Copyright (C) 2018  Rei Arifi

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>. 
    
    
    Author of modifications from original Rei Arifi, 21/06/2018.
    
    
    
    */
#define MAX_TICK  10000 // 120000

#define STATUS_PIN_1 2 // it was 4 the 2 is used to test attiny 84
#define ADC_PIN 3

#define LPF_FACTOR 0.5

#include <TinyWireS.h>
#include <avr/sleep.h>
#include <avr/wdt.h>

// also

#include <avr/interrupt.h>
#include <avr/power.h>


#ifndef TWI_RX_BUFFER_SIZE
#define TWI_RX_BUFFER_SIZE ( 16 )
#endif

unsigned int in, inc=0;
uint8_t ina = 0;
unsigned long tm = 0;
boolean lowt = false;


volatile uint8_t i2c_regs[] =
{
    0, //older 8
    0 //younger 8
};

volatile byte reg_position = 0;
const byte reg_size = sizeof(i2c_regs);


/**
 * This function is executed when there is a request to read sensor
 * To get data, 2 reads of 8 bits are required
 * First requests send 8 older bits of 16bit unsigned int
 * Second request send 8 lower bytes
 * Measurement is executed when request for first batch of data is requested
 */
void requestEvent()
{  
  TinyWireS.send(i2c_regs[reg_position]);

  reg_position++;
  if (reg_position >= reg_size)
  {
      reg_position = 0;
  }
}

void setup() {
  /*
   * Setup I2C
   */
  TinyWireS.begin(I2C_SLAVE_ADDRESS);
  TinyWireS.onRequest(requestEvent);

  /*
   * Set pins
   */
   pinMode(STATUS_PIN_1, OUTPUT);
  pinMode(ADC_PIN, INPUT); // funny enough Attiny85 has pin 6 I/O PWM digital read

   // get actual time in milliseconds and add 60 seconds to it

  /*
   * Start watchdog timer
   */
  //setup_watchdog(6);
}

unsigned int tick = 0;
unsigned long lastReadout = 0;

/*int smooth(int data, float filterVal, float smoothedVal){

  if (filterVal > 1){      // check to make sure params are within range
    filterVal = .99;
  }
  else if (filterVal <= 0){
    filterVal = 0;
  }

  smoothedVal = (data * (1 - filterVal)) + (smoothedVal  *  filterVal);

  return (int)smoothedVal;
}*/

void loop() {

tm = millis() + 10000;
inc=0;

 digitalWrite(STATUS_PIN_1, LOW);
  /*set_sleep_mode(SLEEP_MODE_ADC);
  sleep_enable();
  sleep_mode();
  sleep_disable(); */

  while(millis() <= tm)
 {
 ina = analogRead(ADC_PIN); // read from pin 2 analog input

if (ina>150)
{digitalWrite(STATUS_PIN_1, HIGH);
in=HIGH;
}
else
{digitalWrite(STATUS_PIN_1, LOW);
in=LOW;
}
 
 
 if(in == LOW and lowt == false)
 {
   
   lowt = !lowt;
  
 } 
 
 if(in == HIGH and lowt == true)
 {
   
   inc++;
   lowt = !lowt;
   
 }
 
    
}

/*if (inc>10)
{digitalWrite(STATUS_PIN_1, HIGH);}
else
{digitalWrite(STATUS_PIN_1, LOW);}*/


    uint8_t raw_value = inc; //analogRead(ADC_PIN);
    i2c_regs[0] = raw_value >> 8; // read second
    i2c_regs[1] = raw_value & 0xFF; // read first

     

  
}
