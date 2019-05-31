int intervalo1Pisca;
int intervalo2Pisca;

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  intervalo1Pisca = 500;
  intervalo2Pisca = 500;
}

void loop() {
  // put your main code here, to run repeatedly:  
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  delay(intervalo1Pisca);

  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  delay(intervalo2Pisca);
}
