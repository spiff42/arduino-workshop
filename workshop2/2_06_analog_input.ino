/**********************************************************************
 * Analog input
 * https://github.com/spiff42/arduino-workshop
 * Coding Pirates Workshop, Lyngby - Microsoft, Oktober/November 2022
 * Mikkel Holm Olsen
 **********************************************************************/
void setup() {
  Serial.begin(9600);
}

int sensorValue;

void loop() {
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
}
