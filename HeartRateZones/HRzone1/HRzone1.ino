
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>  // Includes the PulseSensor Library.

#include <Adafruit_NeoPixel.h>  //neopixel library
#define PIN 6
#define NUMPIXELS 144  // Popular NeoPixel size
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

//  Variables
const int PulseWire = 0;
int Threshold = 550;

int age = 21;
int maxHR = 211 - (0.64 * age);

int potPin = A2;  // Potentiometer output connected to analog pin 2
int potVal = 0;   // Variable to store the input from the potentiometer

PulseSensorPlayground pulseSensor;  // Creates a PulseSensor object called "pulseSensor"

void setup() {

  pixels.begin();      // NeoPixel strip object
  Serial.begin(9600);  // Serial Monitor

  //pulsesensor requirments
  pulseSensor.analogInput(PulseWire);
  pulseSensor.setThreshold(Threshold);

  if (pulseSensor.begin()) {  //checks that pulsesensor object is present
    Serial.println("Created pulseSensor Object");
  }
}

void loop() {

  pixels.clear();

  int zone5 = maxHR * 90 / 144;
  int colour5[4] = { 15, 0, 0, 0 };
  showZones(zone5, 144, colour5);  //passing colour and zone integers to show zones function

  int zone4 = maxHR * 80 / 144;
  int colour4[4] = { 25, 2.5, 0, 0 };
  showZones(zone4, zone5, colour4);

  int zone3 = maxHR * 70 / 144;
  int colour3[4] = { 25, 5, 0, 0 };
  showZones(zone3, zone4, colour3);

  int zone2 = maxHR * 60 / 144;
  int colour2[4] = { 25, 10, 0, 0 };
  showZones(zone2, zone3, colour2);

  int zone1 = maxHR * 50 / 144;
  int colour1[4] = { 25, 15, 0, 0 };
  showZones(zone1, zone2, colour1);

  int colour0[4] = { 5, 10, 0, 0 };
  showZones(0, zone1, colour0);

  //potentiometer onto LED
  potVal = analogRead(potPin) * 0.14;  // read the potentiometer value at the input pin and convert to value between 0-144

  pixels.setPixelColor(potVal, pixels.Color(0, 255, 0, 0));


  //live BPM rate LED
  int myBPM = pulseSensor.getBeatsPerMinute();
  int convertedBPM = myBPM * 100 / 144;  //bpm as percentage
  Serial.println(myBPM);
  pixels.setPixelColor(convertedBPM, pixels.Color(255, 0, 0, 0));
  pixels.setPixelColor(convertedBPM + 1, pixels.Color(0, 0, 255, 0));
  pixels.setPixelColor(convertedBPM - 1, pixels.Color(0, 0, 255, 0));

  pixels.show();  // Send the updated pixel colors to the hardware.

  if (convertedBPM > potVal) {  //if heart rate reaches target

    for (int i = 0; i == NUMPIXELS; i++) {  // For each pixel...

      // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
      // Here we're using a moderately bright green color:
      pixels.setPixelColor(i, pixels.Color(0, 255, 0, 0));

      pixels.show();  // Send the updated pixel colors to the hardware.
    }
  }
}

void showZones(int zoneMin, int zoneMax, int colour[4]) {  //function for displaying HR zones

  for (int i = zoneMin; i < zoneMax; i++) {

    pixels.setPixelColor(i, pixels.Color(colour[0], colour[1], colour[2], colour[3]));
  }
}
