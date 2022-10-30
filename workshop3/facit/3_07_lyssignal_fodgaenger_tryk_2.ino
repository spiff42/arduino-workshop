/**********************************************************************
 * Lyssignal to retninger + fodgængersignal med advanceret aktivering
 * https://github.com/spiff42/arduino-workshop
 * Coding Pirates Workshop, Lyngby - Microsoft, Oktober/November 2022
 * Mikkel Holm Olsen
 **********************************************************************/
const byte traffic_lightA_red_pin = 2;
const byte traffic_lightA_yellow_pin = 3;
const byte traffic_lightA_green_pin = 4;
const byte traffic_lightB_red_pin = 5;
const byte traffic_lightB_yellow_pin = 6;
const byte traffic_lightB_green_pin = 7;
const byte traffic_lightF_red_pin = 8;
const byte traffic_lightF_green_pin = 9;
const byte traffic_lightF_indicator_pin = 10;
const byte traffic_lightF_button_pin = 11;

bool lightF_activated = false;

void setup() {
  pinMode(traffic_lightA_red_pin, OUTPUT);
  pinMode(traffic_lightA_yellow_pin, OUTPUT);
  pinMode(traffic_lightA_green_pin, OUTPUT);
  pinMode(traffic_lightB_red_pin, OUTPUT);
  pinMode(traffic_lightB_yellow_pin, OUTPUT);
  pinMode(traffic_lightB_green_pin, OUTPUT);
  pinMode(traffic_lightF_red_pin, OUTPUT);
  digitalWrite(traffic_lightF_red_pin, HIGH); // Tænd rødt
  pinMode(traffic_lightF_green_pin, OUTPUT);
  pinMode(traffic_lightF_indicator_pin, OUTPUT);
  digitalWrite(traffic_lightF_indicator_pin, HIGH); // Sluk indikator
  pinMode(traffic_lightF_button_pin, INPUT_PULLUP);
}

void delay_poll_button(unsigned long duration_msec) {
  unsigned long expire = millis() + duration_msec;
  while (millis() < expire) {
    if (digitalRead(traffic_lightF_button_pin) == LOW) {
      lightF_activated = true;
      digitalWrite(traffic_lightF_indicator_pin, LOW); // Tænd indikator
    }
  }
}

void loop() {
  // 1. tilstand: rødt lys  
  digitalWrite(traffic_lightA_red_pin, HIGH); // Tænd rødt
  
  // B2. rød + gul
  digitalWrite(traffic_lightB_red_pin, HIGH); // Tænd rødt
  digitalWrite(traffic_lightB_yellow_pin, HIGH); // Tænd gult
  delay_poll_button(1000);

  if (lightF_activated) {
    lightF_activated = false;
    digitalWrite(traffic_lightF_indicator_pin, HIGH); // Sluk indikator
    // Fodgænger grønt
    digitalWrite(traffic_lightF_red_pin, LOW); // Sluk rødt
    digitalWrite(traffic_lightF_green_pin, HIGH); // Tænd grønt
  }

  // B3. grøn
  digitalWrite(traffic_lightB_red_pin, LOW); // Sluk rødt
  digitalWrite(traffic_lightB_yellow_pin, LOW); // Sluk gult
  digitalWrite(traffic_lightB_green_pin, HIGH); // Tænd grønt
  delay_poll_button(5000);

  // Fodgænger rødt
  digitalWrite(traffic_lightF_green_pin, LOW); // Sluk grønt
  digitalWrite(traffic_lightF_red_pin, HIGH); // Tænd rødt

  // B4. gul
  digitalWrite(traffic_lightB_green_pin, LOW); // Sluk grønt
  digitalWrite(traffic_lightB_yellow_pin, HIGH); // Tænd gult  
  delay_poll_button(1000);

  // B1. rød
  digitalWrite(traffic_lightB_yellow_pin, LOW); // Sluk gult
  digitalWrite(traffic_lightB_red_pin, HIGH); // Tænd rødt

  // 2. tilstand: rødt + gult lys
  digitalWrite(traffic_lightA_yellow_pin, HIGH); // Tænd gult
  delay_poll_button(1000);

  // 3. tilstand: grønt lys
  digitalWrite(traffic_lightA_red_pin, LOW); // Sluk rødt
  digitalWrite(traffic_lightA_yellow_pin, LOW); // Sluk gult
  digitalWrite(traffic_lightA_green_pin, HIGH); // Tænd grønt
  delay_poll_button(5000);

  // 4. tilstand: gult lys
  digitalWrite(traffic_lightA_green_pin, LOW); // Sluk grønt
  digitalWrite(traffic_lightA_yellow_pin, HIGH); // Tænd gult  
  delay_poll_button(1000);
  digitalWrite(traffic_lightA_yellow_pin, LOW); // Sluk gult
}
