#include <Servo.h>

Servo servo1;
Servo servo2;
int bt1 = 10;
int bt2 = 9;
int point = 0;
int posicaoUP = 90;
int posicaoDN = 0;
void setup(){
  Serial.begin(9600);
  servo1.attach(7);
  servo2.attach(6);
  pinMode(bt1, INPUT);
  pinMode(bt2, INPUT);
}

void loop(){
 // int posicao = posicaoUP;
  //int n = random(1,3);
  //if(n == 1){
    servo1.write(0);
    delay(1000);
    //posicao = posicaoDN;
    servo1.write(90);
    delay(1000);
    if(digitalRead(bt1) == HIGH ){
      point = point + 100;
    //}
   // else if(n==2){
      servo2.write(0);
      delay(1000);
      //posicao = posicaoDN;
      servo2.write(90);
      delay(1000);
      if(digitalRead(bt2) == HIGH){
        point = point + 100;
      }
   // }
  }
  Serial.println(point);
}
