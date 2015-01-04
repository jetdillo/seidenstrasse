seidenstrasse
=============

Stuff for the C^3 Seidenstrasse pneumatic tube project

Arduino code, gnuplot .plot files and raw accelerometer data collected from the datalogger capsule
I built for the 31c3 version of the "Seidenstrasse" pneumatic tube system.

## Usage/Requirements

You will need the Arduino SDCard library for the Adafruit datalogger shield.
A recent version of GNUplot for the .plot files.

## Notes

 * The data is pretty, but it's kind of hard to make any assumptions about what actually went on.
   The Arduino stack was secured inside the capsule by lots of bubble-wrap and electrical tape.
   It's entirely possible(in fact, almost certain) that it jostled around inside, shifted on its own axes, etc. 
   One person on Twitter (@exe) has already pointed out that he thinks the Y-Axis data is horribly off-scale.
   
   That said, if you look closely, you can see some neat events. At around 2500-4500 seconds is where the capsule went 
   through the spiral in Saal4, got stuck for a minute or two and was eventually sucked out at the far end. 
   
   The raw sensor data is scaled based on the [https://learn.adafruit.com/adafruit-analog-accelerometer-breakouts/programming][calibration procedure for the ADXL326 mentioned on the Adafruit page for the ADXL326 ] 
