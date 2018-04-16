/*

LMsensorquery Library for LM 35 sensor reading functions 

These functions have the purpose of reading through an analogRead the output pin of the LM 35 
connected directrly to the Arduino Uno master.

Created by Moisi Xhaferaj, 05/03/2018.
Released into the public domain under CC 3.0.

*/




#include "Arduino.h"
#include <LMsensorquery.h>

//////LM-35///////
void LMsensorquery(int lmpin, int lmdelay, float &temp){

int reading;

reading = analogRead(lmpin);
float millivolt = ( reading/1024.0)*5000;
float celsius = millivolt/10;

temp=celsius;

//String printstring =  "LM35 TEMPRATURE: "; 
//printstring = printstring + celsius + " C";

//Serial.print(printstring);



delay(lmdelay);
}

/////LM-35///////

