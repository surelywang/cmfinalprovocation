/*
Steps:
1. Edit pcmConfig.h
    a: On Uno or non-mega boards, #define buffSize 128. May need to increase.
    b: Uncomment #define ENABLE_RECORDING and #define BLOCK_COUNT 10000UL

2. Usage is as below. See https://github.com/TMRh20/TMRpcm/wiki/Advanced-Features#wiki-recording-audio for
   additional informaiton.
*/

#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>
#define SD_ChipSelectPin 10

TMRpcm audio;
TMRpcm tmrpcm;   // create an object for use in this sketch

int audiofile = 0;
unsigned long i = 0;
bool recmode = 0;
int buttonState;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flicker


void setup() {
//  pinMode(14, INPUT);
  tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc
  pinMode(6, OUTPUT);
  pinMode(2, INPUT_PULLUP);
//  attachInterrupt(digitalPinToInterrupt(2), button, RISING);
    Serial.begin(9600);

  if (!SD.begin(SD_ChipSelectPin)) {  
    Serial.println("SD NOT OK"); 
    return;
  }else{
    Serial.println("SD OK"); 
  }
  
  audio.CSPin = SD_ChipSelectPin;

}

void loop() {
  int reading = digitalRead(2);

  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
      Serial.println(buttonState);
      if(buttonState == 0){
        recmode = 0;
      }else{
        recmode = 1;
      }

      recordOnOff();
    }
  }

  lastButtonState = reading;

  if (SD.exists("file.wav")){
    playMusic();
    Serial.println("music shoudl be playing");
  }
}

void playMusic() {
  tmrpcm.play("file.wav"); 
}
void recordOnOff() {

  if (recmode == 0) {
    recmode = 1;
//  audiofile++;

//  RESET COUNTER IF MAX NUMBER OF TRACKS IS EXCEEDED    
//    if (audiofile >= 11) {
//      audiofile = 1;
//    };

    if (SD.exists("file.wav")) {
      SD.remove("file.wav");
    }
    
    digitalWrite(6, HIGH);
    audio.startRecording("file.wav", 16000, A0); 

    Serial.println("file recorded");
    
//  CODE FOR WRITING MULTIPLE TRACKS
//    switch (audiofile) {
//      case 1: audio.startRecording("1.wav", 16000, A0); 
//        Serial.println("startRecording was fired");
//      break;
//      case 2: audio.startRecording("2.wav", 16000, A0); break;
//      case 3: audio.startRecording("3.wav", 16000, A0); break;
//      case 4: audio.startRecording("4.wav", 16000, A0); break;
//      case 5: audio.startRecording("5.wav", 16000, A0); break;
//      case 6: audio.startRecording("6.wav", 16000, A0); break;
//      case 7: audio.startRecording("7.wav", 16000, A0); break;
//      case 8: audio.startRecording("8.wav", 16000, A0); break;
//      case 9: audio.startRecording("9.wav", 16000, A0); break;
//      case 10: audio.startRecording("10.wav", 16000, A0); break;
//    }
  }
  
  else {
    recmode = 0;

    digitalWrite(6, LOW);
    audio.stopRecording("file.wav");
    Serial.println("file saved"); 

//  CODE FOR SAVING MULTIPLE TRACKS
//    switch (audiofile) {
//      case 1: audio.stopRecording("1.wav"); 
//        Serial.println("stopRecording was fired");
//      break;
//      case 2: audio.stopRecording("2.wav"); break;
//      case 3: audio.stopRecording("3.wav"); break;
//      case 4: audio.stopRecording("4.wav"); break;
//      case 5: audio.stopRecording("5.wav"); break;
//      case 6: audio.stopRecording("6.wav"); break;
//      case 7: audio.stopRecording("7.wav"); break;
//      case 8: audio.stopRecording("8.wav"); break;
//      case 9: audio.stopRecording("9.wav"); break;
//      case 10: audio.stopRecording("10.wav"); break;
//    }
  }
}
