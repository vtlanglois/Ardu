/*
  Created for IU Bloomingtons Spring 2023's Prototyping with Arduino class

  Handles button inputs and two outputs:
    -lighting their LEDs
    -sending messages to a Python script

  In this script, the only thing the Arduino cares about is checking for button states,
  lighting LEDs, and sending messages to the computer.
*/
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
  //set up all necessary inputs and outputs
  enablePinModes(btn1);
  enablePinModes(btn2);
  enablePinModes(btn3);
  enablePinModes(btn4);
  enablePinModes(ctrl);
  // open serial communication with Python script
  Serial.begin(9600);
}

void enablePinModes(Button btn) {
  pinMode(btn.buttonPin, INPUT);
  pinMode(btn.ledPin, OUTPUT);
}

void handleButtonPress(Button btn, char* successMsg) {
  //if the state of the pushbutton is HIGH, send message to Python script thru Serial
  if(btn.state == HIGH) {
    digitalWrite(btn.ledPin, HIGH);
    Serial.println(successMsg);
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
  handleButtonPress(btn1, "button_1_pressed");
  handleButtonPress(btn2, "button_2_pressed");
  handleButtonPress(btn3, "button_3_pressed");
  handleButtonPress(btn4, "button_4_pressed");
  handleButtonPress(ctrl, "ctrl_pressed");
}
