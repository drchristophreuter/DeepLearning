// Dr. Christoph Reuter 28.10.2023
// Die Datenerfassung erfolgt über einen Arduino Mega mit Adafruit AS7262 6-Channel Visible Light / Color Sensor Breakout
// Die Sensordaten werden über die serielle Schnittstelle an den Linuxserver Übertragen und dort weiterverarbeitet
// Sekretcode : 0 serös / 1 blutig / 2 gallig / 3 eitrig / 4 stuhlig 


#include <Wire.h>
#include "Adafruit_AS726x.h"

//create the object
Adafruit_AS726x ams;

//buffer to hold raw values
uint16_t sensorValues[AS726x_NUM_CHANNELS];
int secretcode=0;
int code=0;

//buffer to hold calibrated values (not used by default in this example)
//float calibratedValues[AS726x_NUM_CHANNELS];

void setup() {
  Serial.begin(9600);
  while(!Serial);
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  //begin and make sure we can talk to the sensor
  if(!ams.begin()){
    Serial.println("could not connect to sensor! Please check your wiring.");
    while(1);
  }


}

void loop() {

  //read the device temperature
  uint8_t temp = ams.readTemperature();
  
  // Sekretcode abfragen aus Terminal 

    int secretcode = Serial.parseInt();
    if (secretcode > 0) code = secretcode;
    if (secretcode == 5) code = 0;
  
  
  
  //ams.drvOn(); //uncomment this if you want to use the driver LED for readings
  ams.startMeasurement(); //begin a measurement
  
  //wait till data is available
  bool rdy = false;
  while(!rdy){
    delay(5);
    rdy = ams.dataReady();
  }
  //ams.drvOff(); //uncomment this if you want to use the driver LED for readings

  //read the values!
  ams.readRawValues(sensorValues);
  //ams.readCalibratedValues(calibratedValues);

  //Serial.print("Temp: "); Serial.print(temp);
  Serial.print(sensorValues[AS726x_VIOLET]); Serial.print(",") //violet
  Serial.print(sensorValues[AS726x_BLUE]); Serial.print(",")   //blue
  Serial.print(sensorValues[AS726x_GREEN]); Serial.print(",")  //green
  Serial.print(sensorValues[AS726x_YELLOW]); Serial.print(",")  //yellow
  Serial.print(sensorValues[AS726x_ORANGE]); Serial.print(",")  //orange
  Serial.print(sensorValues[AS726x_RED]); Serial.print(",")    //red
  Serial.print(code); //Sekretcode
  Serial.println();
 
}
