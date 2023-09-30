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
char Red[30]="Red Signal";
char Green[30]="Green Signal";
void loop()
{
  transmit(Red);
  delay(1000);
  transmit(Red);
  delay(1000);
  transmit(Red);
  delay(1000);
  transmit(Red);
  delay(1000);
  transmit(Red);
  delay(1000);
  transmit(Red);
  delay(1000);
  transmit(Red);
  delay(1000);
  transmit(Red);
  delay(1000);
  transmit(Red);
  delay(1000);
  transmit(Red);
  delay(1000);
  transmit(Green);
  delay(1000);
  transmit(Green);
  delay(1000);
  transmit(Green);
  delay(1000);
  transmit(Green);
  delay(1000);
  transmit(Green);
  delay(1000);
  transmit(Green);
  delay(1000);
  transmit(Green);
  delay(1000);
  transmit(Green);
  delay(1000);
  transmit(Green);
  delay(1000);
  transmit(Green);
  delay(1000);
}
void transmit(char *data)
{
    const char *msg = data;
    driver.send((uint8_t *)msg, strlen(msg));
    Serial.println("Sent");
    Serial.println(data);
    driver.waitPacketSent();
}
