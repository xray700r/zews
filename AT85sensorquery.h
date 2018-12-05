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

AT85sensorquery Library for I2C sensors, based on ATTINY-85, querying functions 

These functions have the purpose of reading through the ATTINY-85 library the 10 bit output pin of the Pin2 analogread of the attiny85 connected through the I2C bus to the Arduino Uno master.

Created by Moisi Xhaferaj, 05/03/2018.

*/

#ifndef AT85sensorquery_h
#define AT85sensorquery_h

#include "Arduino.h"
#include <Wire.h>

void AT85sensorquery(unsigned char slaveaddr, int at85delayt, unsigned int &level);

#endif
