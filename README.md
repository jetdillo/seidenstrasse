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
   Also keep in mind that most of this was thrown together on the last night of 31c3 between around 2300-0500. 
   There was a good bit of Mate,swearing and sleep-dep involved. You have been warned. 
 
   
  * That said, if you look closely, you can see some neat events. 
    * The first real recorded trip was in FLIGHT2.TXT. The initial noise is the capsule being taped up and stuffed in the tube. It was sent over the hardware assemblies towards the stage/ballpit area where it popped out out of the tube and landed in somebody's lap. I found him holding the sensor capsule and looking at it rather puzzled. 
    * At around 2500-4500 seconds in FLIGHT2.TXT is where the capsule went through the spiral in Saal4, got stuck for a minute or two and was eventually sucked out at the far end. 
    
  * The raw sensor data is scaled based on the [calibration procedure mentioned on the Adafruit page for the ADXL326 ](https://learn.adafruit.com/adafruit-analog-accelerometer-breakouts/programming).

## Future Work
   I'm not sure how much will be done here with this specific code/data. It was pretty much a one-off. Ideally
   the next revision would have things like a Gyro or proper IMU included so we could map the orientation as well as acceleration, etc.  I had a lot of fun throwing this together in a few hours. Maybe if I'm lucky enough, I'll be able to deploy an improved version at the 2015 Camp this summer.  
   
  I am going to work on a proper 3D-printable capsule with a solid platform that a sensor rig could be installed in, something that could contain a smaller Arduino-alike, the aforementioned IMU, perhaps a Wifi-scanner or other interesting bits of kit. Stay tuned. 

   
