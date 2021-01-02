#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
int point = 0;
int bt1 = 10;
int bt2 = 9;
int bt3 = 8;
int n = 0;
int buzz = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(7);
  servo2.attach(6);
  servo3.attach(5);
  pinMode(bt1, INPUT_PULLUP);
  pinMode(bt2, INPUT_PULLUP);
  pinMode(bt3, INPUT_PULLUP);
  pinMode(buzz, OUTPUT);
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
}

void loop() {
  if(n == 0){
    lcd.setCursor(3,0);
    lcd.print("Game Start!");
    lcd.init();
  }
  // put your main code here, to run repeatedly:
  n = random(1,4);
  int posicao = 0;
  if(n==1){
    servo1.write(posicao);
    delay(1500);
    posicao = 90;
    servo1.write(posicao);
    delay(1000);
    if(digitalRead(bt1) == LOW){
      point = point + 100;
    }
    else if(digitalRead(bt2) == LOW || digitalRead(bt3)==LOW){
      point = point -100;
    }
  }
  else if(n==2){
    servo2.write(posicao);
    delay(1500);
    posicao = 90;
    servo2.write(posicao);
    delay(1000);
    if(digitalRead(bt2) == LOW){
      point = point + 100;
    }
    else if(digitalRead(bt1)==LOW || digitalRead(bt3)==LOW){
      point = point -100;
    }
  }
  else if(n==3){
    servo3.write(0);
    delay(1500);
    posicao = 90;
    servo3.write(posicao);
    delay(1000);
    if(digitalRead(bt3)==LOW){
      point = point + 100;
    }
    else if(digitalRead(bt1)==LOW || digitalRead(bt2)==LOW){
      point = point -100;
    }
  }

  if(digitalRead(bt1)==LOW || digitalRead(bt2)==LOW || digitalRead(bt3) == LOW){
    digitalWrite(buzz, HIGH);
  }
  else{
    digitalWrite(buzz, LOW);
  }
  Serial.println(point);
  lcd.setCursor(3,0);
  lcd.print("Your Point!");
  lcd.setCursor(3,1);
  lcd.print(point);
  if(point == -1000){
    lcd.init();
    lcd.setCursor(3,0);
    lcd.print("Game Over");
    lcd.setCursor(1,1);
    delay(5000);
    lcd.init();
    lcd.print("READY");
    exit(0);
  }
}
