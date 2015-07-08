// Compatible with CAN_TEST_1A

#include <FlexCAN.h>
#include <kinetis_flexcan.h>

const int baudRate = 50000;
const int ledPin = 13;
const int delayTime = 1000;
int count = 0;
FlexCAN myCAN(baudRate);
CAN_message_t message;
CAN_message_t rxmsg;

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  digitalWrite(ledPin,HIGH);
  myCAN.begin();
  

}
void loop() {
  if(myCAN.available())
  {
    myCAN.read(rxmsg);
    Serial.println(rxmsg.buf[0]);
    if(rxmsg.buf[0] == 49)
    {
     Serial.println("message Sent");
     message.buf[0] = count;
     message.buf[1] = count + 1;
     message.len = 2;
     message.id = 0x2;
     myCAN.write(message);
     count++;
      
    }
  }
}
