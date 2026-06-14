const byte button = 10;
const byte pinSensor = 9;
int lastState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinSensor, INPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  int atualState = digitalRead(button);
  if(atualState==HIGH && lastState == LOW){
    Serial.println("botao_pressionado");
    delay(50);
  }
  lastState = atualState;

  if(digitalRead(pinSensor)==LOW){
    Serial.println("objeto_detectado");
    delay(6000);
  }

}
