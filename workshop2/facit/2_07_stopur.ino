/**********************************************************************
 * Simpelt stopur
 * https://github.com/spiff42/arduino-workshop
 * Coding Pirates Workshop, Lyngby - Microsoft, Oktober/November 2022
 * Mikkel Holm Olsen
 **********************************************************************/
const byte lysdiode_pin = 10;
const byte knap_input_pin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(lysdiode_pin, OUTPUT);
  digitalWrite(lysdiode_pin, HIGH); // Sluk LED
  pinMode(knap_input_pin, INPUT_PULLUP);
}
unsigned long starttid, sluttid;

void loop() {
  while (digitalRead(knap_input_pin) != LOW) continue; // Vent til knap trykkes ned
  digitalWrite(lysdiode_pin, LOW); // Tænd LED
  starttid = millis();

  Serial.print("Start ");
  Serial.println(starttid);

  delay(5); // Undgå kontaktprel
  while (digitalRead(knap_input_pin) == LOW) continue; // Vent til knap slippes
  delay(5); // Undgå kontaktprel


  while (digitalRead(knap_input_pin) != LOW) continue; // Vent til knap trykkes ned
  digitalWrite(lysdiode_pin, HIGH); // Sluk LED
  sluttid = millis();
  
  delay(5); // Undgå kontaktprel
  Serial.print("Stop ");
  Serial.println(sluttid);
  
  unsigned long forskel = sluttid - starttid;

  Serial.print("Forskel ");
  Serial.println(forskel);
  
  while (digitalRead(knap_input_pin) == LOW) continue; // Vent til knap slippes
  delay(5); // Undgå kontaktprel

}
