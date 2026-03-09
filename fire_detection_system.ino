#include <DHT.h>

#define DHTPIN 4          // DHT connected to GPIO 4
#define DHTTYPE DHT11
#define SMOKE_PIN 34      // MQ2 DO connected to GPIO 34

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(SMOKE_PIN, INPUT);
  dht.begin();
}

void loop() {

  float temp = dht.readTemperature();
  int smoke = digitalRead(SMOKE_PIN);

  // Check if DHT failed
  if (isnan(temp)) {
    Serial.println("DHT not reading properly!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C  | Smoke: ");
  Serial.println(smoke);

  if (smoke == HIGH || temp > 50) {
    Serial.println("🔥 FIRE RISK DETECTED!");
  } else {
    Serial.println("System Normal");
  }

  Serial.println("---------------------");
  delay(2000);
}
