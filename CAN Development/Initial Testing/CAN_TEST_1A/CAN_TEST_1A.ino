// Compatible with CAN_TEST_1B


#include <FlexCAN.h>
#include <kinetis_flexcan.h>

const int baudRate = 50000;
const int ledPin = 13;
const int delayTime = 100;

FlexCAN myCAN(baudRate);
CAN_message_t message;
CAN_message_t rxmsg;

int8_t i,j;


void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  myCAN.begin();
  

}


void loop() {

    if(myCAN.available())
    {
      myCAN.read(rxmsg);
      i = rxmsg.buf[0];
      j = rxmsg.buf[1];
      Serial.println(ConstructValue(i,j));
    }
  }


int16_t ConstructValue(int8_t& i, int8_t& j)
{
  return (i << 8) | j;
}
