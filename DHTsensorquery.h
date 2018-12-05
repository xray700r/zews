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

LMsensorquery Library for DHT 11 sensor querying functions 

These functions have the purpose of reading through the DHT object and DHT library the output pin of the DHT 11 
connected directrly to the Arduino Uno master.

Created by Moisi Xhaferaj, 05/03/2018.

*/


#ifndef DHTsensorquery_h
#define DHTsensorquery_h

#include "Arduino.h"
#include <dht.h>

void DHTsensorquery(int dhtpin, int dhtdelay, float &hum, float &temp);

#endif
