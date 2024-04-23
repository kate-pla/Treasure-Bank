
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
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(sensor_pin,INPUT);
  Serial.begin(9600);
  tmrpcm1.speakerPin=46;
  button1.setDebounceTime(50);


  if(!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("SD fail");
    return;
  }
  tmrpcm1.setVolume(5);
  pinMode(ledPin,OUTPUT);
}
  


void loop() {
  // put your main code here, to run repeatedly:
  sensor = analogRead(sensor_pin);
  //Serial.println(sensor);
  button1.loop();
  int state = button1.getState();
  
  if(button1.isReleased())
  {
    Serial.println("pressed");
    
    if(SD.exists("test2.wav"))
    {
  
      tmrpcm1.play("test2.wav");
      while(tmrpcm1.isPlaying())
    {
      digitalWrite(ledPin,HIGH);
    }
    }
    if(tmrpcm1.isPlaying())
    {
      tmrpcm1.stopPlayback();
    }
  }
  
  if(sensor<300)
  {
    digitalWrite(led,LOW);
  }
  else
  {


    if(SD.exists("test4.wav"))
    {
  
      tmrpcm1.play("test4.wav");
      while(tmrpcm1.isPlaying())
    {
      digitalWrite(led,HIGH);
    }
    tmrpcm1.stopPlayback();
  }
  }
}
