// LED ligada ao pino 10
int ledPin = 10;

// executa uma vez, quando sketch inicia 
void setup(){
  //define o pino como saída
  pinMode(ledPin, OUTPUT);
}

//executa repetidas vezes
void loop(){
  //3 pontos
  for(int i=0; i<3; i++){
    digitalWrite(ledPin, HIGH);
    delay(150);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  //espera 100ms para marcar o intervalo entre letras 
  delay(100);

  //3 traços
  for(int i=0; i<3; i++){
    digitalWrite(ledPin, HIGH);
    delay(400);
    digitalWrite(ledPin, LOW);
    delay(100);
  }

  //espera 100ms para marcar o intervalo entre letras 
  delay(100);

  //3 pontos
  for(int i=0; i<3; i++){
    digitalWrite(ledPin, HIGH);
    delay(150);
    digitalWrite(ledPin, LOW);
    delay(100);
  }

  //espera 5 segundos antes de repetir o sinal SOS
  delay(5000);
}