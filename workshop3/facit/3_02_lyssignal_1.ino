/**********************************************************************
 * Trafiklys skabelon
 * Coding Pirates Workshop, Lyngby - Microsoft, Oktober/November 2022
 * Mikkel Holm Olsen
 **********************************************************************/
const byte traffic_lightA_red_pin = 2;
const byte traffic_lightA_yellow_pin = 3;
const byte traffic_lightA_green_pin = 4;

void setup() {
  pinMode(traffic_lightA_red_pin, OUTPUT);
  // Tilføj kode der initialiserer de to andre pins
}

void loop() {
  // 1. tilstand: rødt lys  
  digitalWrite(traffic_lightA_red_pin, HIGH); // Tænd rødt
  delay(7000);

  // 2. tilstand: rødt + gult lys
  //digitalWrite(...); // Tænd gult
  delay(1000);

  // 3. tilstand: grønt lys
  // Sluk rødt
  // Sluk gult
  // Tænd grønt
  delay(5000);

  // 4. tilstand: gult lys
  // ...
  delay(1000);
}
