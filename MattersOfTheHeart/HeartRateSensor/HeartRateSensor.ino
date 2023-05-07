#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>  // Includes the PulseSensor Library.

//  Variables
const int PulseWire = 1;
const int LED = 6;
int Threshold = 550;

PulseSensorPlayground pulseSensor;  // Creates a PulseSensor object called "pulseSensor"


void setup() {

  Serial.begin(9600);  // Serial Monitor
  pulseSensor.analogInput(PulseWire);
  pulseSensor.blinkOnPulse(LED);
  pulseSensor.setThreshold(Threshold);


  if (pulseSensor.begin()) {  //checks that pulsesensor object is present
    Serial.println("Created pulseSensor Object");
  }
}



void loop() {



  if (pulseSensor.sawStartOfBeat()) {  // constantly checks if a beat happens
    int myBPM = pulseSensor.getBeatsPerMinute();

    Serial.println("♥  A HeartBeat Happened ! ");
    Serial.print("BPM: ");
    Serial.println(myBPM);
  }

  delay(20);
}