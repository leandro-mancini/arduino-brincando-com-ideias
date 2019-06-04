#define pinLedVm 2
#define pinLedVd 3
#define pinBotao 4

bool pisca = false;

bool leBotao(int porta);
void piscaLED(int porta, int tempo);

void setup() {
  pinMode(pinLedVm, OUTPUT);
  pinMode(pinLedVd, OUTPUT);
  pinMode(pinBotao, INPUT_PULLUP);
}

void loop() {
  if (leBotao(pinBotao)) {
    pisca = !pisca;
  }

  if (pisca) {
    piscaLED(pinLedVd, 100);
    piscaLED(pinLedVm, 500);
  }
}

bool leBotao(int porta) {
  static bool estadoAnterior[14] = {true,true,true,true,true,true,true,true,true,true,true,true,true,true};
  
  bool estadoBotao = digitalRead(porta);
  bool ligado = false;

  if (!estadoBotao && estadoAnterior[porta]) {
    ligado = true;
  }

  estadoAnterior[porta] = estadoBotao;

  return ligado;
}

void piscaLED(int porta, int tempo) {
  static unsigned long _delay[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

  if ((millis() - _delay[porta]) < tempo) {
    digitalWrite(porta, HIGH);
  } else {
    digitalWrite(porta, LOW);
  }

  if ((millis() - _delay[porta]) >= (tempo * 2)) {
    _delay[porta] = millis();
  }
}
