
const int pResistor = A0;  // Photoresistor at Arduino analog pin A0
const int ledPin = 7;      // Led pin at Arduino pin 9
const int greenLedPin = 4;      // Led pin at Arduino pin 4

int value;  // Store value from photoresistor (0-1023)

void setup() {
  pinMode(ledPin, OUTPUT);    // Set lepPin - 9 pin as an output
  pinMode(greenLedPin, OUTPUT);    
  pinMode(pResistor, INPUT);  // Set pResistor - A0 pin as an input
  Serial.begin(9600);
}

void loop() {
  value = analogRead(pResistor);

  Serial.println(value);

  digitalWrite(greenLedPin, HIGH);

  if (value < 20) {
    digitalWrite(ledPin, HIGH); 
  } else {
    digitalWrite(ledPin, LOW);  
  }

  delay(200);  //Small delay
}