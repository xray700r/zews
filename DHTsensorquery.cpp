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

DHTsensorquery Library for DHT 11 sensor querying functions 

These functions have the purpose of reading through the DHT object and DHT library the output pin of the DHT 11 
connected directrly to the Arduino Uno master.

Created by Moisi Xhaferaj, 05/03/2018.

*/




#include "Arduino.h"

#include <dht.h>

#include <DHTsensorquery.h>

dht DHT; // declaring DHT sensor variable


void DHTsensorquery(int dhtpin, int dhtdelay, float &hum, float &temp){

int chk = DHT.read11(dhtpin); // reading from declared pin

//////DHT-11///////  
hum=DHT.humidity;
temp=DHT.temperature;

//String printstring =  "DHT-11 Temperature: "; 
//printstring = printstring + DHT.temperature + " C";

//printstring = printstring + " / " + "DHT-11 Humidity: " + DHT.humidity + " RH";


//Serial.print(printstring);



  delay(dhtdelay);

}
//////DHT-11///////

