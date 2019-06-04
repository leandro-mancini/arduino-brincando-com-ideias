#define pinLedVd 10
#define pinLedVm 8
#define pinBotao 2

bool estadoBotao = true;
bool estAntBotao = true;
bool estadoPisca = false;

unsigned long delay1 = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(pinLedVd, OUTPUT);
  pinMode(pinLedVm, OUTPUT);
  pinMode(pinBotao, INPUT_PULLUP);

  digitalWrite(pinLedVd, HIGH);
}

void loop() {
  estadoBotao = digitalRead(pinBotao);

  if (!estadoBotao && estAntBotao) {
    estadoPisca = !estadoPisca;
  }

  estAntBotao = estadoBotao;

  Serial.print("Estado pisca: ");
  Serial.println(estadoPisca);

  if (estadoPisca) {
    if ((millis() - delay1) >= 500) {
      digitalWrite(pinLedVm, HIGH);
    }

    if ((millis() - delay1) < 500) {
      digitalWrite(pinLedVm, LOW);
    }

    if ((millis() - delay1) >= 1000) {
      delay1 = millis(); 
    }

    Serial.print("Valor do Delay 1: ");
    Serial.println(delay1);
  } else {
    digitalWrite(pinLedVm, LOW);
  }

  delay(10);
}
