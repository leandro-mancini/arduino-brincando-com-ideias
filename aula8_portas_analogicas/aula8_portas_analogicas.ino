int pinLED[9] = {12,11,10,9,8,7,6,5,4};

float valorLDR;
float valorMinimo = 85;
float valorMaximo = 1020;
float luminosidade;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int i = 0; i <= 8; i++) {
    pinMode(pinLED[i], OUTPUT); 
  }

  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  valorLDR = analogRead(A0);

  luminosidade = ((valorLDR - valorMinimo) / (valorMaximo - valorMinimo)) * 10;
  luminosidade = (luminosidade - 10) * -1;

  for (int i = 0; i <= 8; i++) {
    if (i < luminosidade) {
      digitalWrite(pinLED[i], HIGH);
    } else {
      digitalWrite(pinLED[i], LOW);
    }
  }

  delay(500);
}
