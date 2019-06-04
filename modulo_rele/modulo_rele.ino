#define rele1 7
#define pinVm 2
#define pinVd 3

bool leBotao(int porta);

bool ligado;

void setup() {
  Serial.begin(9600);
  
  pinMode(rele1, OUTPUT);
  pinMode(pinVm, INPUT_PULLUP);
  pinMode(pinVd, INPUT_PULLUP);
}

void loop() {
  digitalWrite(rele1, HIGH);
  delay(1000);
  digitalWrite(rele1, LOW);
  delay(1000);
  
  /*
  bool botaoVm = digitalRead(pinVm);
  bool botaoVd = digitalRead(pinVd);

  if (leBotao(pinVm)) {
    ligado = false;
  }

  if (leBotao(pinVd)) {
    ligado = true;
  }

  if (!ligado) {
    digitalWrite(rele1, HIGH);
    Serial.println("Ligado");
  } else {
    digitalWrite(rele1, LOW);
    Serial.println("Desligado");
  }

  delay(300);
  */
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
