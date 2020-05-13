int led_pins[2] = {A2,A1};
int pin_length = sizeof(led_pins)/sizeof(int);
void setup() {
  for(int i=0;i<pin_length;i++){
    pinMode(led_pins[i],OUTPUT);  
  }
}
void loop() {
  for(int i=0;i<pin_length;i++){
    digitalWrite(led_pins[i],HIGH);
    delay(1000);
    digitalWrite(led_pins[i],LOW);
    delay(1000);  
  }
  
}
