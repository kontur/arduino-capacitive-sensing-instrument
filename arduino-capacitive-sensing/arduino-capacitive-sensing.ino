#include <CapacitiveSensor.h>


/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor cs23 = CapacitiveSensor(2,3);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor cs24 = CapacitiveSensor(2,4);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor cs25 = CapacitiveSensor(2,5);
CapacitiveSensor cs26 = CapacitiveSensor(2,6);
CapacitiveSensor cs27 = CapacitiveSensor(2,7);
CapacitiveSensor cs28 = CapacitiveSensor(2,8);

CapacitiveSensor cs2a0 = CapacitiveSensor(2,A0);
CapacitiveSensor cs2a1 = CapacitiveSensor(2,A1);
CapacitiveSensor cs2a2 = CapacitiveSensor(2,A2);
CapacitiveSensor cs2a3 = CapacitiveSensor(2,A3);

int v1 = 0, v2 = 0, v3 = 0, v4 = 0, v5 = 0, v6 = 0, v7 = 0, v8 = 0, v9 = 0, v10 = 0;
float filter = 0.85;
int min_in = 20, max_in = 200, min_out = 0, max_out = 100;

void setup()                    
{
   cs23.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
   pinMode(A0, INPUT);
   pinMode(A1, INPUT);
   pinMode(A2, INPUT);
   pinMode(A3, INPUT);
}

void loop()                    
{
    long total1 = cs23.capacitiveSensor(30);
    long total2 = cs24.capacitiveSensor(30);
    long total3 = cs25.capacitiveSensor(30);
    long total4 = cs26.capacitiveSensor(30);
    long total5 = cs27.capacitiveSensor(30);
    long total6 = cs28.capacitiveSensor(30);
    long total7 = cs2a0.capacitiveSensor(30);
    long total8 = cs2a1.capacitiveSensor(30);
    long total9 = cs2a2.capacitiveSensor(30);
    long total10 = cs2a3.capacitiveSensor(30);
    
    v1 = filter * v1 + (1 - filter) * total1;
    v2 = filter * v2 + (1 - filter) * total2;
    v3 = filter * v3 + (1 - filter) * total3;
    v4 = filter * v4 + (1 - filter) * total4;
    v5 = filter * v5 + (1 - filter) * total5;
    v6 = filter * v6 + (1 - filter) * total6;
    v7 = filter * v7 + (1 - filter) * total7;
    v8 = filter * v8 + (1 - filter) * total8;
    v9 = filter * v9 + (1 - filter) * total9;
    v10 = filter * v10 + (1 - filter) * total10;
    
    /*
    Serial.print("\t");                    // tab character for debug windown spacing
    Serial.print(total1);
    Serial.print("\t");
    Serial.print(total2);
    Serial.print("\t");
    Serial.print(total3);
    Serial.print("\t");
    Serial.print(total4);
    Serial.print("\t");
    Serial.print(total5);
    Serial.print("\t");
    Serial.print(total6);
    Serial.print("\t");
    Serial.print(total7);
    Serial.print("\t");
    Serial.print(total8);
    Serial.print("\t");
    Serial.print(total9);
    Serial.print("\t");
    Serial.print(total10);
    Serial.println();
    */
    
    Serial.print(map(constrain(v1, min_in, max_in), min_in, max_in, min_out, max_out));
    Serial.print("\t");
    Serial.print(map(constrain(v2, min_in, max_in), min_in, max_in, min_out, max_out));
    Serial.print("\t");
    Serial.print(map(constrain(v3, min_in, max_in), min_in, max_in, min_out, max_out));
    Serial.print("\t");
    Serial.print(map(constrain(v4, min_in, max_in), min_in, max_in, min_out, max_out));
    Serial.print("\t");
    Serial.print(map(constrain(v5, min_in, max_in), min_in, max_in, min_out, max_out));
    Serial.print("\t");
    Serial.print(map(constrain(v6, min_in, max_in), min_in, max_in, min_out, max_out));
    Serial.print("\t");
    Serial.print(map(constrain(v7, min_in, max_in), min_in, max_in, min_out, max_out));
    Serial.print("\t");
    Serial.print(map(constrain(v8, min_in, max_in), min_in, max_in, min_out, max_out));
    Serial.print("\t");
    Serial.print(map(constrain(v9, min_in, max_in), min_in, max_in, min_out, max_out));
    Serial.print("\t");
    Serial.print(map(constrain(v10, min_in, max_in), min_in, max_in, min_out, max_out));
    Serial.print("\t");
    Serial.println();
    
    delay(25);                             // arbitrary delay to limit data to serial port 
}
