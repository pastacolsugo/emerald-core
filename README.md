# miniature-happiness

WORK IN PROGRESS

Arduino based greenhouse
features double light control, temperature control (heater and cooler), humidity control (humidifier and dehumidifier).

This is the core software, it doesn't have hardware input and output interface yet, but it's built to implement it. 
it features a variable number of seasons to have different schedules throughout the year.
Every control is thought as on-off.

Lights: two separate channel are featured, day lights and dawn/dusk lights, intended to be placed at an angle.
Temperature: can choose between using air from inside and outside, air heater and cooler, with a double hysteresis control.
Humidity: air humidifier and dehumidifier, again with double hysteresis control.

It relies much on custom data structs.
Tried to reduce memory usage by wisely choose data types, 

Contact me for any info
ugobaroncini+minihapp@gmail.com

