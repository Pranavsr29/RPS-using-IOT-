#include<new.h>
#include<Servo.h>
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
Servo servo_3;
Servo servo_6;
Servo servo_5;
volatile long int A;
int trigPin = (10); // Add the Trig pin on pin 10.
int echoPin = (9); // Add the ECHO pin on pin 9.
int duration, distance; // Add types 'duration' and 'distance'.
void setup()
{
A = 0;
servo_3.attach(3);
servo_6.attach(6);
servo_5.attach(5);
pinMode (12, OUTPUT);
pinMode (trigPin, OUTPUT);// Same as above, the TRIG pin will send the ultrasonic wave.
pinMode (echoPin, INPUT); // The ECHO pin will recieve the rebounded wave, so it must be an input 

}
void loop()
{
digitalWrite (trigPin, HIGH);
delay(50);
digitalWrite (trigPin, LOW);
duration=pulseIn (echoPin,HIGH);
distance=(duration/2)/19.1;
A=random(0,4);
if (distance <=40) 
{
if (A==1){
tone(12,131);
delay(100);
noTone(12);
for (pos1 = 0; pos1 <= 120; pos1 += 2) {
 servo_3.write(pos1);
 delay(10);
}
}
if (A==2){
tone(12,131);
delay(100);
noTone(12);
for (pos2 = 0; pos2 <= 120; pos2 += 2) {
 servo_6.write(pos2);
 delay(10);
}
}
if (A==3){
tone(12,131);
delay(100);
noTone(12);
for (pos3 = 0; pos3 <= 120; pos3 += 2) {
 servo_5.write(pos3);
 delay(10);
}
}
}
}
