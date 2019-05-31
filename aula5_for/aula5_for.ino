int pinLED[9] = {12,11,10,9,8,7,6,5,4};
int numeroLED;

void setup() {
  // put your setup code here, to run once:

  for (int i = 0; i <= 8; i++) {
    pinMode(pinLED[i], OUTPUT); 
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  for (numeroLED = 0; numeroLED <= 8; numeroLED++) {
    digitalWrite(pinLED[numeroLED], HIGH);

    delay(50);
  }

  for (numeroLED = 8; numeroLED >= 0; numeroLED--) {
    digitalWrite(pinLED[numeroLED], LOW);

    delay(100);
  }
}
