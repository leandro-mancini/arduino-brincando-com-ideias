int pinLED[9] = {12,11,10,9,8,7,6,5,4};
int numeroLED;
char digitado;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int i = 0; i <= 8; i++) {
    pinMode(pinLED[i], OUTPUT); 
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  digitado = ' ';

  numeroLED = 0;

  while (digitado != 'P') {
    digitalWrite(pinLED[numeroLED], LOW);
    
    numeroLED++;

    if (numeroLED > 8) {
      numeroLED = 0;
    }

    digitalWrite(pinLED[numeroLED], HIGH);

    if (Serial.available()) {
      digitado = Serial.read();
    }

    delay(50);
  }

  delay(5000);
}
