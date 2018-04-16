/*

BMP180sensorquery Library for BMP-180 querying functions 

These functions have the purpose of reading through the BMP-180 library the output of the sensor
connected through the I2C bus to the Arduino Uno master.

Created by Moisi Xhaferaj, 05/03/2018.
Released into the public domain under CC 3.0.

*/

#ifndef BMP180sensorquery_h
#define BMP180sensorquery_h

#include "Arduino.h"
#include <Wire.h>
#include <SFE_BMP180.h>

void BMP180sensorquery(SFE_BMP180 pressure, int bmp180delayt, float &altitude, float &abspress, float &relpress, float &temp);

#endif
