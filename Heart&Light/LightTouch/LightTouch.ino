
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>  // Includes the PulseSensor Library.

#include <Adafruit_NeoPixel.h>  //neopixel library
#define PIN 6
#define NUMPIXELS 144  // Popular NeoPixel size
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

//  Variables
const int PulseWire = 0;
int Threshold = 550;

PulseSensorPlayground pulseSensor;  // Creates a PulseSensor object called "pulseSensor"

void setup() {

  pixels.begin();      // INITIALIZE NeoPixel strip object

  pulseSensor.analogInput(PulseWire);
  pulseSensor.setThreshold(Threshold);

}


void loop() {
  pixels.clear();


  if (pulseSensor.sawStartOfBeat()) {  // constantly checks if a beat happens

    pixels.setPixelColor(5, pixels.Color(255, 0, 0, 0));
  }

  pixels.show();  // Send the updated pixel colors to the hardware.

  delay(20);
}
