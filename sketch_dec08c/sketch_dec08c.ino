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
int randN(){
  return random(0,4);
}
void pointUP(){
  point += 100;
}
void pointDN(){
  point -= 100;
}

int buttoncheck(int bt){
  for(int i = 0; i < 1000; i++){
    delay(1);
    if(digitalRead(bt) == LOW){
       pointUP();
       digitalWrite(buzz, HIGH);
       delay(70);
       return 1;
    }
    else{
      pointDN();
      digitalWrite(buzz, LOW);
      return 0;
    }
  }
}

void moveServo(Servo servo, int bt){
  servo.write(0);
  delay(1);
  if(buttoncheck(bt)==1){
     count++;
     digitalWrite(buzz, LOW);
     servo.write(90);
     delay(1000);
  }  
}
void WTOM(){
  if(n == 0){
    moveServo(servo1, bt[0]);
  }
  else if(n==1){
    moveServo(servo2, bt[1]);
  }
  else if(n==2){
    moveServo(servo3, bt[2]);
  }
  else if(n==3){
    moveServo(servo4, bt[3]);
  }
}
void lcdControl(){
  if(n==0){
    lcd.setCursor(3,0);
    lcd.print("Game Start!");
    lcd.init();
  }
}
void lcdPoint(){
  lcd.setCursor(3,0);
  lcd.print("Your Point!");
  lcd.setCursor(3,1);
  lcd.print(point);
}
void stopGame(){
  if(point == -1000){
    lcd.init();
    lcd.setCursor(3,0);
    lcd.print("Game Over");
    lcd.setCursor(3,1);
    lcd.print(over);
    delay(5000);
    lcd.init();
    lcd.print("READY");
    exit(0);
  }
}
void loop() {
  lcdControl();
  n = randN();
  WTOM();
  over = count + point;
  lcdPoint();
  stopGame();
  Serial.println(over);  
}
