#define pinVRx A2
#define pinVRy A1
#define pinSW 2

void setup() {
  pinMode(pinVRx, INPUT);
  pinMode(pinVRy, INPUT);
  pinMode(pinSW, INPUT);

  Serial.begin(9600);
}

void loop() {
  int valorVRx = analogRead(pinVRx);
  int valorVRy = analogRead(pinVRy);
  bool statusSW = digitalRead(pinSW);

  Serial.print("Valor VRx: ");
  Serial.println(map(valorVRx, 0, 1023, 0, 179));

  Serial.print("Valor VRy: ");
  Serial.println(map(valorVRy, 0, 1023, 1023, 0));

  if (statusSW) {
    Serial.print("Botão [Solto]");
  } else {
    Serial.print("Botão [Apertado]");
  }

  Serial.println("============================================================");

  delay(500);
}
