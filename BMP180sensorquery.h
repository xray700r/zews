/*

Copyright (C) 2018  Moisi Xhaferaj

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

BMP180sensorquery Library for BMP-180 querying functions 

These functions have the purpose of reading through the BMP-180 library the output of the sensor
connected through the I2C bus to the Arduino Uno master.

Created by Moisi Xhaferaj, 05/03/2018.

*/

#ifndef BMP180sensorquery_h
#define BMP180sensorquery_h

#include "Arduino.h"
#include <Wire.h>
#include <SFE_BMP180.h>

void BMP180sensorquery(SFE_BMP180 pressure, int bmp180delayt, float &altitude, float &abspress, float &relpress, float &temp);

#endif
