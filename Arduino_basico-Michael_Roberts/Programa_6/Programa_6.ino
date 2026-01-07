// Projeto 5 - Iluminação de Led Sequencial 
byte ledpin[]={7, 8, 9, 10, 11, 12, 13}; //array com os pinos de cada led 
int leddelay; 
int direcao=1; // define a direção que a led vai ir 
int ledAtual=0; // define o led que será acesso 
unsigned long changeTime; //armazena o tempo
int potPin =A1;

void setup() {
  //define toodos os pinos como saida
  for(int i=0; i<7; i++){
    pinMode(ledpin[i], OUTPUT);
  }
 changeTime = millis();
}

void loop() {
  leddelay=analogRead(potPin);
  //verifica se o tempo de cada iteração é maior que o tempo de delay
  if((millis()-changeTime)>leddelay){
    changeLED(); 
    changeTime=millis();
  }
}

void changeLED(){
  //apaga todas as leds
  for(int i=0;i<7; i++){
    digitalWrite(ledpin[i], LOW);
  }
  //acende a led atual
  digitalWrite(ledpin[ledAtual], HIGH);
  //incrementa para a prox iteração
  ledAtual+=direcao;
  //verifica se chegou no limite das leds para mudar a direção
  if(ledAtual==6)
    direcao= -1;
  if(ledAtual==0)
    direcao= 1;
}
