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

LMsensorquery Library for LM 35 sensor reading functions 

These functions have the purpose of reading through an analogRead the output pin of the LM 35 
connected directrly to the Arduino Uno master.

Created by Moisi Xhaferaj, 05/03/2018.

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

