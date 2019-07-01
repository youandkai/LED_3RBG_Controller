/*
 This Sketch Simulate Flashing Lights
 */

//blink without delay = bwd
const int red = 3;
const int green = 5;
const int blue = 6;
int on_sec=50;
const int knob1 = A1;
const int knob2 = A0;

//for bwd
const int ledPin = LED_BUILTIN;
int redState = LOW;
int greenState = LOW;
int blueState = LOW;
unsigned long previousMillis = 0;
long interval=1000;

void setup() {
  // set up LED pins
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  //bwd implementation
  //pinMode(ledPin,OUTPUT);
  
  // initialize serial communications
  Serial.begin(9600);
}


void loop() {

  //reading knob
  on_sec = map(analogRead(knob1), 1, 1024, 11, 500);

  //bwd implementation
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= on_sec) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (redState == LOW&greenState == LOW&blueState == LOW) {
      redState=HIGH;
    } else if (redState== HIGH&greenState==LOW&blueState== LOW) {
      redState = LOW;
      greenState=HIGH;
    } else if (redState== LOW&greenState==HIGH&blueState== LOW){
      greenState=LOW;
      blueState=HIGH;
    } else if (redState== LOW&greenState==LOW&blueState== HIGH){
      blueState=LOW;
      redState=HIGH;
    }

    //print a state change to serial monitor    
    Serial.print(redState);
    Serial.print("is on for");
    Serial.print(on_sec);
    Serial.print("\n");

  } //end if statement

  digitalWrite(red, redState);
  digitalWrite(green, greenState);
  digitalWrite(blue, blueState);


} //end loop
