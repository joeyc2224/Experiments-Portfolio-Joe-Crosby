
#include <Adafruit_NeoPixel.h>

#define PIN 6

#define NUMPIXELS 144  // NeoPixel size

int potPin = A0;  // Potentiometer output connected to analog pin 3
int potVal = 0;   // Variable to store the input from the potentiometer

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pixels.begin();  // NeoPixel strip object
}

void loop() {

  pixels.clear();  // Set all pixel colors to 'off'

  potVal = analogRead(potPin) * 0.14;  // read the potentiometer value at the input pin
  Serial.println(potVal);

  pixels.setPixelColor(potVal, pixels.Color(0, 255, 0, 0));

  //int enemyPos = random(0, 144);
  int targetPos = 50;
  int score = 0;

  pixels.setPixelColor(targetPos, pixels.Color(255, 0, 0, 0));

  pixels.show();

  if (potVal == targetPos) {
    for (int i = 0; i < NUMPIXELS; i++) {  // For each pixel...

      // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
      // Here we're using a moderately bright green color:
      pixels.setPixelColor(i, pixels.Color(255, 0, 0, 0));

      pixels.show();  // Send the updated pixel colors to the hardware.
    }
  }
}
