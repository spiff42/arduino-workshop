/**********************************************************************
 * Array, float og for-løkke
 * https://github.com/spiff42/arduino-workshop
 * Coding Pirates Workshop, Lyngby - Microsoft, Oktober/November 2022
 * Mikkel Holm Olsen
 **********************************************************************/
void setup() {
  Serial.begin(9600);
  while (!Serial) { }
}
float arr[] = { 1.1, 2.2, 4.4, 8.8, 16.16, 32.32, 64.64, 128.128 };
void loop() {
  float sum = 0.0;
  // put your main code here, to run repeatedly:
  for (int i=0; i<8; i++) {
    sum += arr[i];
    Serial.print("arr[");
    Serial.print(i, DEC);
    Serial.print("] = ");
    Serial.print(arr[i]);
    Serial.print(", sum=");
    Serial.println(sum);
  }
  delay(5000);
}