




 /* Created for IU Bloomingtons Spring 2023's Prototyping with Arduino class
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
  char* url; //the URL of video/playlist to play
  /**
  @TODO: figure out if I can really use an array to store all the key presses. Would the macros be why it doesn't work?
  */
  char key; //the hotkey value
  bool usesShift; //does the key need shift to work?
};



Button btn1 = {3,4,0, "https://www.youtube.com/watch?v=YO0A8SSor1k&list=PL_Dj2ayYHVRyLb7SLlxafH6_jgazJ6dgL", 'k', false}; 
Button btn2 = {5,6,0, "https://www.youtube.com/watch?v=CRjVN_FtOpk&list=PLWdM4kr9O7dNVXRui9UghSMHFdZGlnCwH", 'c', false};
Button btn3 = {7,8,0, "https://www.youtube.com/watch?v=Kr9zgvjRbjY&list=PLa8HWWMcQEGRdrmSKzOxpCUaZoPfg1IgT", 'n', true};
Button btn4 = {9,10,0, "https://www.youtube.com/watch?v=aj60xWBHJxw&list=PLT1rvk7Trkw621AGHhz4WQC2thuUawRek", 'p', true};
Button ctrl = {8,12,0, "", 'c', false}; //switches between "URL" and "Shortcuts" state

bool isCtrl = false;

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

void handleURLRequest(Button btn) {
  //if the state of the pushbutton is HIGH, send keystroke command to connected keyboard
  if(btn.state == HIGH) {
    digitalWrite(btn.ledPin, HIGH);
    //for Chrome only
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('l');
    Keyboard.releaseAll();
    Keyboard.println(btn.url);
  
    delay(1000);
  } else {

  
    digitalWrite(btn.ledPin, LOW);
  }
}

void handleKeystrokeRequest(Button btn) {
    //if the state of the pushbutton is HIGH, send keystroke command to connected keyboard
  if(btn.state == HIGH) {
    digitalWrite(btn.ledPin, HIGH);
    Serial.println("ctrl button function!");
    //loop wasn't work, hope this works!
    if(btn.usesShift) {
      Keyboard.press(KEY_LEFT_SHIFT);
    } 
    Keyboard.press(btn.key);
    Keyboard.releaseAll();

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
  if(!isCtrl) {
    handleURLRequest(btn1);
    handleURLRequest(btn2);
    handleURLRequest(btn3);
    handleURLRequest(btn4);
  } else {
    handleKeystrokeRequest(btn1);
    handleKeystrokeRequest(btn2);
    handleKeystrokeRequest(btn3);
    handleKeystrokeRequest(btn4);
  }

  if(ctrl.state == HIGH) {N
      isCtrl = !isCtrl;
      digitalWrite(ctrl.ledPin, isCtrl);
      Serial.println("ctrl!");
      Serial.println(isCtrl);
      delay(1000);
  }


}

