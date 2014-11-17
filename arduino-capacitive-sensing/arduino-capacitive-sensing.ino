#include <CapacitiveSensor.h>

/*
 * Arduino musical capacitive sensing instrument code
 * Johannes Neumeier 2014
 *
 * Created at Physical Interaction Design course at
 * Aalto University, Media Lab, SOPI research group
 * fall 2014
 *
 * Arduino code based on:
 * CapitiveSense Library Demo Sketch Paul Badger 2008
 */

// capacitive sensors
// digital pins:
CapacitiveSensor cs23 = CapacitiveSensor(2,3);
CapacitiveSensor cs24 = CapacitiveSensor(2,4);
CapacitiveSensor cs25 = CapacitiveSensor(2,5);
CapacitiveSensor cs26 = CapacitiveSensor(2,6);
CapacitiveSensor cs27 = CapacitiveSensor(2,7);
CapacitiveSensor cs28 = CapacitiveSensor(2,8);
// analog pins
CapacitiveSensor cs2a0 = CapacitiveSensor(2,A0);
CapacitiveSensor cs2a1 = CapacitiveSensor(2,A1);
CapacitiveSensor cs2a2 = CapacitiveSensor(2,A2);
CapacitiveSensor cs2a3 = CapacitiveSensor(2,A3);

// save "last" value on every read to smoothen values
int v1 = 0, v2 = 0, v3 = 0, v4 = 0, v5 = 0, v6 = 0, v7 = 0, v8 = 0, v9 = 0, v10 = 0;

// smoothening amount from 0-1
float filter = 0.85; 

// min_in and max_in need to be empirically tested with the configured hardware setup
// as the physical properties of the equipment change the reads
// min_out and max_out define the normalized range of values written to the serial port
int min_in = 20, max_in = 700, min_out = 0, max_out = 100; 

void setup()                    
{
   Serial.begin(9600);
   
   // set additional analog pins for input
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
    
    // apply dampening to all new values, so that the 
    // fluctuations are less extrem between reads
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
    // debug print to see the actual unnormalized value
    Serial.print("\t");
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
    
    // print normalized values for each sensor between min_out and max_out
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
    /**/
    
    // arbitrary delay to limit data to serial port 
    delay(25);     
}
