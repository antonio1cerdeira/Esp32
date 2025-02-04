#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run 'make menuconfig' to and enabled it
#endif

BluetoothSerial SerialBT;
boolean estado = 0;
unsigned long myTime;
const unsigned long intervalo = 1000;
unsigned long tempoAnterior = 0;
String myString;


#define FORCA_PIN 12
int fsrValue = 0;
int fsrVoltage = 0;

const int buzzerPin = 33;
int touchValue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SerialBT.begin("ESP32_Rui_Costa");
  Serial.println("Ligação disponível");
  pinMode(4, INPUT);           //Abrir a porta 4 para a entrada do botão
  pinMode(2, OUTPUT);          //Abrir a porta 2 para saída verde
  pinMode(19, OUTPUT);         //Abrir a porta 19 para saída azul
  pinMode(15, OUTPUT);         //Abrir a porta 15 para saída vermelho
  pinMode(buzzerPin, OUTPUT);  //Abrir a porta 33 para o buzzer
}

void loop() {

  unsigned long tempoAtual = millis(); //Guarda os milissegundos passados na variavel tempoAtual

  if (tempoAtual - tempoAnterior >= intervalo) { //Se o tempoAtual - tempoAnterior (que a primeira vez é zero) for maior que o intervalo, executa o programa
    tempoAnterior = tempoAtual; //Atualiza a variavel tempoAnterior com os milissegundos passados, igualando esta variável ao tempoAtual

    tone(buzzerPin, 0); //Desliga o buzzer no inicio do loop

    touchValue = touchRead(4); //Guarda o valor do botão na variavel
    if (touchValue < 20) { //Se o valor for inferior a 20 
      estado = !estado; //Muda o estado
    }

    if (estado == 1) { //Se o estado for verdadeiro
      digitalWrite(2, LOW); //Desliga os Leds todos
      digitalWrite(19, LOW);
      digitalWrite(15, LOW);

      fsrValue = analogRead(FORCA_PIN); //Lê o valor analógico
      fsrVoltage = map(fsrValue, 0, 1023, 0, 5000); //Lê o valor digitalPWM
      myString = "FSR: " + String(fsrValue) + ", " + String(fsrVoltage) + " mV"; //Construir a String

      if (fsrValue < 100) { //Adiciona à string o comentário correspondente
        myString = myString + " - No squeeze";
      } else if (fsrValue < 500) { //Liga o led verde
        myString = myString + " - Light squeeze";
        digitalWrite(2, HIGH);
      } else if (fsrValue < 1000) { //Liga o led azul
        myString = myString + " - Medium squeeze";
        digitalWrite(19, HIGH);
      } else if (fsrValue < 2000) { //Liga o led vermelho
        myString = myString + " - Big squeeze";
        digitalWrite(15, HIGH);
      } else { //Liga todos os Leds e faz som
        myString = myString + " - Very Big squeeze";
        digitalWrite(2, HIGH);
        digitalWrite(19, HIGH);
        digitalWrite(15, HIGH);
        tone(buzzerPin, 5000);
      }
      //Imprime os valores no Serial e no Telemóvel
      Serial.println(myString);
      SerialBT.println(myString);

    } else { //Se o estado for falso o programa deve imprimir "desligado"
      Serial.println("Desligado");
      SerialBT.println("Desligado");
    }
  }
}