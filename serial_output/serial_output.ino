void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("hello");
  Serial.flush();
  delay(1000);
}
