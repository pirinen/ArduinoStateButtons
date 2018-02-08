/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int button26Pin = 26;     // the number of the pushbutton pin
const int button28Pin = 28;     // the number of the pushbutton pin

//const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState26 = 0;         // variable for reading the pushbutton status
int buttonState28 = 0;

byte oldbutton26 = 0;
byte oldbutton28 = 0;
byte state26 = 0;
byte state28 = 0;
byte pressed26 = 0;
byte pressed28 = 0;

void setup() {
  // initialize the LED pin as an output:
  //pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button26Pin, INPUT);
  pinMode(button28Pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState26 = digitalRead(button26Pin);
  buttonState28 = digitalRead(button28Pin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:

  if (buttonState26 == LOW) {
    pressed26 = 0;
  }

  //Button26
  if (buttonState26 == HIGH && !oldbutton26 && !pressed26) {

    if (state26 == 0)
    {
      Serial.println("Button26 On");
      state26 = 1;
    }
    else
    {
      state26 = 0;
    }
    oldbutton26 = 1;
    pressed26 = 1;

  } else if (buttonState26 == HIGH && oldbutton26 && !pressed26) {

    if (state26 == 1)
    {
      Serial.println("Button26 Off");
      state26 = 0;
    }
    else
    {
      state26 = 1;
    }
    oldbutton26 = 0;
    pressed26 = 1;
  } //Button26

  if (buttonState28 == LOW) {
    pressed28 = 0;
  }
  
  //Button28
  if (buttonState28 == HIGH && !oldbutton28 && !pressed28) {

    if (state28 == 0)
    {
      Serial.println("Button28 On");
      state28 = 1;
    }
    else
    {
      state28 = 0;
    }
    oldbutton28 = 1;
    pressed28 = 1;

  } else if (buttonState28 == HIGH && oldbutton28 && !pressed28) {

    if (state28 == 1)
    {
      Serial.println("Button28 Off");
      state28 = 0;
    }
    else
    {
      state28 = 1;
    }
    oldbutton28 = 0;
    pressed28 = 1;
  } //Button28
}
