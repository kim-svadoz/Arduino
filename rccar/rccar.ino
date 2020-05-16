/*
   Smart Robot Car V3
   - Motor test code
*/
#include <IRremote.h>
// 차량 운행 방향 상태 전역 변수.

int carSpeed = 200; // 최대 속도의  50 % for testing.

#define ENA   11
#define EN1   7 // 왼쪽 뒤로
#define EN2   3 // 왼쪽 앞으로 
#define EN3   4 // 오른쪽 앞으로
#define EN4   2 // 오른쪽 뒤로
#define ENB   5
const int RECV_PIN = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;


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
  irrecv.enableIRIn();
  irrecv.blink13(true);




}
void loop()
{/*
  if (Serial.available() > 1) {
    char a = Serial.read();
    switch (a) {
      case 'g':
        go(carSpeed);
        break;
      case 'b':
        back(carSpeed);
        break;
      case 'r':
        right(carSpeed);
        break;
      case 'l':
        left(carSpeed);
        break;
    }
    */
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
}
void go(int speed)
{
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, HIGH);
  digitalWrite(EN3, HIGH);
  digitalWrite(EN4, LOW);
  delay(1000);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
void back(int speed)
{
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, LOW);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, HIGH);
  delay(1000);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
void right(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, HIGH);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, HIGH);
  delay(1000);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
void left(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, LOW);
  digitalWrite(EN3, HIGH);
  digitalWrite(EN4, LOW);
  delay(1000);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
