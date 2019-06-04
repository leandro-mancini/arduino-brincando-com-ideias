unsigned char letra;

void setup() {
  Serial.begin(9600);

  char especial = '\n';

  Serial.println();
  Serial.print("Primeira frase.\0Segunda frase.");
  Serial.print(especial);
  Serial.print("\tTerceira frase.");
}

void loop() {
  // put your main code here, to run repeatedly:

}
