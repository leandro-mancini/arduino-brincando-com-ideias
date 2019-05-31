void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  // pinMode(7, INPUT); // Ligar no 5v com resistor
  pinMode(7, INPUT_PULLUP); // Ligar no GND sem o resistor
}

void loop() {
  // put your main code here, to run repeatedly:  
  int estadoBotao;

  estadoBotao = digitalRead(7);
  
  digitalWrite(10, estadoBotao);
  digitalWrite(9, !estadoBotao);
}
