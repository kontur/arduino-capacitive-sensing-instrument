#include <CapacitiveSensor.h>


/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs23 = CapacitiveSensor(2,3);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs24 = CapacitiveSensor(2,4);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs25 = CapacitiveSensor(2,5);
CapacitiveSensor   cs26 = CapacitiveSensor(2,6);

int v1 = 0, v2 = 0, v3 = 0, v4 = 0, v5 = 0;
float filter = 0.85;
int min_in = 500, max_in = 1500, min_out = 0, max_out = 100;

void setup()                    
{
//   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
}

void loop()                    
{
    long start = millis();
    long total1 = cs23.capacitiveSensor(30);
    long total2 = cs24.capacitiveSensor(30);
    long total3 = cs25.capacitiveSensor(30);
    long total4 = cs26.capacitiveSensor(30);
    
    v1 = filter * v1 + (1 - filter) * total1;
    v2 = filter * v2 + (1 - filter) * total2;
    v3 = filter * v3 + (1 - filter) * total3;
    v4 = filter * v4 + (1 - filter) * total4;
    
    /*
    Serial.print(v1);
    Serial.print("\t");
    Serial.print(v2);
    Serial.print("\t");
    Serial.print(v3);
    Serial.print("\t");
    Serial.print(v4);
    Serial.print("\t");
    
    Serial.print("\t1: ");                    // tab character for debug windown spacing
    Serial.print(total1);
    Serial.print("\t3: ");
    Serial.print(total3);
    Serial.print("\t4: ");
    Serial.print(total4);
    */
    Serial.print(map(constrain(v1, min_in, max_in), min_in, max_in, min_out, max_out));
    Serial.print("\t");
    Serial.print(map(constrain(v2, min_in, max_in), min_in, max_in, min_out, max_out));
    Serial.print("\t");
    Serial.print(map(constrain(v3, min_in, max_in), min_in, max_in, min_out, max_out));
    Serial.print("\t");
    Serial.print(map(constrain(v4, min_in, max_in), min_in, max_in, min_out, max_out));
    Serial.print("\t");
    Serial.println();
    delay(10);                             // arbitrary delay to limit data to serial port 
}
