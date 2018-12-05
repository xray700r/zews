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

/////////////Simple function for reading an I2C LDR sensor 


#include "Arduino.h"

#include <Wire.h>

#include <AT85sensorquery.h>


//////ATTINY-85///////

void AT85sensorquery(unsigned char slaveaddr, int at85delayt, unsigned int &level){



  
Wire.requestFrom(slaveaddr, 2);    // request 2 bytes from slave device #0x13

int i =0;
unsigned int readout = 0;

//Serial.print("Ready\n");


while (Wire.available()) { // slave may send less than requested
byte c = Wire.read(); // receive a byte as character

//delay(200);

//Serial.print("\n Byte c is:\n");

//Serial.print(c);



if (i == 0) {
    readout = c;
} else {
    readout = readout << 8;
    readout = readout + c;
}

i++;
  
}





if (readout > 255) {
level=readout;
}
else {
  
level=0;

}

/*String printstring =  "\nReadout for sensor: "; 
printstring = printstring + readout + " ADC\n";


Serial.print(printstring);*/



delay(at85delayt);


}


//////ATTINY-85///////

