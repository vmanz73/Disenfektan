/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int pump = 13;
int timer =0;
// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(pump,OUTPUT);
Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor

Serial.print("Distance: ");
Serial.println(distance);
if (distance <= 200  ){
timer++;
digitalWrite(pump,HIGH);
Serial.println("nyala");
Serial.println("waktu : "+String(timer));
if(timer == 110){
  digitalWrite(pump,LOW);
  Serial.println("mati");
  timer = 0;
  delay(2500);
}
}
else{
  digitalWrite(pump,LOW);
  Serial.println("mati");
  timer = 0;

}
}
