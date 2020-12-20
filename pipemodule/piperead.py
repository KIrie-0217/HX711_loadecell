import os
import errno
import time
import struct
import pipemethod

def main():
    fifo = pipemethod.openFIFO("/tmp/ktl-fifo/torque","r")
    while True:
        try:
            out = pipemethod.read_and_unpack(fifo,9)
            print(out)
        except KeyboardInterrupt:
            print ('Finish')
            os.close(fifo)
            break   
     

if __name__ == "__main__":
    main()
