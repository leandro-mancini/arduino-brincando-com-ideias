String textoRecebido = "";
unsigned long delay1 = 0;

void setup() {  
  Serial.begin(9600);  
}

void loop() {
  char caracter;
  
  if (Serial.available()) {
     caracter = Serial.read();
     textoRecebido += caracter;
     delay1 = millis();
  }

  if (((millis() - delay1) > 10) && (textoRecebido != "")) {
     Serial.print("Texto digitado: ");
     Serial.println(textoRecebido);

     textoRecebido = "";
  }
}
