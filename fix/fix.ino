#define Relay1    2  //D4
#define Relay2    14 //D5
#define Relay3    12 //D6
#define Relay4    13 //D7

#define push      15 //D8

int sensorValue = 0;
int deltime     = 0;

unsigned long previousMillis = 0;
unsigned long currentMillis = 0;

const long interval1 = 100;
const long interval2 = 0;

void setup() {
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  pinMode(push, INPUT);

  digitalWrite(Relay1, HIGH);
  digitalWrite(Relay2, HIGH);
  digitalWrite(Relay3, HIGH);
  digitalWrite(Relay4, HIGH);
}

void loop() {
  if (millis() - previousMillis >= interval1) {
    sensorValue = analogRead(A0);
    deltime = map(sensorValue, 0, 1024, 1, 255) * 15;
    previousMillis = millis();

    if (digitalRead(push) == HIGH) {
      if (millis() - currentMillis >= deltime) {
        digitalWrite(Relay1, LOW);
        currentMillis = millis();
      }
      if (millis() - currentMillis >= deltime*2) {
        digitalWrite(Relay2, LOW);
        currentMillis = millis();
      }
      if (millis() - currentMillis >= deltime*3) {
        digitalWrite(Relay3, LOW);
        currentMillis = millis();
      }
      if (millis() - currentMillis >= deltime*4) {
        digitalWrite(Relay4, LOW);
        currentMillis = millis();
      }
    }

    if (digitalRead(push) == LOW) {
      if (millis() - currentMillis >= deltime) {
        digitalWrite(Relay1, !LOW);
        currentMillis = millis();
      }
      if (millis() - currentMillis >= deltime*2) {
        digitalWrite(Relay2, !LOW);
        currentMillis = millis();
      }
      if (millis() - currentMillis >= deltime*3) {
        digitalWrite(Relay3, !LOW);
        currentMillis = millis();
      }
      if (millis() - currentMillis >= deltime*4) {
        digitalWrite(Relay4, !LOW);
        currentMillis = millis();
      }
    }
  }
}