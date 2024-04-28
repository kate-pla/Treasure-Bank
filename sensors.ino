
#define led 7
#define sensor_pin A0
#include "SD.h"
#define SD_ChipSelectPin 53
#include "TMRpcm.h"
#include "SPI.h"
#define ledPin 12
#include <ezButton.h>
TMRpcm tmrpcm1;
ezButton button1(5);
int sensor;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(sensor_pin,INPUT);
  Serial.begin(9600);
  tmrpcm1.speakerPin=46;
  button1.setDebounceTime(50);
  
  //Checks if the SD card is working
  if(!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("SD fail");
    return;
  }
  if(SD.exists("test2.wav"))
  {
    Serial.println("File doesn't exist")
  }
  if(SD.exists("test4.wav"))
  {
    Serial.println("File doesn't exist")
  }
  tmrpcm1.setVolume(5);
  pinMode(ledPin,OUTPUT);
  
}
  


void loop() {
  // Gets the sensor value
  sensor = analogRead(sensor_pin);
  button1.loop();
  //Gets the button state
  int state = button1.getState();
  // When button is released the sound will start playing
  if(button1.isReleased())
  {
    Serial.println("pressed");

    tmrpcm1.play("test2.wav");
    // Make sures the sound doesn't stop in the middle
    while(tmrpcm1.isPlaying())
    {
      digitalWrite(ledPin,HIGH);
    }
    // Stops the sound from continuing playing
    if(tmrpcm1.isPlaying())
    {
      tmrpcm1.stopPlayback();
    }
  }
  // Detects when the coins are inserted
  // If the light detection is greater than 300 than that means there is no coin that was inserted
  if(sensor<300)
  {
    digitalWrite(led,LOW);
  }
  else
  {
    // Since the light detection was less than 300 that means a coin was insereted
    // Sound will start playing and light will turn on
    
    tmrpcm1.play("test4.wav");
    while(tmrpcm1.isPlaying())
    {
      digitalWrite(led,HIGH);
    }
    tmrpcm1.stopPlayback();
  
  }
}
