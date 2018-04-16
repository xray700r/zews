/*

AT85sensorquery Library for I2C sensors, based on ATTINY-85, querying functions 

These functions have the purpose of reading through the ATTINY-85 library the 10 bit output pin of the Pin2 analogread of the attiny85 connected through the I2C bus to the Arduino Uno master.

Created by Moisi Xhaferaj, 05/03/2018.
Released into the public domain.

*/

#ifndef AT85sensorquery_h
#define AT85sensorquery_h

#include "Arduino.h"
#include <Wire.h>

void AT85sensorquery(unsigned char slaveaddr, int at85delayt, unsigned int &level);

#endif
