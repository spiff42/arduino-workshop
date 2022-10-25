/**********************************************************************
 * Variable og løkke
 * NB: Der er en fejl i denne sketch, hvad er det?
 * https://github.com/spiff42/arduino-workshop
 * Coding Pirates Workshop, Lyngby - Microsoft, Oktober/November 2022
 * Mikkel Holm Olsen
 **********************************************************************/
int i = 0, sum = 0;

void setup() {
  Serial.begin(9600);
  while (sum < 40000) {
    Serial.println(sum, DEC);
    i = i + 1;
    sum = sum + i;
  }
}

void loop() {
}
