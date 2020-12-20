import os
import errno
import time
import struct
import pipemethod


def main():
    fifo = pipemethod.openFIFO("/tmp/ktl-fifo/torque","w")
    n=0
    while True:
        try:
            data = [1*n,2.000,0.03,4,5,6,7,8,9]
            pipemethod.pack_and_write(data,fifo)
            n+= 1

        except KeyboardInterrupt:
            print ('Finish')
            os.close(fifo)
            break

if __name__ == "__main__":
    main()
