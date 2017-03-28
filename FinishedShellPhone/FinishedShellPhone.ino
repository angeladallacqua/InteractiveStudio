/* ONE TRACK WILL PLAY UPON SETUP
WHEN IT IS DONE
STARTS READING FROM THE ACCELEROMETER
*/

// This code is modified version of the Adafruit VS1053 Codec Breakout
// This code is modified version of the Adafruit LSM303DLHC


////////////////ACCEL
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>


//////////

#include <Adafruit_VS1053.h>
#include <SD.h>

// These are the pins used for the music maker shield
#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)

// These are common pins between breakout and shield
#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin


Adafruit_VS1053_FilePlayer musicPlayer = 
  // create shield-example object!
Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);

Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);

float heading;

int MUSIC;
boolean randomMUSIC;

  
void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit VS1053 Simple Test");

  if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  }
  Serial.println(F("VS1053 found"));
  
   if (!SD.begin(CARDCS)) {
    Serial.println(F("SD failed, or not present"));
    while (1);  // don't do anything more
   }
 
  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(1,1);

  // Timer interrupts are not suggested, better to use DREQ interrupt!
  //musicPlayer.useInterrupt(VS1053_FILEPLAYER_TIMER0_INT); // timer int

  // If DREQ is on an interrupt pin (on uno, #2 or #3) we can do background
  // audio playing
  //musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);  // DREQ int
  
  // Play one file, don't return until complete
 // Serial.println(F("Playing track 001"));
  //musicPlayer.playFullFile("track001.mp3");

  ///////accel
   /* Initialise the sensor */
  if(!mag.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }
  
}

void loop() {
  // File is playing in the background
  
if (musicPlayer.stopped()) {
Serial.println("music stopped");
if(heading > 230){
 MUSIC = int(random(1,15));


if(MUSIC==1){
    Serial.println(F("Playing track 001"));
  musicPlayer.playFullFile("track001.mp3");
}

if(MUSIC==2){
    Serial.println(F("Playing track 002"));
  musicPlayer.playFullFile("track002.mp3");
  Serial.write(MUSIC);
}

if(MUSIC==3){
    Serial.println(F("Playing track 003"));
  musicPlayer.playFullFile("track003.mp3");
  Serial.write(MUSIC);
}

if(MUSIC==4){
    Serial.println(F("Playing track 004"));
  musicPlayer.playFullFile("track004.mp3");
  Serial.write(MUSIC);
}
  if(MUSIC==5){
    Serial.println(F("Playing track 005"));
  musicPlayer.playFullFile("track005.mp3");
  Serial.write(MUSIC);
}
 if(MUSIC==6){
    Serial.println(F("Playing track 006"));
  musicPlayer.playFullFile("track006.mp3");
  Serial.write(MUSIC);
}
 if(MUSIC==7){
    Serial.println(F("Playing track 007"));
  musicPlayer.playFullFile("track007.mp3");
  Serial.write(MUSIC);
}
 if(MUSIC==8){
    Serial.println(F("Playing track 008"));
  musicPlayer.playFullFile("track008.mp3");
  Serial.write(MUSIC);
}
 if(MUSIC==9){
    Serial.println(F("Playing track 009"));
  musicPlayer.playFullFile("track009.mp3");
  Serial.write(MUSIC);
}
 if(MUSIC==10){
    Serial.println(F("Playing track 010"));
  musicPlayer.playFullFile("track010.mp3");
  Serial.write(MUSIC);
}
 if(MUSIC==11){
    Serial.println(F("Playing track 011"));
  musicPlayer.playFullFile("track011.mp3");
  Serial.write(MUSIC);
}
 if(MUSIC==12){
    Serial.println(F("Playing track 012"));
  musicPlayer.playFullFile("track012.mp3");
  Serial.write(MUSIC);
}
 if(MUSIC==13){
    Serial.println(F("Playing track 013"));
  musicPlayer.playFullFile("track013.mp3");
  Serial.write(MUSIC);
}
 if(MUSIC==14){
    Serial.println(F("Playing track 014"));
  musicPlayer.playFullFile("track014.mp3");
  Serial.write(MUSIC);
}
}
}
///////ACCEL
compass();
}

void compass(){
/* Get a new sensor event */ 
  sensors_event_t event; 
  mag.getEvent(&event);
  
  float Pi = 3.14159;
  
  // Calculate the angle of the vector y,x
 heading = (atan2(event.magnetic.y,event.magnetic.x) * 180) / Pi;
  
  // Normalize to 0-360
  if (heading < 0)
  {
    
    heading = 360 + heading;
  }
  Serial.print("Compass Heading: ");
  Serial.println(heading);
  delay(500);
}
