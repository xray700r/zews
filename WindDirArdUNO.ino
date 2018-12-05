/*

Copyright (C) 2018  Rei Arifi

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

	Created by Rei Arifi, 21/06/2018.

*/

#define I2C_SLAVE_ADDRESS 0x04

#include <Wire.h>


#ifndef TWI_RX_BUFFER_SIZE
#define TWI_RX_BUFFER_SIZE ( 16 )
#endif

uint8_t dir = -1;

void requestEvent()
{ 
  Wire.write(dir);
}

void setup() {
  Wire.begin(I2C_SLAVE_ADDRESS);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(A0, INPUT);
}

unsigned int tick = 0;
unsigned long lastReadout = 0;


void loop() {
  Serial.println("Start");
 
  if(digitalRead(2) == HIGH)// and analogRead(A0) > 500)
  {
    dir =  1;
  }
  //else
  //{
  //  Serial.println("Error");
  //  dir = -1;
  //}

  if(digitalRead(3) == HIGH)
  {
    dir =  2;
  }

  if(digitalRead(4) == HIGH)
  {
    dir =  3;
  }

  if(digitalRead(5) == HIGH)
  {
    dir =  4;
  }

  if(digitalRead(6) == HIGH)
  {
    dir =  5;
  }

  if(digitalRead(7) == HIGH)
  {
    dir =  6;
  }

  if(digitalRead(8) == HIGH)
  {
    dir =  7;
  }

  if(digitalRead(9) == HIGH)// and digitalRead(A0) < 500)
  {
    dir =  8;
  }
  //else
  //{
  //  Serial.println("Error");
  //  dir = -1;
  //}

  Serial.println(dir);
  delay(500);
}
