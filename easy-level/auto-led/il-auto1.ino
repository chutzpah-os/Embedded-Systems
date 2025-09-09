/*******************************************************************************
* RoboCore Arduino Pocket Kit - Projeto Iluminação Automatizada
* Imprimir na Serial os valores lidos através do LDR.
*******************************************************************************/

const int pino_ldr = A0; // pino onde o LDR está conectado
int leitura = 0; // variável para armazenar o valor lido pelo ADC

void setup() {
  // Inicia e configura a Serial
  Serial.begin(9600); // 9600bps
  
  pinMode(pino_ldr, INPUT); // configura o pino com LDR como entrada
}

void loop() {
  // le o valor de tensão no pino do potenciômetro
  leitura = analogRead(pino_ldr);
  
  // imprime valor lido pelo arduino (0 a 1023)
  Serial.print("Leitura do LDR: ");
  Serial.print(leitura);
  
  Serial.println(); // nova linha
  
  delay(1000); // aguarda 1 segundo para uma nova leitura
}