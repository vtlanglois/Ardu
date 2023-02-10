import serial
import webbrowser as wb
import pyautogui


print("Begin reading serial input")

# ser = serial.Serial("COM11", 9600) # change "COM3" to the correct port for your setup
/
while True:
    message = "Button 2 pressed" #ser.readline().decode().strip()/
    match message:
        case "Button 1 pressed":
            wb.open("https://www.youtube.com", new = 0);
        case "Button 2 pressed":
            wb.open("https://www.youtube.com/feed/subscriptions");
        case "Button 3 pressed":
             wb.open("https://www.youtube.com/feed/trending");
        case "Button 4 pressed":
             wb.open("https://www.youtube.com/shorts");
    break;
