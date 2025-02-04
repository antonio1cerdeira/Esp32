
// Sensor com interface I2C

#include <Wire.h>

#define SRF08_ADDRESS 0x70  //E0>>1= 70 para calcular um bit, bit calculator shift para a direita
#define SOFT_REGISTER 0x00  
#define CMD_REGISTER 0x00
#define RANGE_REGISTER 0x02 // porta sensor de distancia
#define LIGHT_REGISTER 0x01 // porta sensor de luz

void setup() {
  Wire.begin(); 
  Serial.begin(9600); 
  delay(100); 
  Serial.println(getSoftRevision()); 
}

void loop() {
  int range = getRange();
  int light = getLight();
  String s = "Range: " + String(range) + " Light: " + String(light);
  Serial.println(s); 
}

int getSoftRevision(){

  Wire.beginTransmission(SRF08_ADDRESS);
  Wire.write(SOFT_REGISTER);
  Wire.endTransmission();

  Wire.requestFrom(SRF08_ADDRESS, 1); 
  while(Wire.available() < 1);
  int software = Wire.read();

  return software;
}

int getRange(){

  Wire.beginTransmission(SRF08_ADDRESS);
  Wire.write(CMD_REGISTER);
  Wire.write(0x51); 
  Wire.endTransmission(); 
  delay(100); 

  
  Wire.beginTransmission(SRF08_ADDRESS);
  Wire.write(RANGE_REGISTER);
  Wire.endTransmission(); 

  Wire.requestFrom(SRF08_ADDRESS, 2);
  while(Wire.available() <2); 
  byte highByte = Wire.read();
  byte lowByte = Wire.read();


  int range = (highByte <<8) + lowByte;

  return range;

}

int getLight(){

  Wire.beginTransmission(SRF08_ADDRESS);
  Wire.write(LIGHT_REGISTER);
  Wire.endTransmission();

  Wire.requestFrom(SRF08_ADDRESS, 1); 
  while(Wire.available() < 1); 
  int light = Wire.read(); 

  return light;
  
}