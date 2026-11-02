// Minimal W5500SecureMqtt example using an insecure (no certificate check) connection.
// Template — for production use begin() with a BearSSL::X509List trust anchor. Compile-check first.
#include <W5500SecureMqtt.h>

W5500SecureMqtt client;

void setup() {
  Serial.begin(115200);
  client.beginInsecure("broker.example.com", "w5500-client", nullptr, nullptr, 8883);
}

void loop() {
  bool networkReady = true;  // replace with your real W5500 link-up check
  client.tick(networkReady);
  if (client.status() == W5500SecureMqtt::Status::Connected)
    client.publish("wilcoxon/secure", "online");
  delay(1000);
}
