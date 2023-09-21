#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
//Transmit at pin 11; receive at pin 12;
RH_ASK driver;

void setup()
{
    Serial.begin(9600);	  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}
char Lol[30]="ABCDEFGHI";
char Haha[30]="Hey dude, how are you?";
void loop()
{
  transmit(Lol);
  transmit(Haha);
}
void transmit(char *data)
{
    const char *msg = data;
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(100);
}
