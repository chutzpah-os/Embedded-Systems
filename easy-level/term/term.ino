/*******************************************************************************
* RoboCore Arduino Pocket Kit - Lendo um Termistor
* Converte a resistência do termistor em temperatura e imprime na serial.
*******************************************************************************/

const int pino_termistor = A0; // pino onde o termistor está conectado
const float resistor_serie = 10000.0; // valor do resistor em serie com o termistor
const float resistencia_nominal = 10000.0; // resistencia nominal do termistor
const float temperatura_nominal = 25.0; // temperatura para resistência nominal
const float coeficiente_beta = 3950.0; // coeficiente beta do sensor (datasheet)
int leitura = 0; // variável para armazenar o valor lido pelo ADC
float resistencia = 0.0; // variável para armazenar a resistência
float temperatura = 0.0; // variável para armazenar a temperatura

void setup() {
  // Inicia e configura a Serial
  Serial.begin(9600); // 9600bps

  // configura o pino com termistor como entrada
  pinMode(pino_termistor, INPUT); // pino A0
}

void loop() {
  // le o valor de tensão no pino do termistor
  float leitura;
  leitura = analogRead(pino_termistor);

  // imprime valor lido pelo arduino (0 a 1023)
//  Serial.print("Leitura: ");
//  Serial.print(leitura);
//  Serial.print("\t"); // tabulacao

  // converte o valor para resistência
  resistencia = 1023 / leitura - 1; // (1023/ADC - 1)
  resistencia = resistor_serie / resistencia; // 10k / (1023/ADC - 1)
//  Serial.print("Resistencia: ");
//  Serial.print(leitura);
//  Serial.print("\t"); // tabulacao

  temperatura = resistencia / resistencia_nominal; // (R/Ro)
  temperatura = log(temperatura); // ln(R/Ro)
  temperatura /= coeficiente_beta; // 1/B * ln(R/Ro)
  temperatura += 1.0 / (temperatura_nominal + 273.15); // + (1/To)
  temperatura = 1.0 / temperatura; // inverso
  temperatura -= 273.15; // converte para graus Celsius

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print("*C");

  Serial.println(); // nova linha

  delay(1000); // aguarda 1 segundo para uma nova leitura
}