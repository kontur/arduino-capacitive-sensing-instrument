void setup() {
  Serial.begin(9600);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
}

void loop() {
  int a3 = analogRead(A3);
  int a4 = analogRead(A4);
  int a5 = analogRead(A5);
  Serial.println(a3);
  Serial.println(a4);
  Serial.println(a5);
}
