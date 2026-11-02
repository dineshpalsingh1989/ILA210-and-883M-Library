// Minimal IRIVIOCHardware example: bring up the W5500 Ethernet and print the IP.
// Template — set the CS / interrupt pins for your board and compile-check before use.
#include <SPI.h>
#include <IRIVIOCHardware.h>

irivioc::Ethernet eth(/*cs=*/5, SPI, /*interruptPin=*/-1);

void setup() {
  Serial.begin(115200);
  if (!eth.begin("iriv-device")) Serial.println("Ethernet begin failed");
}

void loop() {
  if (eth.connected()) { Serial.print("IP: "); Serial.println(eth.localIP()); }
  else Serial.println("Link down");
  delay(2000);
}
