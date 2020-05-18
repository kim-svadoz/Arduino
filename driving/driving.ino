/*
   Smart Robot Car V3
   - Motor test code
*/
#include "NewPing.h"
// 차량 운행 방향 상태 전역 변수.

int carSpeed = 194; // 최대 속도의  50 % for testing.

#define ENA   11
#define EN1   7 // 왼쪽 뒤로
#define EN2   3 // 왼쪽 앞으로 
#define EN3   4 // 오른쪽 앞으로
#define EN4   2 // 오른쪽 뒤로
#define ENB   5

#define ECHO   8
#define TRIGGER   9

NewPing sonar(ECHO, TRIGGER, 200);
const int RECV_PIN = 10;

//////////////////////////////////
// Setup to run once
//
void setup()
{
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);  // ENA
  pinMode(EN1, OUTPUT);  // EN1
  pinMode(EN2, OUTPUT);  // EN2

  pinMode(ENB, OUTPUT);  // ENB
  pinMode(EN3, OUTPUT);  // EN3
  pinMode(EN4, OUTPUT);  // EN4
}
void loop()
{
  Serial.print("Ping : ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
  delay(1000);
  
  if (Serial.available() > 0) {
    int a = Serial.read();
    switch (a) {
      case 'f':
        forward(carSpeed);
        break;
      case 'x':
        left(carSpeed);
        break;
      case 'y':
        right(carSpeed);
        break;
      case 'b':
        back(carSpeed);
        break;
      case 'l':
        leftspin();
        break;
      case 'r':
        rightspin();
        break;
      case 'u':
        up(carSpeed);
        break;
      case 'd':
        down(carSpeed);
        break;
      case 's':
        stopD();
        break;
    }
    
    /*
    if (irrecv.decode(&results)){
    if(results.value==16718055){
      go(carSpeed);
    }
    if(results.value==16730805){
      back(carSpeed);
    }
    if(results.value==16716015){
      left(carSpeed);
    }
    if(results.value==16734885){
      right(carSpeed);
    }
    irrecv.resume();
  }
  */
  }
}
void forward(int speed)
{
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, HIGH);
  digitalWrite(EN3, HIGH);
  digitalWrite(EN4, LOW);
}
void left(int speed)
{
  analogWrite(ENA, 0);
  analogWrite(ENB, speed);
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, LOW);
  digitalWrite(EN3, HIGH);
  digitalWrite(EN4, LOW);
}
void right(int speed)
{
  int mSpeed = speed + 20;
  if(mSpeed >= 255) mSpeed = 255;
  analogWrite(ENA, speed);
  analogWrite(ENB, 0);
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, HIGH);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, HIGH);
}
void back(int speed)
{
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, LOW);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, HIGH);
}
void up(int speed) {
  carSpeed += 20;
  if(carSpeed>=255) carSpeed=255;
}
void down(int speed) {
  carSpeed -= 20;
  if(carSpeed<=100) carSpeed=100;
}
void leftspin() {
  analogWrite(ENA, 120);
  analogWrite(ENB, 120);
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, LOW);
  digitalWrite(EN3, HIGH);
  digitalWrite(EN4, LOW);
  delay(500);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
void rightspin() {
  analogWrite(ENA, 120);
  analogWrite(ENB, 120);
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, HIGH);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, HIGH);
  delay(500);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
void stopD(){
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
