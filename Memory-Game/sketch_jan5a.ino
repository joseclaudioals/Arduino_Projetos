int pinLeds[]={10, 11, 12, 13};
int pinButton[]={2, 3, 4, 5};
int wishedSequel[4];
int delayTm=500;

#define BUZZER 7
#define LEDVIC 6

void setup() {
  for(int i=0; i<4; i++){
    pinMode(pinLeds[i], OUTPUT);
    pinMode(pinButton[i], INPUT);
  }
  
  pinMode(BUZZER, OUTPUT);
  pinMode(LEDVIC, OUTPUT);

  randomSeed(analogRead(A0));
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  for(int i=0; i<4; i++){
    wishedSequel[i]=random(0, 4);

    digitalWrite(pinLeds[wishedSequel[i]], HIGH);
    delay(delayTm);
    digitalWrite(pinLeds[wishedSequel[i]], LOW);
    delay(delayTm/2);
  }

  if(checkInput()==false){
    defeat();
  }
  else{
    digitalWrite(LEDVIC, HIGH);
    delay(250);
    digitalWrite(LEDVIC, LOW);
    delay(250);
    digitalWrite(LEDVIC, HIGH);
    delay(250);
    digitalWrite(LEDVIC, LOW);
    delay(250);
    digitalWrite(LEDVIC, HIGH);
    delay(250);
    digitalWrite(LEDVIC, LOW);
    delayTm-=50;
  }

  if(delayTm<=100){
    victory();
  }

}

bool checkInput(){
  
  for(int i=0; i<4; i++){ //always will need four inputs pressed
    int buttonPressed = -1; //while no button is pressed status = -1
    while(buttonPressed == -1){ //still searching and looping until any button be pressed 

      for(int j=0; j<4; j++){
        if(digitalRead(pinButton[j])==HIGH){

          buttonPressed = j;

          digitalWrite(pinLeds[j], HIGH);
          digitalWrite(BUZZER, HIGH);
          delay(200);
          digitalWrite(pinLeds[j], LOW);
          digitalWrite(BUZZER, LOW);
          
          while(digitalRead(pinButton[j])==HIGH);
        }
      }
    }
    if(buttonPressed!=wishedSequel[i])
      return false;
  }
  return true;
}

void victory(){
  digitalWrite(BUZZER, HIGH);
  digitalWrite(LEDVIC, HIGH);
  delay(250);
  digitalWrite(BUZZER, LOW);
  digitalWrite(LEDVIC, LOW);
  delay(250);
  digitalWrite(BUZZER, HIGH);
  digitalWrite(LEDVIC, HIGH);
  delay(250);
  digitalWrite(BUZZER, LOW);
  digitalWrite(LEDVIC, LOW);
  delay(250);
  digitalWrite(BUZZER, HIGH);
  digitalWrite(LEDVIC, HIGH);
  delay(250);
  digitalWrite(BUZZER, LOW);
  digitalWrite(LEDVIC, LOW);


  delayTm=500;
  
  delay(2000);
}

void defeat(){
  digitalWrite(BUZZER, HIGH);
  delay(250);
  digitalWrite(BUZZER, LOW);
  delay(250);
  digitalWrite(BUZZER, HIGH);
  delay(250);
  digitalWrite(BUZZER, LOW);
  delay(250);
  digitalWrite(BUZZER, HIGH);
  delay(250);
  digitalWrite(BUZZER, LOW);

  delayTm = 500;

  delay(2000);
}
