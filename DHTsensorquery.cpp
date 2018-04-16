/*

DHTsensorquery Library for DHT 11 sensor querying functions 

These functions have the purpose of reading through the DHT object and DHT library the output pin of the DHT 11 
connected directrly to the Arduino Uno master.

Created by Moisi Xhaferaj, 05/03/2018.
Released into the public domain under CC 3.0.

*/




#include "Arduino.h"

#include <dht.h>

#include <DHTsensorquery.h>

dht DHT;


void DHTsensorquery(int dhtpin, int dhtdelay, float &hum, float &temp){

int chk = DHT.read11(dhtpin);

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

