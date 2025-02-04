#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run 'make menuconfig' to and enabled it
#endif
BluetoothSerial SerialBT;
char valor;
char valor1;
unsigned long myTime;
const unsigned long intervalo = 100;
unsigned long tempoAnterior = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialBT.begin("ESP32_CerdeiraDev");
  Serial.println("Ligação disponível");
  pinMode(2, OUTPUT);
}

void loop() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;

    valor = (char)SerialBT.read();
    valor1 = (char)Serial.read();

    if (Serial.available()) {
      SerialBT.write(valor1);
      Serial.println(valor1);
      if (valor1 == '1') {
        digitalWrite(2, HIGH);
      }
      if (valor1 == '0') {
        digitalWrite(2, LOW);
      }
    }
    if (SerialBT.available()) {
      Serial.println(valor);
      if (valor == '1') {
        digitalWrite(2, HIGH);
      }
      if (valor == '0') {
        digitalWrite(2, LOW);
      }
    }
  }
}