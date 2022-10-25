/**********************************************************************
 * Knap tænder og slukker lysdiode, løsning 2
 * https://github.com/spiff42/arduino-workshop
 * Coding Pirates Workshop, Lyngby - Microsoft, Oktober/November 2022
 * Mikkel Holm Olsen
 **********************************************************************/
const byte lysdiode_pin = 10;
const byte knap_input_pin = 11;

void setup() {
  pinMode(lysdiode_pin, OUTPUT);
  pinMode(knap_input_pin, INPUT_PULLUP);
}

void loop() {
  digitalWrite(lysdiode_pin, !digitalRead(knap_input_pin));
}