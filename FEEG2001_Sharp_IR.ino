/*
 * Author: Ayo Abioye (abioyeayo@gmail.com)
 * FileName: FEEG2001_Sharp_IR
 * Purpose: FEEG2001 Course Sharp IR sensor Distance measurement demonstration
 * Date: Fri 21-Oct-2016
 * 
 * Description: Modified from the default arduino AnalogReadSerial
 * Reads an analog input on pin 0, prints the result to the serial monitor.
 * Attach the WHITE wire of the Sharp IR sensor to pin A0, RED to +5V, and BLACK to Gnd.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);

  float x = sensorValue/5445.3;           // y = 5445.3x; where y is raw sensor adc value, x = 1/(L + K)
  float distance_cm = (1/x) - 2;          // where k = 2; and L = distance in cm;

  
  // print out the value you read:
  Serial.println(distance_cm + 'cm');
  delay(100);        // delay in between reads for stability
}
