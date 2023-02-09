import serial
import webbrowser


print("start!")

ser = serial.Serial("COM11", 9600) # change "COM3" to the correct port for your setup


print("start!2")

while True:
    print("start!23")
    message = ser.readline().decode().strip()
    print(message)
    print("j!")
    if message == "Button 1 pressed":
        # perform action for button 1
        webbrowser.open("https://www.wikipedia.com")
        print("3!!!")

    if message == "Button 2 pressed":
        # perform action for button 1
        print("2!!!")
