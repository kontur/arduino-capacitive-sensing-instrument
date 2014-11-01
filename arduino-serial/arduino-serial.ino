void setup() {
  Serial.begin(9600);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
}

void loop() {
  int a0 = analogRead(A0);
  int a1 = analogRead(A1);
  int a2 = analogRead(A2);
  int a3 = analogRead(A3);
  int a4 = analogRead(A4);
  int a5 = analogRead(A5);
  
  Serial.println("---------------");
  
  Serial.println("Potentiometers:");
  Serial.println(a3);
  Serial.println(a4);
  Serial.println(a5);
  
  Serial.println("Photoresistors:");
  Serial.println(a0);
  Serial.println(a1);
  Serial.println(a2);
  
  
  delay(10);
}
