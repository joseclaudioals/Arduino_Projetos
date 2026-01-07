byte ledPin[]={13, 12, 11, 10, 9, 8, 7};
unsigned int ledAtual=0;
int ledDelay=100;
int mudarLed;
int direcao=1;
int quicadas=7;


void setup(){
  for(int i=0; i<7;i++){
    pinMode(ledPin[i], OUTPUT);
  }

  mudarLed=millis();
}

void loop(){
  if((millis()-mudarLed)>ledDelay){
    quicar();
    mudarLed=millis();
  }
}

void quicar(){
  for(int i=0; i<quicadas; i++){
    digitalWrite(ledPin[i], LOW);
  }
  digitalWrite(ledPin[ledAtual], HIGH);
  ledAtual+=direcao;
  if(ledAtual>=(quicadas-1)){direcao = -1;}
  if(ledAtual<=0){
    direcao = 1;
  	quicadas--;
    if(quicadas==1)
      quicadas=7;
  }
}