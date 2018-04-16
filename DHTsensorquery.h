/*

LMsensorquery Library for DHT 11 sensor querying functions 

These functions have the purpose of reading through the DHT object and DHT library the output pin of the DHT 11 
connected directrly to the Arduino Uno master.

Created by Moisi Xhaferaj, 05/03/2018.
Released into the public domain under CC 3.0.

*/


#ifndef DHTsensorquery_h
#define DHTsensorquery_h

#include "Arduino.h"
#include <dht.h>

void DHTsensorquery(int dhtpin, int dhtdelay, float &hum, float &temp);

#endif
