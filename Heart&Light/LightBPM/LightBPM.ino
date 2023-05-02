
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
  Serial.begin(9600);  // Serial Monitor
  pulseSensor.analogInput(PulseWire);
  pulseSensor.setThreshold(Threshold);

  if (pulseSensor.begin()) {  //checks that pulsesensor object is present
    Serial.println("Created pulseSensor Object");
  }
}


void loop() {

  pixels.clear();


  if (pulseSensor.sawStartOfBeat()) {  // constantly checks if a beat happens

    int myBPM = pulseSensor.getBeatsPerMinute();

    Serial.println(myBPM);


    for (int i = 0; i < myBPM; i++) {

      pixels.setPixelColor(i, pixels.Color(255, 0, 0, 0));
    }

    pixels.show();  // Send the updated pixel colors to the hardware.

    delay(20);
  }
}
