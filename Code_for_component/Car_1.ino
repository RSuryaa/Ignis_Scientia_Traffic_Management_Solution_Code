#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
RH_ASK driver;
//Transmit at pin 12; receive at pin 11;
const uint8_t maxMessageSize = 50; // Maximum message size

uint8_t buf[maxMessageSize];
uint8_t buflen;

char TM[9] = " - Car 1";

void transmit(char *data)   // To transmit function. Pass only char datatype as argument.
{
    const char *msg = data;
    driver.send((uint8_t *)msg, strlen(msg));
    Serial.println("Sent");
    Serial.println(data);
    driver.waitPacketSent();
}

void setup() {
  Serial.begin(9600);    // Debugging only
  buflen = sizeof(buf); // Initialize buflen to the size of the buffer
  if (!driver.init())
    Serial.println("init failed");
  else
    Serial.println("init success");
}

char myChar[51]; // Define a character array to store the converted characters (plus room for null-terminator)

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

    // Reset the myChar array and copy the converted characters
    memset(myChar, 0, sizeof(myChar)); // Reset myChar to all null characters
    Serial.println("Converted char data:");
    int charIndex = 0; // Index to track the position in myChar
    for (int i = 0; i < buflen; i++) {
      if (isPrintableChar(buf[i])) {
        myChar[charIndex] = static_cast<char>(buf[i]); // Convert uint8_t to char
        Serial.write(myChar[charIndex]); // Print the converted character
        charIndex++;
      }
    }
    Serial.println();
    if(strcmp(myChar, "Green Signal")==0){
      digitalWrite(7, HIGH);
    }
    else{
      digitalWrite(7, LOW);
    }
    // Reset buflen to the size of the buffer for the next message
    buflen = sizeof(buf);
    strcat(myChar, TM);
    transmit(myChar);
  }
  
}

bool isPrintableChar(uint8_t c) {
  return (c >= 32 && c <= 126); // ASCII printable characters
}
