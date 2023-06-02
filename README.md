# Arduino Kid Controller - I341

This repository contains the codebase for a controller made for children using Arduino. The device was created as a class project for INFO-I341, Prototyping for Arduino, offered by Indiana University during the Spring 2023 semester.

![Arduino Children's Controller](controller_photo.jpg)

## Description

The Arduino Children's Controller is a custom-made device designed specifically for children. It features four large, round buttons and one smaller Ctrl button, all placed within a colorful LEGO board. The controller's design aims to provide an engaging and intuitive interface for children to interact with.

## Button Design

![Arduino Controller Button](controller_button.jpg)

The buttons were inspired by morse code telegraph machines. When the user pressed down on the button section's circular LEGO piece, the cyclinder piece below presses the tactile button. The hinge section forces the button section to go back up.

Each button has a unique top, allowing children to differentiate between them by touch alone. The distinctive design elements help children easily identify the buttons and enhance their overall experience while using the controller.

## Components Used

The controller was built with the following components:
- 1 Arduino Pro Micro Controller
- LEGO bricks
- 5 Mini breadboards
- 5 LEDs
- 5 Buttons
- Jumper Wires

## Main File

The main file in this repository is `pro-micro-controller.ino`. It handles user input in the form of button presses and provides two different functionalities depending on whether the Ctrl button is pressed or not. The code is designed to work with Windows and Chrome.

### Functionality

The `pro-micro-controller.ino` file provides the following functionality:

- A struct called `Button` is defined to store the properties of each button. The properties include the button pin, LED pin, button state (pressed or not), URL of the playlist/video, the value of the key needed for the shortcut, and a boolean to check if the shortcut requires the Shift key.

- Upon setting up the Arduino, the code opens serial communication and activates the keyboard class to emulate keystrokes on the connected computer.

- If a regular button is pressed while in the "playlist" state, the code emulates the keystrokes "Left Ctrl + L" to jump to the address bar in Chrome. Then it types the URL of the playlist stored in the corresponding `Button` struct and navigates to the playlist.

- If a regular button is pressed while in the "shortcut" state, the code emulates the keystrokes defined in the corresponding `Button` struct.

- If the Ctrl button is pressed, the code switches between the "playlist" and "shortcut" states.

## Getting Started

To use this codebase and set up the Arduino Children's Controller, follow the steps below:

1. Clone the repository to your local machine.

```shell
git clone https://github.com/your-username/arduino-children-controller.git
```

2. Connect your Arduino board to your computer.

3. Open the `pro-micro-controller.ino` file in the Arduino IDE.

4. Configure the necessary settings, such as board type and port, in the Arduino IDE.

5. Upload the code to the Arduino board.

6. Connect the buttons and LEDs to the appropriate pins on the Arduino board, as specified in the `Button` struct within the code.

7. Connect the Arduino board to the computer running Chrome.

8. Ensure that Chrome is open and the active window.

9. Test the functionality by pressing the buttons and observing the desired behavior in Chrome.

## Contributing

Contributions to the project are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request on the repository.

## License

This project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code for personal and commercial purposes.
