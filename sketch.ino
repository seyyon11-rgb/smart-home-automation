#define BLYNK_TEMPLATE_ID "TMPL6abc123"
#define BLYNK_TEMPLATE_NAME "SmartHome"
#define BLYNK_AUTH_TOKEN "abcd1234xyz"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// WiFi credentials
char ssid[] = "air99Wifi";
char pass[] = "aot96";

// Pins
#define DHTPIN 4
#define DHTTYPE DHT22
#define LED_PIN 5

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

// 📱 Mobile switch control
BLYNK_WRITE(V0) {
  int value = param.asInt();   // 0 or 1
  digitalWrite(LED_PIN, value);
}

// 🌡️ Send sensor data
void sendData() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Sensor Error");
    return;
  }

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C | Hum: ");
  Serial.println(hum);

  // Send to mobile
  Blynk.virtualWrite(V1, temp);
  Blynk.virtualWrite(V2, hum);

  // 🔥 Auto control (optional)
  if (temp > 30) {
    digitalWrite(LED_PIN, HIGH);
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  dht.begin();

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(2000L, sendData);
}

void loop() {
  Blynk.run();
  timer.run();
}
