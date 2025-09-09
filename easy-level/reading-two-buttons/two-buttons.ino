/*******************************************************************************
* Lendo dois Botões
* Acender os LEDs quando os botões forem pressionados e apagá-los quando os 
* botões forem soltos.
*******************************************************************************/

const int pino_botao1 = 2; // pino onde o botao 1 está conectado
const int pino_botao2 = 3; // pino onde o botao 2 está conectado
const int pino_led1 = 11; // pino onde o LED 1 está conectado
const int pino_led2 = 12; // pino onde o LED 2 está conectado
int estado_botao1 = 0; // variável para armazenar o estado do botão 1
int estado_botao2 = 0; // variável para armazenar o estado do botão 2

void setup(){
  pinMode(pino_botao1, INPUT); // configura o pino com o botão 1 como entrada
  pinMode(pino_botao2, INPUT); // configura o pino com o botão 2 como entrada
  pinMode(pino_led1, OUTPUT); // configura o pino com o LED 1 como saída
  pinMode(pino_led2, OUTPUT); // configura o pino com o LED 2 como saída
}

void loop(){
  /* o novo estado do botão vai ser igual ao que o Arduino
  ler no pino onde está o botão. Poderá ser ALTO (HIGH)
  se o botão estiver pressionado, ou BAIXO (LOW) se o botão estiver solto */
  estado_botao1 = digitalRead(pino_botao1);
  estado_botao2 = digitalRead(pino_botao2);

  if (estado_botao1 == HIGH){ // se botão 1 estiver pressionado (HIGH)
    digitalWrite(pino_led1, HIGH); // acende o LED 1 do pino 11.
  }
  else{ //se não estiver pressionado
    digitalWrite(pino_led1, LOW); // apaga o LED 1 do pino 11.
  }

  if (estado_botao2 == HIGH){ // se botão 2 estiver pressionado (HIGH)
    digitalWrite(pino_led2, HIGH); // acende o LED 2 do pino 12.
  }
  else{ //se não estiver pressionado
    digitalWrite(pino_led2, LOW); // apaga o LED 2 do pino 12.
  }
}