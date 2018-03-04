/* 
Force Sensitive Resistor testing sketch
*/
 
int fsrAnalogPin = 0; // FSR is connected to analog 0
int LEDpin = 11;      // LED to pin 11 
int fsrReading;      // Analog reading from the FSR resistor divider
int LEDbrightness;
 
void setup(void) {
  Serial.begin(9600);   // Baud rate for serial monitor
  pinMode(LEDpin, OUTPUT);
}
 
void loop(void) {
  fsrReading = (analogRead(fsrAnalogPin));

  // Log FSR analog reading
  Serial.print("Analog reading : ");
  Serial.print(fsrReading);
 
   // Log thresholds
  if (fsrReading < 10) {
    Serial.print(" - No pressure");
  } else if (fsrReading < 200) {
    Serial.println(" - Very light pressure");
  } else if (fsrReading < 500) {
    Serial.println(" - Light pressure");
  } else if (fsrReading < 800) {
    Serial.println(" - Medium pressure");
  } else {
    Serial.println(" - Strong pressure");
  }

  /* Change the range from the analog reading (0-1023) down to the range
  used by analogWrite (0-255) using map function. */
  LEDbrightness = map(fsrReading, 0, 1023, 0, 255);
  // Set LED brightness based on analog pressure reading
  analogWrite(LEDpin, LEDbrightness);
 
  delay(500); // Updates every 500 milliseconds
}