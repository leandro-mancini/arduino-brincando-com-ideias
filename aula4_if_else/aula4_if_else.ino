int pinVermelho = 10;
int pinAmarelo = 9;
int pinVerde = 8;
int pinBotao = 7;
int pinPedestreVermelhor = 3;
int pinPedestreVerde = 2;

int faseSemafaro;
int estadoBotao;
int estadoAnteriorBotao;

int tempoPisca;
int estadoPisca;

void setup() {
  // put your setup code here, to run once:

  pinMode(pinVermelho, OUTPUT);
  pinMode(pinAmarelo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinBotao, INPUT);
  pinMode(pinPedestreVermelhor, OUTPUT);
  pinMode(pinPedestreVerde, OUTPUT);

  faseSemafaro = 1;

  estadoAnteriorBotao = digitalRead(pinBotao);

  tempoPisca = 0;
  estadoPisca = HIGH;
}

void loop() {
  // put your main code here, to run repeatedly:

  estadoBotao = digitalRead(pinBotao);

  if ((estadoBotao == LOW) && (estadoAnteriorBotao == HIGH)) {
    if (faseSemafaro < 4) {
      faseSemafaro = faseSemafaro + 1;
    } else {
      faseSemafaro = 1;
    }
  }

  estadoAnteriorBotao = estadoBotao;

  if (faseSemafaro == 1) { // SEMAFARO ABERTO (VERDE)
    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinVermelho, LOW);
    digitalWrite(pinAmarelo, LOW);

    digitalWrite(pinPedestreVermelhor, HIGH);
    digitalWrite(pinPedestreVerde, LOW);
  }

  if (faseSemafaro == 2) { // SEMAFARO (AMARELO)
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinVermelho, LOW);
    digitalWrite(pinAmarelo, HIGH);
  }

  if (faseSemafaro == 3) { // SEMAFARO FECHADO (VERMELHO)
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinVermelho, HIGH);
    digitalWrite(pinAmarelo, LOW);

    digitalWrite(pinPedestreVermelhor, LOW);
    digitalWrite(pinPedestreVerde, HIGH);
  }

  if (faseSemafaro == 4) { // SEMAFARO PEDESTRE PISCANDO
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinVermelho, HIGH);
    digitalWrite(pinAmarelo, LOW);

    tempoPisca = tempoPisca + 1;

    if (tempoPisca == 400) {
      estadoPisca = !estadoPisca;
      tempoPisca = 0;
    }

    digitalWrite(pinPedestreVermelhor, estadoPisca);
    digitalWrite(pinPedestreVerde, LOW);
  }

  delay(100);
}
