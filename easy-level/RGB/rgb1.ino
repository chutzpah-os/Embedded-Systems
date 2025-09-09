/*******************************************************************************
*  Projeto RGB - Parte 1
* Entender como os LEDs RGB funcionam e como acionar cada uma de suas 3 cores.
*******************************************************************************/

// pinos onde cada uma das cores estão conectados:
const int pino_r = 11; 
const int pino_g = 10; 
const int pino_b = 9; 

void setup() {
  // configura os pinos de cada cor como saída:
  pinMode(pino_r, OUTPUT);
  pinMode(pino_g, OUTPUT);
  pinMode(pino_b, OUTPUT);
}

void loop() {
  // aciona o LED na cor vermelha:
  digitalWrite(pino_r, HIGH);
  digitalWrite(pino_g, LOW);
  digitalWrite(pino_b, LOW);
  delay(500); // aguarda 500ms 
  
  // aciona o LED na cor verde:
  digitalWrite(pino_r, LOW);
  digitalWrite(pino_g, HIGH);
  digitalWrite(pino_b, LOW);
  delay(500); // aguarda 500ms 

  // aciona o LED na cor azul:
  digitalWrite(pino_r, LOW);
  digitalWrite(pino_g, LOW);
  digitalWrite(pino_b, HIGH);
  delay(500); // aguarda 500ms 
}