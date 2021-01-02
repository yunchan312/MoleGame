#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int buzz = 7;
int bt[] = {8,9,10,11};
int count = 0;
int n=0;
int point = 0;
int over = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(bt[0], INPUT_PULLUP);
  pinMode(bt[1], INPUT_PULLUP);
  pinMode(bt[2], INPUT_PULLUP);
  pinMode(bt[3], INPUT_PULLUP);
  pinMode(buzz, OUTPUT);
  servo1.attach(6);
  servo2.attach(5);
  servo3.attach(4);
  servo4.attach(3);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

int buttoncheck(int bt){
  for(int i = 0; i < 1000; i++){
    delay(1);
    if(digitalRead(bt) == LOW){
       digitalWrite(buzz, HIGH);
       delay(70);
       return 1;
    }
    else{
      digitalWrite(buzz, LOW);
      return 0;
    }
  }
}
void ServoUP(){
  if(n == 1){
    servo1.write(0);
  }
  else if(n==2){
    servo2.write(0);
  }
  else if(n==3){
    servo3.write(0);
  }
  else if(n==4){
    servo4.write(0);
  }
}
void ServoDN(){
  if(n == 1){
    servo1.write(90);
    delay(1000);
  }
  else if(n==2){
    servo2.write(90);
    delay(1000);
  }
  else if(n==3){
    servo3.write(90);
    delay(1000);
  }
  else if(n==4){
    servo4.write(90);
    delay(1000);
  }
}

void pointUP(){
  point = point + 100;
}
void pointDN(){
  point = point - 100;
}
void startLCD(){
  lcd.setCursor(3,0);
  lcd.print("Game Start!");
  lcd.init();
}
void gamingLCD(){
  lcd.init();
  lcd.setCursor(3,0);
  lcd.print("Your Point:");
  lcd.setCursor(3,1);
  lcd.print(point);
}
void stopLCD(){
  lcd.init();
  lcd.setCursor(3,0);
  lcd.print("Game Over");
  lcd.setCursor(3,1);
  lcd.print(point);
}
void GO(){
  if(point == -1000){
    stopLCD();
    exit(0);
  }
}
void loop() {
  startLCD();
  n = random(1,5);
  ServoUP();
  if(buttoncheck(bt[n-1]) == 1){
    pointUP();
    digitalWrite(buzz, LOW);
    ServoDN();
  }
  else{
    pointDN();
    digitalWrite(buzz, LOW);
    ServoDN();
  }
  gamingLCD();
  GO();
}
