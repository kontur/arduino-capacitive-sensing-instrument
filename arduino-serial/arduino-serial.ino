int outMin = 0;
int outMax = 100;
int samplingRate = 100;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
}

void loop() {
  // read photoresistors and clamp to 0-100
  int a0 = map(analogRead(A0), 0, 1023, outMin, outMax);
  int a1 = map(analogRead(A1), 0, 1023, outMin, outMax);
  int a2 = map(analogRead(A2), 0, 1023, outMin, outMax);
  
  // read potentiometers and clamp to 0-100
  // output originally ranges from 500-1023 because of 10kOhm resistor
  int a3 = map(constrain(analogRead(A3), 500, 1023), 500, 1023, outMin, outMax);
  int a4 = map(constrain(analogRead(A4), 500, 1023), 500, 1023, outMin, outMax);
  int a5 = map(constrain(analogRead(A5), 500, 1023), 500, 1023, outMin, outMax);
  
  /*
  // debug printing
  Serial.println("---------------");
  
  Serial.println("Potentiometers:");
  Serial.println(a3);
  Serial.println(a4);
  Serial.println(a5);
  
  Serial.println("Photoresistors:");
  Serial.println(a0);
  Serial.println(a1);
  Serial.println(a2);
  
  delay(500);
  */


  // Serial print tab separated
  Serial.print(a3);
  Serial.print("\t");
  Serial.print(a4);
  Serial.print("\t");
  Serial.print(a0);
  Serial.println();
  
  delay(samplingRate);
   
}

