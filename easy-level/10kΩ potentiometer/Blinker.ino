/*******************************************************************************
*  Pisca-Pisca
* Usar um potenciômetro para controlar o período com que um LED pisca.
*******************************************************************************/

const int pino_potenciometro = A0; // pino onde o pontenciômetro está conectado
const int pino_led = 11; // pino onde o LED está conectado
int leitura = 0; // variável para armazenar o valor lido pelo ADC

void setup() {
  pinMode(pino_potenciometro, INPUT); // configura o pino com potenciômetro como entrada
  pinMode(pino_led, OUTPUT); // configura o pino com o LED como saída
}

void loop() {
  // le o valor de tensão no pino do potenciômetro
  leitura = analogRead(pino_potenciometro);

  digitalWrite(pino_led, HIGH); // Aciona o LED
  delay(leitura); // Aguarda o valor lido no pino do potenciômetro em milissegundos
  digitalWrite(pino_led, LOW); // Apaga o LED
  delay(leitura); // Aguarda o valor lido no pino do potenciômetro em milissegundos
}