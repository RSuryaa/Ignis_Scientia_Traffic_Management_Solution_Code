#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
//Transmit at pin 12; receive at pin 11;
RH_ASK driver;

void setup()
{
    Serial.begin(9600);	  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}
char Lol[30]="Red Signal";
char Haha[30]="Green Signal";
void loop()
{
  transmit(Lol);
  delay(2000);
  transmit(Haha);
  delay(2000);
}
void transmit(char *data)
{
    const char *msg = data;
    driver.send((uint8_t *)msg, strlen(msg));
    Serial.println("Sent");
    driver.waitPacketSent();
}
