// Compatible with CAN_TEST_1B


#include <FlexCAN.h>
#include <kinetis_flexcan.h>

const int baudRate = 50000;
const int ledPin = 13;
const int delayTime = 50;

FlexCAN myCAN(baudRate);
CAN_message_t message;
CAN_message_t rxmsg;

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  myCAN.begin();
  

}


void loop() {
  for(int i = 1; i < 50; i++)
  {
  message.buf[0] = i;
  message.id = 0x1;
  message.len = 1;
  myCAN.write(message);
  digitalWrite(ledPin,HIGH);
  delay(delayTime);
  digitalWrite(ledPin,LOW);
  delay(delayTime);  
  }
  if(myCAN.available())
  {
    Serial.println("message recieved");
    myCAN.read(rxmsg);
    Serial.println(rxmsg.buf[0]);
    Serial.println(rxmsg.buf[1]);
    
  }
}
