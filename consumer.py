import serial
import webbrowser as wb


print("Begin reading serial input")
serialPort = "COM11"
ser = serial.Serial(serialPort, 9600) # change "COM3" to the correct port for your setup
print("Begin responding to serial input")

while True:
    message = ser.readline().decode().strip()
    match message:
        case "button_1_pressed":
            wb.open("https://www.youtube.com");
        case "button_2_pressed":
            wb.open("https://www.youtube.com/feed/subscriptions");
        case "button_3_pressed":
             wb.open("https://www.youtube.com/feed/trending");
        case "button_4_pressed":
             wb.open("https://www.youtube.com/shorts");
        case "ctrl_pressed":
            pass
