# ZEWS - ZEus Weather Station
## Documentation and Concept


### Description and purpose


The Zeus Weather Station (**ZEWS**) is an initiative of the 
"Harry Fultz Institute Open Source Club" to promote Open Source Software and Hardware 
and education on Weather Monitoring as a better implementation of the OSWS (Open Source Weather Station) project and data gathering from various sensors while containing the cost of the ZEWS on a limited budget.

The ZEWS is based on HW as Arduino UNO, Attiny85 and Raspberry Pi and software as the 
Arduino IDE, C/C++, Python. Operating systems as the Raspbian, CentOS, Arch.

The HW of the sensors is the only part that has been purchased as in the case of the:

1. LM 35 Linear Temperature sensor
- DHT 11 Humidity and Temperature sensor
- BMP180 Pressure and Temperature sensor
- LDR and IR diodes etc for light detection
- Hall effect sensor for the Anemometer
- Thermocouple for the Pyranometer


### The ZEWS Features:

**Version 1.0**

1. Anemometer: Wind speed and direction
- Thermometer: Temperature measurement
- Hygrometer: Humidity measurement
- Barometer: Atmospheric pressure measurement
- Lux-meter: Measurement of light 
- Pyranometer: Measurement of incident Sun radiation


### Who can build and use

ZEWS is easy to implement from everyone with intermediate knowledge on electronics.
The number of persons can speed up the process and knowledge on using Arduino IDE 
and programming Attiny85 with Arduino as ISP is a must. HW building is a limiting factor in this
project as the housing of the sensors and some of the sensors are completely DIY.


### HOW TO BUILD

This system is a simple sensor integration platform. All data is gathered on an Arduino UNO as a I2C Master.
All other sensors are either directly integrated on the Arduino UNO or hooked up on the I2C bus as slaves. 
Detailed instructions are uploaded on the GitHub repo.
