/******************************************************************************** Mostra a temperatura na barra gráfica de LEDs e emite um alarme sonoro quando
* a temperatura está acima de um valor predefinido.
*******************************************************************************/

// pinos onde os leds da barra gráfica de leds estão conectados
const int pinos_leds[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
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

  // configura os pinos da barra gráfica de LEDs como saída
  for(int x = 0; x < 10; x++) {
    pinMode(pinos_leds[x], OUTPUT);
  }
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

  if (temperatura > 23.5) { // Se a temperatura for maior que 23.5*C
    digitalWrite(pinos_leds[0], HIGH); // Acende o LED 1
  }
  else { // Senão
    digitalWrite(pinos_leds[0], LOW); // Apaga o LED 1
  }

  if (temperatura > 24.0) { // Se a temperatura for maior que 24.0*C
    digitalWrite(pinos_leds[1], HIGH); // Acende o LED 2
  }
  else { // Senão
    digitalWrite(pinos_leds[1], LOW); // Apaga o LED 2
  }

  if (temperatura > 24.5) { // Se a temperatura for maior que 24.5*C
    digitalWrite(pinos_leds[2], HIGH); // Acende o LED 3
  }
  else { // Senão
    digitalWrite(pinos_leds[2], LOW); // Apaga o LED 3
  }

  if (temperatura > 25.0) { // Se a temperatura for maior que 25.0*C
    digitalWrite(pinos_leds[3], HIGH); // Acende o LED 4
  }
  else { // Senão
    digitalWrite(pinos_leds[3], LOW); // Apaga o LED 4
  }

  if (temperatura > 25.5) { // Se a temperatura for maior que 25.5*C
    digitalWrite(pinos_leds[4], HIGH); // Acende o LED 5
  }
  else { // Senão
    digitalWrite(pinos_leds[4], LOW); // Apaga o LED 5
  }

  if (temperatura > 26.0) { // Se a temperatura for maior que 26.0*C
    digitalWrite(pinos_leds[5], HIGH); // Acende o LED 6
  }
  else { // Senão
    digitalWrite(pinos_leds[5], LOW); // Apaga o LED 6
  }

  if (temperatura > 26.5) { // Se a temperatura for maior que 26.5*C
    digitalWrite(pinos_leds[6], HIGH); // Acende o LED 7
  }
  else { // Senão
    digitalWrite(pinos_leds[6], LOW); // Apaga o LED 7
  }

  if (temperatura > 27.0) { // Se a temperatura for maior que 27.0*C
    digitalWrite(pinos_leds[7], HIGH); // Acende o LED 8
  }
  else { // Senão
    digitalWrite(pinos_leds[7], LOW); // Apaga o LED 8
  }

  if (temperatura > 27.5) { // Se a temperatura for maior que 27.5*C
    digitalWrite(pinos_leds[8], HIGH); // Acende o LED 9
  }
  else { // Senão
    digitalWrite(pinos_leds[8], LOW); // Apaga o LED 9
  }

  if (temperatura > 28.0) { // Se a temperatura for maior que 28.0*C
    digitalWrite(pinos_leds[9], HIGH); // Acende o LED 10
    tone(pino_buzzer, 2000); // Aciona o buzzer
  }
  else { // Senão
    digitalWrite(pinos_leds[9], LOW); // Apaga o LED 10
    noTone(pino_buzzer); // Desliga o buzzer
  }

  delay(1000); // aguarda 1 segundo para uma nova leitura
}