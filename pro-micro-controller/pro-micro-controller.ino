  Created for IU Bloomingtons Spring 2023's Prototyping with Arduino class
  Handles button inputs and two outputs:
    -lighting their LEDs
    -sending keystrokes to connected device
  In this script, the Arduino cares about checking for button states, lighting LEDS,
  and sending keystrokes to the computer.
  This script was designed with Chrome and Windows in mind. 
*/

#include <Keyboard.h>

struct Button {
  const int buttonPin; //the input pin
  const int ledPin; //the output pin
  int state; //if the pin is pressed or not
};

Button btn1 = {3,4,0};
Button btn2 = {5,6,0};
Button btn3 = {7,8,0};
Button btn4 = {9,10,0};
Button ctrl = {11,12,0};


void setup() {
  // read the state of the pushbutton value:
  enablePinModes(btn1);
  enablePinModes(btn2);
  enablePinModes(btn3);
  enablePinModes(btn4);
  enablePinModes(ctrl);
  //enable keyboard
  Keyboard.begin();
  // open serial communication 
  Serial.begin(9600);
}

void enablePinModes(Button btn) {
  pinMode(btn.buttonPin, INPUT);
  pinMode(btn.ledPin, OUTPUT);
}

void handleButtonPress(Button btn, char* cmd) {
  //if the state of the pushbutton is HIGH, send keystroke command to connected keyboard
  if(btn.state == HIGH) {
    digitalWrite(btn.ledPin, HIGH);
    //for Chrome only
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press("l");
    Keyboard.releaseAll();
    Keyboard.println(cmd);
    delay(1000);
  } else {
    digitalWrite(btn.ledPin, LOW);
  }
}

void loop() {
  // read the state of the pushbutton value:
  btn1.state = digitalRead(btn1.buttonPin);
  btn2.state = digitalRead(btn2.buttonPin);
  btn3.state = digitalRead(btn3.buttonPin);
  btn4.state = digitalRead(btn4.buttonPin);
  ctrl.state = digitalRead(ctrl.buttonPin);
  //check the state of the pushbutton value
  handleButtonPress(btn1, "https://www.youtube.com");
  handleButtonPress(btn2, "https://www.youtube.com/feed/subscriptions");
  handleButtonPress(btn3, "https://www.youtube.com/feed/trending");
  handleButtonPress(btn4, "https://www.youtube.com/shorts");
  /**
    @TODO: figure out Ctrl's purpose
    @DESC: if we want Ctrl to serve as a Ctrl button, calling the function on ctrl will not work.
  */
  handleButtonPress(ctrl, "https://www.youtube.com/shorts"); 


}
