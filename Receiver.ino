#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
RH_ASK driver;
//Transmit at pin 11; receive at pin 12;
const uint8_t maxMessageSize = 50; // Maximum message size

uint8_t buf[maxMessageSize];
uint8_t buflen;

void setup() {
  Serial.begin(9600);    // Debugging only
  buflen = sizeof(buf); // Initialize buflen to the size of the buffer
  if (!driver.init())
    Serial.println("init failed");
  else
    Serial.println("init success");
}

void loop() {
  if (driver.recv(buf, &buflen)) // Non-blocking
  {
    // Message with a good checksum received, dump it.
    Serial.print("Message: ");
    for (int i = 0; i < buflen; i++) {
      if (isPrintableChar(buf[i])) {
        Serial.write(buf[i]);
      }
      else {
        Serial.print("Non-printable character (ASCII code ");
        Serial.print(buf[i]);
        Serial.print(")");
      }
    }
    Serial.println();
    // Reset buflen to the size of the buffer for the next message
    buflen = sizeof(buf);
  }
}

bool isPrintableChar(uint8_t c) {
  return (c >= 32 && c <= 126); // ASCII printable characters
}
