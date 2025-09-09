/*******************************************************************************
*  Projeto RGB - Parte 2
* Combinar as três cores do LED RGB para formar outras cores diversas.
*******************************************************************************/

// pinos onde cada uma das cores estão conectados:
const int pino_r = 11; 
const int pino_g = 10; 
const int pino_b = 9;

// variáveis para salvar a intensidade de cada cor
int valor_r = 255; // vermelho (red)
int valor_g = 0; // verde (green)
int valor_b = 0; // blue (blue)

void setup() {
  // configura os pinos de cada cor como saída:
  pinMode(pino_r, OUTPUT);
  pinMode(pino_g, OUTPUT);
  pinMode(pino_b, OUTPUT);
  
  // inicializa LED em cor vemelha  e de máxima intensidade
  analogWrite(pino_r, valor_r);
  analogWrite(pino_g, valor_g);
  analogWrite(pino_b, valor_b);
}

void loop() {
  // aumenta a intensidade do LED verde
  for (valor_g = 0; valor_g < 255; valor_g=valor_g+5){
    analogWrite(pino_g, valor_g);
    delay(50); // aguarda 50ms 
  }
  
  // diminui a intensidade do LED vermelho
  for (valor_r = 255; valor_r > 0; valor_r=valor_r-5){
    analogWrite(pino_r, valor_r);
    delay(50); // aguarda 50ms 
  }
  
  // aumenta a intensidade do LED azul
  for (valor_b = 0; valor_b < 255; valor_b=valor_b+5){
    analogWrite(pino_b, valor_b);
    delay(50); // aguarda 50ms 
  }
  
  // diminui a intensidade do LED verde
  for (valor_g = 255; valor_g > 0; valor_g=valor_g-5){
    analogWrite(pino_g, valor_g);
    delay(50);
  }
  
  // aumenta a intensidade do LED vermelho
  for (valor_r = 0; valor_r < 255; valor_r=valor_r+5){
    analogWrite(pino_r, valor_r);
    delay(50); // aguarda 50ms 
  }

}
