void setup() {
  // put your setup code here, to run once:
  //pinMode(0, OUTPUT);
  pinMode(2, OUTPUT); //Abrir a porta 2 para saída
  pinMode(12, OUTPUT); //Abrir a porta 4 para saída
  pinMode(5, OUTPUT); //Abrir a porta 5 para saída
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH); //Ativar a porta
  //digitalWrite(0, HIGH);
  delay(3000); //Esperar 1 segundo
  digitalWrite(2, LOW); //Desativar a porta
  //digitalWrite(0, LOW);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  digitalWrite(5, HIGH);
  delay(2000);
  digitalWrite(5, LOW);
}