// Minimal WilcoxonMqtt example: connect over Wi-Fi and publish once a second.
// Template — fill in Wi-Fi and broker details and compile-check before use.
#include <WiFi.h>
#include <WilcoxonMqtt.h>

WiFiClient net;
WilcoxonMqttClient mqtt(net);

void setup() {
  Serial.begin(115200);
  WiFi.begin("your-ssid", "your-password");
  while (WiFi.status() != WL_CONNECTED) delay(500);
  mqtt.setServer("broker.example.com", 1883);
}

void loop() {
  if (!mqtt.connected()) mqtt.connect("wilcoxon-client");
  mqtt.loop();
  mqtt.publish("wilcoxon/status", "online");
  delay(1000);
}
