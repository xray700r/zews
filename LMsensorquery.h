/*

LMsensorquery Library for LM 35 sensor reading functions 

These functions have the purpose of reading through an analogRead the output pin of the LM 35 
connected directrly to the Arduino Uno master.

Created by Moisi Xhaferaj, 05/03/2018.
Released into the public domain under CC 3.0.

*/

#ifndef LMsensorquery_h
#define LMsensorquery_h

#include "Arduino.h"

void LMsensorquery(int lmpin, int lmdelay, float &temp);

#endif
