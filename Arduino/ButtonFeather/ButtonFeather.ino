
// IMPORTS
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// BUTTON PIN VALUES
int btnPin1 = 12;     // the number of the pushbutton pin
//int btnPin2 = 0;
//int btnPin3 = 0;
//int btnPin4 = 0;
//int btnPin5 = 0;
//int btnPin6 = 0;

// BUTTON COUNTER VALUES
int btnCnt1 = 0;    // temp for testing
//int btnCnt2 = 0;
//int btnCnt3 = 0;
//int btnCnt4 = 0;
//int btnCnt5 = 0;
//int btnCnt6 = 0;

// NEOPIXEL PIN VALUES
int neoPin1 = 19;    // Which pin on the Arduino is connected to the NeoPixels?
//int neoPin2 = 0;
//int neoPin3 = 0;
//int neoPin4 = 0;
//int neoPin5 = 0;
//int neoPin6 = 0;
int NUMPIXELS = 1;    // # NeoPixels in strip

// Neopixel Declarations
Adafruit_NeoPixel pixel1 = Adafruit_NeoPixel(NUMPIXELS, neoPin1, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixel2 = Adafruit_NeoPixel(NUMPIXELS, neoPin2, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixel3 = Adafruit_NeoPixel(NUMPIXELS, neoPin3, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixel4 = Adafruit_NeoPixel(NUMPIXELS, neoPin4, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixel5 = Adafruit_NeoPixel(NUMPIXELS, neoPin5, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixel6 = Adafruit_NeoPixel(NUMPIXELS, neoPin6, NEO_GRB + NEO_KHZ800);
int delayval = 1000;  // delay each light-on for a second


// SETUP ELECTRONICS
void setup() {
  
  // INITIALIZE BUTTON PINS AS INPUT
  pinMode(btnPin1, INPUT);
//  pinMode(btnPin2, INPUT);
//  pinMode(btnPin3, INPUT);
//  pinMode(btnPin4, INPUT);
//  pinMode(btnPin5, INPUT);
//  pinMode(btnPin6, INPUT);

  // INITIALIZE NEOPIXEL PINS AS OUTPUT
  pinMode(neoPin1, OUTPUT);
  pixel1.begin();
  pixel1.show();
  pixel1.setBrightness(100);
//  --
//  pinMode(neoPin2, OUTPUT);
//  pixel2.begin();
//  pixel2.show();
//  pixel2.setBrightness(100);
//  --
//  pinMode(neoPin3, OUTPUT);
//  pixel3.begin();
//  pixel3.show();
//  pixel3.setBrightness(100);
//  --
//  pinMode(neoPin4, OUTPUT);
//  pixel4.begin();
//  pixel4.show();
//  pixel4.setBrightness(100);
//  --
//  pinMode(neoPin5, OUTPUT);
//  pixel5.begin();
//  pixel5.show();
//  pixel5.setBrightness(100);
//  --
//  pinMode(neoPin6, OUTPUT);
//  pixel6.begin();
//  pixel6.show();
//  pixel6.setBrightness(100);
  
}


// EXECUTE CONTROLS
// STATUS: CURRENTLY STILL TESTING
void loop() {
  
  if (digitalRead(btnPin1) == HIGH) {    // Check if the pushbutton is pressed
    
    Serial.println("Button 1 was pressed.");
    btnCnt1 += 1; // increment counter
    // Neopixel lights
    pixel1.setPixelColor(0, pixel1.Color(0,0,255)); // Set color as moderately bright green color.
    pixel1.show();                                 // Sends updated pixel color to the hardware.
    delay(delayval);                               // Delay for a period of time (in milliseconds).
    pixel1.setPixelColor(0, pixel1.Color(0,0,0)); // Set color as moderately bright green color.
    pixel1.show();                                 // Sends updated pixel color to the hardware.

  }
  
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
  else {
    
    Serial.println("No button was pressed.");
    
  }
  
}
