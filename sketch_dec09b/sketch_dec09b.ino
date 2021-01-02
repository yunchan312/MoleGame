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
int n=0;
int point = 0;
int over = 0;
int count = 1;

void pointUP(){
  point = point + 100;
}
void pointDN(){
  point = point - 100;
}
void Random(){
  n = random(1,5);
}
void Move1(){
  count = 0;
  servo1.write(0);
  for(int i = 0; i < 1000; i++){
    delay(1);
    if(digitalRead(bt[0])==LOW){
      if(count == 0){
        count++;
        pointUP();
      }
      digitalWrite(buzz, HIGH);
      servo1.write(90);
    }
    digitalWrite(buzz, LOW);
    delay(1);
  }
}
void Move2(){
  count = 0;
  servo2.write(0);
  for(int i = 0; i < 1000; i++){
    delay(1);
    if(digitalRead(bt[1])==LOW){
      if(count == 0){
        count++;
        pointUP();
      }
      digitalWrite(buzz, HIGH);
      servo4.write(90);
    }
    digitalWrite(buzz, LOW);
    delay(1);
  }
}
void Move3(){
  servo3.write(0);
  for(int i = 0; i < 1000; i++){
    delay(1);
    if(digitalRead(bt[2])==LOW){
      if(count == 0){
        count++;
        pointUP();
      }
      digitalWrite(buzz, HIGH);
      servo3.write(90);
    digitalWrite(buzz, LOW);
    delay(1);
   }
}
void Move4(){
  count = 0;
  servo4.write(0);
  for(int i = 0; i < 1000; i++){
    delay(1);
    if(digitalRead(bt[3])==LOW){
      if(count == 0){
        count++;
        pointUP();
      }
      digitalWrite(buzz, HIGH);
      servo4.write(90);
    }
    digitalWrite(buzz, LOW);
    delay(1);
  }
}
void LCDpoint(){
  lcd.setCursor(3,0);
  lcd.print("Your Point");
  lcd.setCursor(3,1);
  lcd.print(point);
}
void isGameover(){
  over++;
  if(over == 30){
    lcd.setCursor(3,0);
    lcd.print("Game Over");
    exit(0);
  }
}
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

void loop() {
  LCDpoint();
  Random();
  Serial.println(n);
  if(n==1){
    Move1();
  }
  else if(n==2){
    Move2();
  }
  else if(n==3){
    Move3();
  }
  else if(n==4){
    Move4();
  }
  isGameover();

  //Serial.println(point);

}
