#include <CapacitiveSensor.h>                         //declare library
CapacitiveSensor capSensor = CapacitiveSensor(8, 7);  //pin sensor connection

void setup()  //settings of our arduino
{
  Serial.begin(9600);  //Set the monitor
}

void loop() {
  long sensorValue = capSensor.capacitiveSensor(30);  //Save the values in a constant slow
  Serial.println(sensorValue);                        //Print to screen the data read

  if (sensorValue > 1000) {
    Serial.println("touch!");
  }

  delay(400);
}
