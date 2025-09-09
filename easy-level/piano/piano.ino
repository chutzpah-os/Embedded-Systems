/*******************************************************************************
* Projeto Piano
* Acender um LED e tocar uma nota musical diferente para cada botão que for 
* pressionado.
*******************************************************************************/

const int pino_botao1 = 2; // pino onde o botao 1 está conectado
const int pino_botao2 = 3; // pino onde o botao 2 está conectado
const int pino_buzzer = 10; // pino onde o buzzer está conectado
const int pino_led1 = 11; // pino onde o LED 1 está conectado
const int pino_led2 = 12; // pino onde o LED 2 está conectado
int estado_botao1 = 0; // variável para armazenar o estado do botão 1
int estado_botao2 = 0; // variável para armazenar o estado do botão 2

void setup(){
  pinMode(pino_led1, OUTPUT); // configura o pino com o LED 1 como saída
  pinMode(pino_led2, OUTPUT); // configura o pino com o LED 2 como saída
  pinMode(pino_buzzer, OUTPUT); // configura o pino com o buzzer como saída
  pinMode(pino_botao1, INPUT); // configura o pino com o botão 1 como entrada
  pinMode(pino_botao2, INPUT); // configura o pino com o botão 2 como entrada
}

void loop(){
  /* o novo estado do botão vai ser igual ao que o Arduino
  ler no pino onde está o botão. Poderá ser ALTO (HIGH)
  se o botão estiver pressionado, ou BAIXO (LOW) se o botão estiver solto */
  estado_botao1 = digitalRead(pino_botao1);
  estado_botao2 = digitalRead(pino_botao2);

  // se os dois botões estiverem soltos (LOW)
  if (!estado_botao1 && !estado_botao2){
    digitalWrite(pino_led1, LOW); // apaga o LED 1 do pino 11.
    digitalWrite(pino_led2, LOW); // apaga o LED 2 do pino 12.
    noTone(pino_buzzer); // para a frequência do pino do buzzer
  }

  // se botão 1 estiver pressionado (HIGH) e o botão 2 estiver solto (LOW)
  if (estado_botao1 && !estado_botao2){
    digitalWrite(pino_led1, HIGH); // acende o LED 1 do pino 11.
    digitalWrite(pino_led2, LOW); // apaga o LED 2 do pino 12.
    tone(pino_buzzer, 261); // tone(pino, frequência(Hz));
  }

  // se botão 2 estiver pressionado (HIGH) e o botão 1 estiver solto (LOW)
  if (estado_botao2 && !estado_botao1){
  	digitalWrite(pino_led1, LOW); // apaga o LED 1 do pino 11.
    digitalWrite(pino_led2, HIGH); // acende o LED 2 do pino 12.
    tone(pino_buzzer, 391); // tone(pino, frequência(Hz));
  }

  // se os dois botões estiverem pressionados (HIGH)
  if (estado_botao1 && estado_botao2){
    digitalWrite(pino_led1, HIGH); // acende o LED 1 do pino 11.
    digitalWrite(pino_led2, HIGH); // acende o LED 2 do pino 12.
    tone(pino_buzzer, 440); // tone(pino, frequência(Hz));
  }

  /* Frequências
   * Dó  - 261,63Hz
   * Ré  - 293,66Hz
   * Mi  - 329,63Hz
   * Fá  - 349,23Hz
   * Sol - 391,99Hz
   * Lá  - 440,00Hz
   * Si  - 493,88Hz
   */
}