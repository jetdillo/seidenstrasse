#include <SD.h>
#include <stdlib.h>
#include <string.h>
const int xInput = A0;
const int yInput = A1;
const int zInput = A2;

const int chipSelect = 10;

char datastr[30];

char accelx_str[8];
char accely_str[8];
char accelz_str[8];

// Raw Ranges:
// initialize to mid-range and allow calibration to
// find the minimum and maximum for each axis
int xRawMin = 318;
int xRawMax = 343;

int yRawMin = 318;
int yRawMax = 343;

int zRawMin = 318;
int zRawMax = 343;

// Take multiple samples to reduce noise
const int sampleSize = 10;

unsigned long base_ts=0;

void setup() 
{
  
  delay(5000);
  
  //analogReference(EXTERNAL);
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  base_ts=millis();
}

void loop() 
{
  unsigned long cur_ts=0;
  unsigned long flight_ts=0;
  
  int xRaw = ReadAxis(xInput);
  int yRaw = ReadAxis(yInput);
  int zRaw = ReadAxis(zInput);
   
    // Convert raw values to 'milli-Gs"
    long xScaled = map(xRaw, xRawMin, xRawMax, -1000, 1000);
    long yScaled = map(yRaw, yRawMin, yRawMax, -1000, 1000);
    long zScaled = map(zRaw, zRawMin, zRawMax, -1000, 1000);
  
    // re-scale to fractional Gs
    float xAccel = xScaled / 1000.0;
    float yAccel = yScaled / 1000.0;
    float zAccel = zScaled / 1000.0;
    
    cur_ts = millis();
    flight_ts= cur_ts-base_ts; 
  
    //Apparently the Arduino version of sprintf doesn't deal well with floats
    //So we cannot have nice things...
    
    sprintf(datastr,"%l:%d:%d:%d - ",flight_ts,xRaw,yRaw,zRaw);
    
    int accel_strpos=(strlen(datastr))+1;
    
    dtostrf(xAccel,2,3,&datastr[accel_strpos]);
    datastr[accel_strpos+7]=':';
    dtostrf(yAccel,2,3,&datastr[accel_strpos+8]);
    datastr[accel_strpos+15]=':';
    dtostrf(zAccel,2,3,&datastr[accel_strpos+22]);
    
    Serial.println(datastr);
    
    /*
    datastr += ":";
    datastr +=xAccel;
    datastr += ":";
    datastr +=String(yAccel);
    datastr += ":";
    datastr +=String(zAccel);
    */
    
    File dataFile = SD.open("FLIGHT.TXT", FILE_WRITE);
    if (dataFile) {
    dataFile.println(datastr);
    dataFile.close();
    // print to the serial port too:
    Serial.println(datastr);
    
   //datastr="";
   memset(datastr,0,30);
    
    
    }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening mission_log.txt");
  } 
  
  delay(250);
}

//
// Read "sampleSize" samples and report the average
//
int ReadAxis(int axisPin)
{
  long reading = 0;
  analogRead(axisPin);
  delay(1);
  for (int i = 0; i < sampleSize; i++)
  {
    reading += analogRead(axisPin);
  }
  return reading/sampleSize;
}

