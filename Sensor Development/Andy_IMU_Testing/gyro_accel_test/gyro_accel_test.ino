#include <FlexCAN.h>
#include <kinetis_flexcan.h>
#include<Wire.h>
const int MPU=0x68;  // I2C address of the MPU-6050
int16_t GyX;
int delayTime = 10;
FlexCAN myCAN(50000);
CAN_message_t message;


void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
  myCAN.begin();

}
void loop(){
  message.id = 0x1;
  message.len = 2;
  Wire.beginTransmission(MPU);
  Wire.write(0x43);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,2,true);  // request a total of 14 registers
  //GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  int8_t i = Wire.read();
  int8_t j = Wire.read();
  Wire.endTransmission(true);
  message.buf[0] = i;
  message.buf[1] = j;
  if(myCAN.write(message))
    Serial.println("Cats");
    Serial.println(i<<8|j,BIN);
  delay(delayTime);
}
