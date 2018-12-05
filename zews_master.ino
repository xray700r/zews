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

Code for the OSWS Arduino UNO Master 

These function calls have the purpose of reading the output of the sensors
connected through the I2C bus or direvtly to the Arduino Uno master.

Created by Moisi Xhaferaj, 05/03/2018.

Part of the original code from:
SFE_BMP180 library example sketch
V10 Mike Grusin, SparkFun Electronics 10/24/2013
V1.1.2 Updates for Arduino 1.6.4 5/2015

and

https://github.com/DzikuVx/attiny_photoresistor_i2c

*/

#include <Wire.h>

#include <LMsensorquery.h>

#include <DHTsensorquery.h>

#include <SFE_BMP180.h>

#include <dht.h>

#include <AT85sensorquery.h>

#include <BMP180sensorquery.h>


#define DHT11_PIN 7

int tempPin = 1;

#define I2C_SLAVE1 0x13 //luminance level 10 bit

#define I2C_SLAVE2 0x08 //radiated powerlevel

// You will need to create an SFE_BMP180 object, here called "pressure":

SFE_BMP180 pressure;





 
void setup()
{
 Wire.begin(); // join i2c bus (address optional for master)
 Serial.begin(9600); // start serial for output
 Serial.println("REBOOT");

  // Initialize the sensor (it is important to get calibration values stored on the device).

  if (pressure.begin())
    Serial.println("BMP180 init success");
  else
  {
    // Oops, something went wrong, this is usually a connection problem,
    // see the comments at the top of this sketch for the proper connections.

    Serial.println("BMP180 init fail\n\n");
    while(1); // Pause forever.
  }
}
 
void loop()
{


float lm35temp=0;
float dht11temp=0;
float dht11hum=0;
unsigned int luminance=0, irradiatedpower=0, WindSpeed=0, WindDir=0;

float bmp180abspress=0;
float bmp180relpress=0;
float bmp180temp=0;
float bmp180altitude=103;

AT85sensorquery(I2C_SLAVE1, 2000, luminance);

AT85sensorquery(I2C_SLAVE2, 2000, irradiatedpower);

DHTsensorquery(DHT11_PIN, 3000, dht11hum, dht11temp);

LMsensorquery(tempPin, 3000, lm35temp);

BMP180sensorquery(pressure, 2000, bmp180altitude, bmp180abspress, bmp180relpress, bmp180temp);


String stringColumns = "TemperatureLM35, TemperatureDHT11, TemperatureBMP180, HumidityDHT11, PessureBMP180abs, PessureBMP180rel, WindSpeed, WindDir, Luminance, IrradiatedPower; ";

String stringOut = "*";

stringOut = stringOut + lm35temp + "," + dht11temp + "," + bmp180temp + "," + dht11hum + "," + bmp180abspress + "," + bmp180relpress + "," + WindSpeed + "," + WindDir + "," + luminance + "," + irradiatedpower + ";";



Serial.println();
  Serial.print(stringColumns);

Serial.println();
  Serial.print(stringOut);

Serial.println();
 


delay(1000);  // Pause for 1 seconds.


}


