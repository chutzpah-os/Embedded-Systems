* Emite um alarme sonoro quando a temperatura está fora de um intervalo.
*******************************************************************************/

const int pino_termistor = A0; // pino onde o termistor está conectado
const int pino_buzzer = 2; // pino onde o buzzer está conectado
const float resistor_serie = 10000.0; // valor do resistor em serie com o termistor
const float resistencia_nominal = 10000.0; // resistencia nominal do termistor
const float temperatura_nominal = 25.0; // temperatura para resistência nominal
const float coeficiente_beta = 3950.0; // coeficiente beta do sensor (datasheet)
int leitura = 0; // variável para armazenar o valor lido pelo ADC
float resistencia = 0.0; // variável para armazenar a resistência
float temperatura = 0.0; // variável para armazenar a temperatura

void setup() {
  pinMode(pino_termistor, INPUT); // configura o pino com termistor como entrada
  pinMode(pino_buzzer, OUTPUT); // configura o pino com o buzzer como saída
}

void loop() {
  // le o valor de tensão no pino do termistor
  float leitura;
  leitura = analogRead(pino_termistor);

  // converte o valor para resistência
  resistencia = 1023 / leitura - 1; // (1023/ADC - 1)
  resistencia = resistor_serie / resistencia; // 10k / (1023/ADC - 1)

  // converte o valor para temperatura
  temperatura = resistencia / resistencia_nominal; // (R/Ro)
  temperatura = log(temperatura); // ln(R/Ro)
  temperatura /= coeficiente_beta; // 1/B * ln(R/Ro)
  temperatura += 1.0 / (temperatura_nominal + 273.15); // + (1/To)
  temperatura = 1.0 / temperatura; // inverso
  temperatura -= 273.15; // converte para graus Celsius

  if (temperatura > 30) { // Se a temperatura for maior que 30*C
    tone(pino_buzzer, 261); // Aciona buzzer
  }
  else if (temperatura < 20) { // Se a temperatura for menor que 20*C
    tone(pino_buzzer, 493); // Aciona buzzer
  }
  else { // Se a temperatura estiver dentro dos limites
    noTone(pino_buzzer); // Desliga buzzer
  }

  delay(1000); // aguarda 1 segundo para uma nova leitura
}