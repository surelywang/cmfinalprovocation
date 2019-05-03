
// IMPORTS
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// FEATHER SETUP
#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h"

#include "BluefruitConfig.h"
  
  #if SOFTWARE_SERIAL_AVAILABLE
    #include <SoftwareSerial.h>
  #endif
  
  /* ...hardware SPI, using SCK/MOSI/MISO hardware SPI pins and then user selected CS/IRQ/RST */
  Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);

  // A small helper
  void error(const __FlashStringHelper*err) {
    Serial.println(err);
    while (1);
  }
  
  /* The service information */
  int32_t hrmServiceId;
  int32_t hrmMeasureCharId;
  int32_t hrmLocationCharId;
  int32_t gattReadableCharId;

// BUTTON PIN VALUES
//int btnPin1 = 5;     // the number of the pushbutton pin
//int btnPin2 = 6;
//int btnPin3 = 9;
//int btnPin4 = 10;
//int btnPin5 = 11;
//int btnPin6 = 12;

// BUTTON COUNTER VALUES
int btnCnt1 = 0;    // temp for testing
//int btnCnt2 = 0;
//int btnCnt3 = 0;
//int btnCnt4 = 0;
//int btnCnt5 = 0;
//int btnCnt6 = 0;

// NEOPIXEL PIN VALUES
//int neoPin1 = 19;    // Which pin on the Arduino is connected to the NeoPixels?
//int neoPin2 = 0;
//int neoPin3 = 0;
//int neoPin4 = 0;
//int neoPin5 = 0;
//int neoPin6 = 0;
//int NUMPIXELS = 1;    // # NeoPixels in strip

// Neopixel Declarations
//Adafruit_NeoPixel pixel1 = Adafruit_NeoPixel(NUMPIXELS, neoPin1, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixel2 = Adafruit_NeoPixel(NUMPIXELS, neoPin2, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixel3 = Adafruit_NeoPixel(NUMPIXELS, neoPin3, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixel4 = Adafruit_NeoPixel(NUMPIXELS, neoPin4, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixel5 = Adafruit_NeoPixel(NUMPIXELS, neoPin5, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixel6 = Adafruit_NeoPixel(NUMPIXELS, neoPin6, NEO_GRB + NEO_KHZ800);
//int delayval = 1000;  // delay each light-on for a second


// SETUP ELECTRONICS
void setup() {
  
  // INITIALIZE BUTTON PINS AS INPUT
//  pinMode(btnPin1, INPUT);
//  pinMode(btnPin2, INPUT);
//  pinMode(btnPin3, INPUT);
//  pinMode(btnPin4, INPUT);
//  pinMode(btnPin5, INPUT);
//  pinMode(btnPin6, INPUT);

  // INITIALIZE NEOPIXEL PINS AS OUTPUT
//  pinMode(neoPin1, OUTPUT);
//  pixel1.begin();
//  pixel1.show();
//  pixel1.setBrightness(100);


// FEATHER SETUP
Serial.begin(9600);

if ( !ble.begin(VERBOSE_MODE) )
{
  error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
}
Serial.println( F("OK!") );

/* Perform a factory reset to make sure everything is in a known state */
Serial.println(F("Performing a factory reset: "));
if (! ble.factoryReset() ){
     error(F("Couldn't factory reset"));
}

/* Disable command echo from Bluefruit */
ble.echo(false);

Serial.println("Requesting Bluefruit info:");
/* Print Bluefruit information */
ble.info();

/* Change the device name to make it hrmServiceIdeasier to find */
Serial.println(F("Setting device name to 'Conner's Feather: "));

if (! ble.sendCommandCheckOK(F("AT+GAPDEVNAME=Conner's Feather")) ) {
  error(F("Could not set device name?"));
}

/* Add the Heart Rate Service definition */
/* Service ID should be 1 */
Serial.println(F("Adding the Heart Rate Service definition (UUID = 0x180D): "));
 ble.sendCommandWithIntReply( F("AT+GATTADDSERVICE=UUID=0x180D"), &hrmServiceId);

/* Add the Heart Rate Measurement characteristic */
/* Chars ID for Measurement should be 1 */
//Serial.println(F("Adding the Heart Rate Measurement characteristic (UUID = 0x2A37): "));
//ble.sendCommandWithIntReply( F("AT+GATTADDCHAR=UUID=0x2A37, PROPERTIES=0x10, MIN_LEN=2, MAX_LEN=3, VALUE=00-40"), &hrmMeasureCharId);

Serial.println(F("Adding the Readable characteristic: "));
boolean success = ble.sendCommandWithIntReply( F("AT+GATTADDCHAR=UUID128=00-70-42-04-00-77-12-10-13-42-CC-BA-DE-FA-EA-BD,PROPERTIES=0x02,MIN_LEN=1, MAX_LEN=20, VALUE=GREEN"), &gattReadableCharId);
    if (! success) {
    error(F("Could not add Custom Readable characteristic"));
  }

/* Add the Heart Rate Service to the advertising data (needed for Nordic apps to detect the service) */
Serial.print(F("Adding Heart Rate Service UUID to the advertising payload: "));
ble.sendCommandCheckOK( F("AT+GAPSETADVDATA=02-01-06-05-02-0d-18-0a-18") );

/* Reset the device for the new service setting changes to take effect */
Serial.print(F("Performing a SW reset (service changes require a reset): "));
ble.reset();

Serial.println();



  
}


// EXECUTE CONTROLS
// STATUS: CURRENTLY STILL TESTING
void loop() {

   // FEATHER
  featherRun();
  
//  if (digitalRead(btnPin1) == HIGH) {    // Check if the pushbutton is pressed
//    
//    Serial.println("Button 1 was pressed.");
//    btnCnt1 += 1; // increment counter
//    // Neopixel lights
//    pixel1.setPixelColor(0, pixel1.Color(0,0,255)); // Set color as moderately bright green color.
//    pixel1.show();                                 // Sends updated pixel color to the hardware.
//    delay(delayval);                               // Delay for a period of time (in milliseconds).
//    pixel1.setPixelColor(0, pixel1.Color(0,0,0)); // Set color as moderately bright green color.
//    pixel1.show();                                 // Sends updated pixel color to the hardware.
//
//  }
  
//  else if (digitalRead(btnPin2) == HIGH) {
//    
//    Serial.println("Button 2 was pressed.");
//    btnCnt2 += 1; // increment counter
//    // Neopixel lights
//    pixel2.setPixelColor(0, pixel2.Color(0,0,255)); // Set color as moderately bright green color.
//    pixel2.show();                                 // Sends updated pixel color to the hardware.
//    delay(delayval);                               // Delay for a period of time (in milliseconds).
//    pixel2.setPixelColor(0, pixel2.Color(0,0,0)); // Set color as moderately bright green color.
//    pixel2.show();                                 // Sends updated pixel color to the hardware.
//    
//  } else if (digitalRead(btnPin3) == HIGH) {
//
//    Serial.println("Button 3 was pressed.");
//    btnCnt3 += 1; // increment counter
//    // Neopixel lights
//    pixel3.setPixelColor(0, pixel3.Color(0,0,255)); // Set color as moderately bright green color.
//    pixel3.show();                                 // Sends updated pixel color to the hardware.
//    delay(delayval);                               // Delay for a period of time (in milliseconds).
//    pixel3.setPixelColor(0, pixel3.Color(0,0,0)); // Set color as moderately bright green color.
//    pixel3.show();   
//    
//  } else if (digitalRead(btnPin4) == HIGH) {
//
//    Serial.println("Button 2 was pressed.");
//    btnCnt4 += 1; // increment counter
//    // Neopixel lights
//    pixel4.setPixelColor(0, pixel4.Color(0,0,255)); // Set color as moderately bright green color.
//    pixel4.show();                                 // Sends updated pixel color to the hardware.
//    delay(delayval);                               // Delay for a period of time (in milliseconds).
//    pixel4.setPixelColor(0, pixel4.Color(0,0,0)); // Set color as moderately bright green color.
//    pixel4.show();   
//    
//  } else if (digitalRead(btnPin5) == HIGH) {
//
//    Serial.println("Button 2 was pressed.");
//    btnCnt5 += 1; // increment counter
//    // Neopixel lights
//    pixel5.setPixelColor(0, pixel5.Color(0,0,255)); // Set color as moderately bright green color.
//    pixel5.show();                                 // Sends updated pixel color to the hardware.
//    delay(delayval);                               // Delay for a period of time (in milliseconds).
//    pixel5.setPixelColor(0, pixel5.Color(0,0,0)); // Set color as moderately bright green color.
//    pixel5.show();   
//    
//  } else if (digitalRead(btnPin6) == HIGH) {
//
//    Serial.println("Button 2 was pressed.");
//    btnCnt6 += 1; // increment counter
//    // Neopixel lights
//    pixel6.setPixelColor(0, pixel6.Color(0,0,255)); // Set color as moderately bright green color.
//    pixel6.show();                                 // Sends updated pixel color to the hardware.
//    delay(delayval);                               // Delay for a period of time (in milliseconds).
//    pixel6.setPixelColor(0, pixel6.Color(0,0,0)); // Set color as moderately bright green color.
//    pixel6.show();   
//    
//  }
//  
//  else {
//    
//    Serial.println("No button was pressed.");
//    
//  }
  
}


// Send data
void featherRun() {
  /* Command is sent when \n (\r) or println is called */
  /* AT+GATTCHAR=CharacteristicID,value */
  ble.print( F("AT+GATTCHAR=") );
  //ble.print( hrmMeasureCharId );
  ble.print( gattReadableCharId );
  ble.print( F(",00-") );
  ble.println(5, HEX);

  /* Check if command executed OK */
  if ( !ble.waitForOK() )
  {
    Serial.println(F("Failed to get response!"));
  }

  /* Delay before next measurement update */
  delay(1000);
}
