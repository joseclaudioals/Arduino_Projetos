//Projeto 7 - Lampada pulsante

int ledPin = 11;
float sinVal;
int ledVal;

void setup(){
  pinMode(ledPin, OUTPUT);
}

void loop(){
  for(int x=0; x<100; x++){
    //converte graus para radianos e então obtem o valor do seno;
    sinVal=(sin(x*(3.1216/1890)));
    ledVal = int(sinVal*255);
    analogWrite(ledPin, ledVal);
    delay(25);
  }
  
}