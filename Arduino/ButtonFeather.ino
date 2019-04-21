
// IMPORTS
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// BUTTON VALUES
int btnPin1 = 12;     // the number of the pushbutton pin
//int buttonState = 0;    // variable for reading the pushbutton status
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

// NEOPIXEL VALUES
int neoPin1 = 23    // Which pin on the Arduino is connected to the NeoPixels?
//int neoPin2 = 0;
//int neoPin3 = 0;
//int neoPin4 = 0;
//int neoPin5 = 0;
//int neoPin6 = 0;
int NUMPIXELS = 1    // # NeoPixels in strip
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, neoPin1, NEO_GRB + NEO_KHZ800);
int delayval = 500;  // delay for half-a-second


// SETUP ELECTRONICS
void setup() {
  
  // INITIALIZE BUTTON PINS AS INPUT
  pinMode(btnPin1, INPUT);
//  pinMode(btnPin2, INPUT);
//  pinMode(btnPin3, INPUT);
//  pinMode(btnPin4, INPUT);
//  pinMode(btnPin5, INPUT);
//  pinMode(btnPin6, INPUT);

  // INITIALIZE NEOPIXEL PIN AS OUTPUT
  pinMode(neoPin1, OUTPUT);
  pixels.begin();
  pixels.setBrightness(50);
  
}


// EXECUTE CONTROLS
// STATUS: CURRENTLY STILL TESTING
void loop() {
  
  if (digitalRead(btnPin1) == HIGH) {    // Check if the pushbutton is pressed
    
    Serial.println("Button 1 was pressed.");
    btnCnt1 += 1; // increment counter
    pixels.setPixelColor(0, pixels.Color(0,0,10)); // Set color as moderately bright green color.
    pixels.show();                                 // Sends updated pixel color to the hardware.
    delay(delayval);                               // Delay for a period of time (in milliseconds).
 
  } else {
    Serial.println("No button was pressed.");
  }
  
}




// Prep for later
//  } else if (digitalRead(btnPin2) == HIGH) {
//  } else if (digitalRead(btnPin3) == HIGH) {
//  } else if (digitalRead(btnPin4) == HIGH) {
//  } else if (digitalRead(btnPin5) == HIGH) {
//  } else if (digitalRead(btnPin6) == HIGH) {
//  }
