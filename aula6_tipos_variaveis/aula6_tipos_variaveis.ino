int valorX;
int valorY;
int valorZ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  valorX = 10;
  valorY = 20;
  valorZ = valorX + valorY;

  Serial.print("ValorX=");
  Serial.println(valorX);
  Serial.print("ValorY=");
  Serial.println(valorY);
  Serial.print("ValorZ=");
  Serial.println(valorZ);
}

void loop() {
  // put your main code here, to run repeatedly:

}
