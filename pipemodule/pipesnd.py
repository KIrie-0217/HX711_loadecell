import os
import errno
import time
import subprocess


FIFO = "mypipe"

try:
    os.mkfifo(FIFO)
except OSError as oe:
    if oe.errno != errno.EEXIST:
        raise

print("open PIPE...")
fifo = os.open(FIFO,os.O_WRONLY|os.O_NONBLOCK)
print("FIFO opened")

n =0
while True:
    try:
        
        data = [float(i)*n for i in range(9)]
        print(type(data),type(data[1]))
        os.write(fifo,str(data).encode())
        time.sleep(1)
        n += 1
    except KeyboardInterrupt:
        print ('Finish')
        break
     