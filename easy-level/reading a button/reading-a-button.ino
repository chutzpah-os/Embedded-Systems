/*******************************************************************************
*- Lendo um Botão
* Acende o LED quando o botão é pressionado e o apaga quando o botão é solto.
*******************************************************************************/

const int pino_botao = 2; // pino onde o botao está conectado
const int pino_led = 11; // pino onde o LED está conectado
int estado_botao = 0; // variável para armazenar o estado do botão
    
void setup(){
  pinMode(pino_botao, INPUT); // configura o pino com o botão como entrada
  pinMode(pino_led, OUTPUT); // configura o pino com o LED como saída
}

void loop(){
  /* o novo estado do botão vai ser igual ao que o Arduino 
  ler no pino onde está o botão. Poderá ser ALTO (HIGH) 
  se o botão estiver pressionado, ou BAIXO (LOW) se o botão estiver solto */
  estado_botao = digitalRead(pino_botao); 
  
  if (estado_botao == HIGH){ // se botão estiver pressionado (HIGH)
    digitalWrite(pino_led, HIGH); // acende o LED do pino 11.
  }
  else{ // se não estiver pressionado (LOW)
    digitalWrite(pino_led, LOW); // apaga o LED do pino 11.
  }
}