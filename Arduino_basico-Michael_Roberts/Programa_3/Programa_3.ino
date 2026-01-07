// define os pinos para os leds e o botão
int carRed = 12;
int carYellow = 11;
int carGreen = 10;
int pedRed = 9;
int pedGreen = 8;
int button = 2;
// determina o tempo na qual o pedestre poderá passar 
int travessia = 5000;
// variável que armazenará o valor de tempo
unsigned long changeTime;

void setup(){
  //iniciando o valor de cada pino
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(button, INPUT);

  // por padrão, o led verde dos carros e o led vermelho dos pedestres está acesso
  digitalWrite(carGreen, HIGH);
  digitalWrite(pedRed, HIGH);
}

void loop(){
  //a variável estado verifica se o bottão foi pressionado
  int estado = digitalRead(button);
  //caso o tempo armazenado na variavel "changeTime" seja maior que 2,5s o semaforo dos pedestres é ativado
  if(estado == HIGH &&(millis()-changeTime)>2500){
    //chama a função de mudar o semafoto 
    changeLights();
  }
}

void changeLights(){
  digitalWrite(carGreen, LOW); //apaga o led verde dos carros 
  digitalWrite(carYellow, HIGH); // acende o led amarelo dos carros 
  delay(2000); // 2s

  digitalWrite(carYellow, LOW); //led amarela dos carros é apagada
  digitalWrite(carRed, HIGH); //led vermelha dos carros é acesa
  delay(1000); // 1s

  digitalWrite(pedRed, LOW); //apaga a led vermelha dos pedestres
  digitalWrite(pedGreen, HIGH);//acende a led verde
  delay(travessia); //5s

//a led verde dos pedestres pisca 10 vezes antes do semaforo voltar a ficar vermelho
  for(int i=0; i<10; i++){
    digitalWrite(pedGreen, HIGH);
    delay(250);
    digitalWrite(pedGreen, LOW);
    delay(250);
  }
//acende o led vermelho dos pedestres
  digitalWrite(pedRed, HIGH);
  delay(500);
//acende o led amarelo e apaga o led
  digitalWrite(carYellow, HIGH);
  digitalWrite(carRed, LOW);
  delay(1000);

  digitalWrite(carGreen, HIGH); //acende o led verde dos carros
  digitalWrite(carYellow, LOW); //apaga o led amarelo dos carros

  changeTime=millis(); //armazena o valor em milisegundos desde que o botão foi apertado
}