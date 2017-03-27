// This code is modified version of the Adafruit VS1053 Codec Breakout
// This code is modified version of the Adafruit LSM303DLHC


#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>

#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>
#define SHIELD_RESET  -1      
#define SHIELD_CS     7      
#define SHIELD_DCS    6      
#define CARDCS 4     
#define DREQ 3       

Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);


Adafruit_VS1053_FilePlayer musicPlayer = 
Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);

void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Adafruit VS1053 Simple Test");
 
  if(!mag.begin())
  {
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }

if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  }
  Serial.println(F("VS1053 found"));
  
   if (!SD.begin(CARDCS)) {
    Serial.println(F("SD failed, or not present"));
    while (1);  // don't do anything more
  }

  musicPlayer.setVolume(1,20);


  Serial.println(F("Playing track 001"));
  musicPlayer.playFullFile("track001.mp3");

 Serial.println(F("Playing track 002"));
 musicPlayer.playFullFile("track002.mp3");

 Serial.println(F("Playing track 003"));
 musicPlayer.playFullFile("track003.mp3");
 
  Serial.println(F("Playing track 004"));
  musicPlayer.playFullFile("track004.mp3");

   Serial.println(F("Playing track 005"));
  musicPlayer.playFullFile("track005.mp3");

   Serial.println(F("Playing track 006"));
  musicPlayer.playFullFile("track006.mp3");

   Serial.println(F("Playing track 007"));
  musicPlayer.playFullFile("track007.mp3");

   Serial.println(F("Playing track 008"));
  musicPlayer.playFullFile("track008.mp3");

}


void loop(void) {
  sensors_event_t event; 
  mag.getEvent(&event);
  
  float Pi = 3.14159;
  
  float heading = (atan2(event.magnetic.y,event.magnetic.x) * 180) / Pi;
 
  if (heading < 0) {
    heading = 360 + heading;
  }
  Serial.print("Compass Heading: ");
  Serial.println(heading);
  delay(500);
  
//////

  if (musicPlayer.stopped()) {
    Serial.println("Done playing music");
    while (1);
  }
  if (Serial.available()) {
    char c = Serial.read();
    
    // if we get an 's' on the serial console, stop!
    if (c == 's') {
      musicPlayer.stopPlaying();
    }
    
    // if we get an 'p' on the serial console, pause/unpause!
    if (c == 'p') {
      if (! musicPlayer.paused()) {
        Serial.println("Paused");
        musicPlayer.pausePlaying(true);
      } else { 
        Serial.println("Resumed");
        musicPlayer.pausePlaying(false);
      }
    }
  }

  delay(100);
}

void printDirectory(File dir, int numTabs) {
   while(true) {
     
     File entry =  dir.openNextFile();
     if (! entry) {
       //no more files
       Serial.println("**nomorefiles**");
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
}
