# User GUIDE

# Software

[Download Arduino IDE](https://www.arduino.cc/en/software)

# Hardware

**First Arduino**
- LCD Screen
- 8 buttons
- Bread board
- Male to Female wires

**Second Arduino**
- Photoresistor
- Transistor
- 8ohm 3w speaker
- SD card Module
- Yellow LED
- Red LED
- Male to Female Wires

**Libraries**

Sound and Lights
- SPI.h
- SD.h
- TMRPCM.h

LCD and Buttons
- LiquidCrystal.h

# Wiring Diagrams 

**LCD and Buttons**
![image](https://github.com/kate-pla/Treasure-Bank/assets/115516204/b945e4e9-b974-4937-9952-4acbec144eda)

The wiring diagram doesn't represent exactly the same wiring as used in my code. If you do not want to use a potentiometer you can connect the VO to a digital pin. Then you are able to adjust the contrast in the code. 

**Sound and Lights**
![image](https://github.com/kate-pla/Treasure-Bank/assets/115516204/ea561403-a25d-4ec0-8ddc-f5e25a807caf)

# LCD and Buttons Steps
For the LCD and Buttons once you have finished wiring them you will then you need to go to the code and make sure that the pin values match your wiring. Once that is ready you can put the code into the arduino using the USB cabel. Now once that is done the LCD and Buttons should be functioning. There can be times where the LCD might display random characters. If that happens check the all of the wires are correct and that there is no loose wires. If that doesn't work it could be something with the breadboard. I would try switiching out the breadboard. If the buttons adds mutliple values at one time then you would need to adjust the delay. The way it should be working is that everytime you push one of the buttons a certain value is added to the total amount and the displayed on the LCD screen.  

# Sound and Lights Steps
Once you have finished wiring the sd card module, speaker, lights, and the micro you can start working on the code and making sure that the pin values match your wiring. Once that is ready you put the code into the arduino using the usb cabel. If that sound is not loud enough you would need to use a transistor as a way of amplyfing the sound. If it says that the SD card is not found it could be that the wiring is wrong. You would need to check and make sure that the wiring is correct. The light sensor value would need to be adjust according to the light that is in the room. The way it should be working is that everytime an object the light value would change and the sound would start playing and the red LED would turn on. When the micro switch is pressed and then released then the next sound would start playing and the yellow LED light would turn on. 

**SD Card Steps**

In order to add a file to the SD card you need to take these steps:
- First you need to choose a sound file you want
- Second you would need to convert the file to a wav file using these website (https://audio.online-convert.com/convert-to-wav)
- Third you would set the parameters to 8 bit resolution, 16000hz for the audio frequency, mono for the audio channels, and U8 for the PCM format
- Fourth after you have converted the file you would need to download the SD formatter
- Fifth you would connect the SD card to your computer and open the SD formatter
- Sixth you would select the drive and click on format.
- Seventh you would add your file to the drive you selected for the SD card
- Eigth you would remove the SD card from your computer and add it to the SD card Module




  
  
