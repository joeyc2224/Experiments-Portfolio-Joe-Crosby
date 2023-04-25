//simple 
#include <Adafruit_NeoPixel.h>

#define PIN 6 

#define NUMPIXELS 144  // NeoPixel size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

#define DELAYVAL 0  // Time to pause between pixels

void setup() {

  pixels.begin();  // INITIALIZE NeoPixel strip 
}

void loop() {


  for (int i = 0; i < NUMPIXELS; i++) {  // For each pixel...

    if (i % 2 != 0) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 255, 0));
    } else {
      pixels.setPixelColor(i, pixels.Color(255, 0, 0, 0));
    }

    pixels.show();  // Send the updated pixel colors

    delay(DELAYVAL);  // Pause before next pass through loop
  }



  for (int i = 144; i > 0; i--) {  // For each pixel...

    if (i % 2 == 0) {
      pixels.setPixelColor(i, pixels.Color(0, 255, 0, 0));
    } else {
      pixels.setPixelColor(i, pixels.Color(255, 0, 0, 0));
    }

    pixels.show();  // Send the updated pixel colors to the hardware.

    delay(DELAYVAL);  // Pause before next pass through loop
  }
}
