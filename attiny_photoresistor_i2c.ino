/* 

Code for the OSWS Light sensor slave 

This function calls have the purpose of reading the output of the LDR
connected through the analog port and on request send data over I2C to the Arduino Uno master.

Author Moisi Xhaferaj, 29/02/2018.
Released into the public domain under CC 3.0.

Original Code Light Sensor on Attiny 85 found at the following source:

Attiny photoresistor i2c:

https://github.com/DzikuVx/attiny_photoresistor_i2c

*/


#include <TinyWireS.h>
//#include <usiTwiSlave.h>

/*
 * Set I2C Slave address. You can have multiple sensors with different addresses
 */
#define I2C_SLAVE_ADDRESS 0x13

/*
 * How often measurement should be executed
 * One tick is more less 0.5s, so 1 minute is 120 ticks
 * This executes measurements every 2 minutes, so 120s, 120000 ms
 */
#define MAX_TICK  10000 // 120000

#define STATUS_PIN_1 4
#define ADC_PIN 3

#define LPF_FACTOR 0.5

//#include <TinyWireS.h>
//#include <avr/sleep.h>
//#include <avr/wdt.h>




#ifndef TWI_RX_BUFFER_SIZE
#define TWI_RX_BUFFER_SIZE ( 16 )
#endif

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
  TinyWireS.send(0);//i2c_regs[reg_position]);

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
  pinMode(ADC_PIN, INPUT);


}

unsigned int tick = 0;
unsigned long lastReadout = 0;

int smooth(int data, float filterVal, float smoothedVal){

  if (filterVal > 1){      // check to make sure params are within range
    filterVal = .99;
  }
  else if (filterVal <= 0){
    filterVal = 0;
  }

  smoothedVal = (data * (1 - filterVal)) + (smoothedVal  *  filterVal);

  return (int)smoothedVal;
}

void loop() {

//  set_sleep_mode(SLEEP_MODE_PWR_SAVE);
//  sleep_enable();
//  sleep_mode();
//  sleep_disable(); 

int lightMeter = 0;

  unsigned long currentMillis = millis();
  /*
   * On tick value 0, do measurements
   */
  //if (abs(currentMillis - lastReadout) > MAX_TICK) {
    uint8_t raw_value = analogRead(ADC_PIN);

    //lightMeter = raw_value;// smooth(raw_value, LPF_FACTOR, lightMeter);
    
    i2c_regs[0] = 0 >> 8; //lightMeter >> 8;
    i2c_regs[1] = 0; //lightMeter & 0xFF;
    
    digitalWrite(STATUS_PIN_1, HIGH);
    //lastReadout = currentMillis;
  //}
}
