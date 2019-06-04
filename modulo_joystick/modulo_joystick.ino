#include <Servo.h>

#define pinVRx A2
#define pinVRy A1
#define pinSW 2
#define pinServo 8

Servo myServo;

void setup() {
  pinMode(pinVRx, INPUT);
  pinMode(pinVRy, INPUT);
  pinMode(pinSW, INPUT);

  myServo.attach(pinServo);

  Serial.begin(9600);
}

void loop() {
  int valorVRx = analogRead(pinVRx);
  int valorVRy = analogRead(pinVRy);
  bool statusSW = digitalRead(pinSW);
  byte angulo = map(valorVRx, 0, 1023, 0, 179);

  myServo.write(angulo);

  Serial.print("Valor VRx: ");
  Serial.print(map(valorVRx, 0, 1023, 0, 179));

  Serial.print("  Valor VRy: ");
  Serial.print(map(valorVRy, 0, 1023, 1023, 0));

  if (statusSW) {
    Serial.println("  Botão [Solto]");
  } else {
    Serial.println("  Botão [Apertado]");
  }

  Serial.println("============================================================");

  delay(1000);
}
