from socket import socket, AF_INET, SOCK_STREAM
import time
import serial
import time
import json
from pipemodule import pipemethod

serialport = '/dev/ttyACM1'
serialV = 9600

def readbypy(serialport,serialV):
    fifo = pipemethod.openFIFO("/tmp/ktl-fifo/torque","w")
    while True:
        try:

            ser = serial.Serial(serialport,serialV)
            print("Arduino coneccted")
            time.sleep(1)

            while True:

                
                String_data = ser.readline()
                try:
                    data = json.loads(String_data.decode().rstrip("\r\n"))
                    data = [float(data["1"]),float(data["2"]),float(data["3"]),float(data["4"]),float(data["5"]),float(data["6"]),float(data["7"]),float(data["8"]),float(data["9"])]
                    print(data)
                    pipemethod.pack_and_write(data,fifo)

                except:
                    data = ""  
                    print("none")



        except KeyboardInterrupt:
            print ('Finish')
            ser.close()
            break

def main():
    serialport = '/dev/ttyACM1'
    serialV = 9600
    readbypy(serialport,serialV)

if __name__ == "__main__":
    main()
            


