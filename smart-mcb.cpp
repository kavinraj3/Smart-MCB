#define BLYNK_PRINT Serial
#include <ESP32WiFi.h>
#include <BlynkSimpleEsp32.h>

// Blynk credentials
char auth[] = "YOUR_BLYNK_AUTH";
char ssid[] = "YOUR_WIFI";
char pass[] = "YOUR_PASSWORD";

// Relay pins
int relay1 = D1;
int relay2 = D2;
int relay3 = D3;

// Threshold values
float MAX_CURRENT = 2.0;    // overload limit (Amps)
float MIN_VOLTAGE = 180.0;  // voltage drop
float MAX_VOLTAGE = 250.0;  // over voltage

void setup() {
  Serial.begin(9600);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);

  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);

  Blynk.begin(auth, ssid, pass);
}

float readCurrent() {
  int raw = analogRead(A0);
  float voltage = raw * (3.3 / 1023.0);
  float current = (voltage - 2.5) / 0.185; // ACS712
  return abs(current);
}

float readVoltage() {
  int raw = analogRead(A0);
  float voltage = raw * (250.0 / 1023.0); // ZMPT101B
  return voltage;
}

void checkLine(int relayPin, int vPin, int cPin, int lineNo) {
  float voltage = readVoltage();
  float current = readCurrent();
  float power = voltage * current;

  if (current > MAX_CURRENT) {
    digitalWrite(relayPin, HIGH);
    Blynk.logEvent("fault", "Overload in Line " + String(lineNo));
  }
  else if (voltage < MIN_VOLTAGE) {
    digitalWrite(relayPin, HIGH);
    Blynk.logEvent("fault", "Voltage Drop in Line " + String(lineNo));
  }
  else if (voltage > MAX_VOLTAGE) {
    digitalWrite(relayPin, HIGH);
    Blynk.logEvent("fault", "Over Voltage in Line " + String(lineNo));
  }

  Blynk.virtualWrite(vPin, voltage);
  Blynk.virtualWrite(cPin, current);
}

void loop() {
  Blynk.run();

  checkLine(relay1, V1, V2, 1);
  checkLine(relay2, V3, V4, 2);
  checkLine(relay3, V5, V6, 3);

  delay(1000);
}
