void setup() {
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(9, 255);
  delay(5000);
  digitalWrite(9, 0);
  delay(3000);
  
}
