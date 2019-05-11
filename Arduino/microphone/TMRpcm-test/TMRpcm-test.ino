#include <SD.h>                      // need to include the SD library
#include <SPI.h>
#include <TMRpcm.h>           //  also need to include this library...

#define SD_ChipSelectPin 14  //using digital pin 4 on arduino nano 328, can use other pins

TMRpcm audio;   // create an object for use in this sketch


void setup(){

  tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc

  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  tmrpcm.play("music"); //the sound file "music" will play each time the arduino powers up, or is reset
}



void loop(){  

  if(Serial.available()){    
    if(Serial.read() == 'p'){ //send the letter p over the serial monitor to start playback
      tmrpcm.play("music");
    }
  }

}
