import os
import errno
import time

FIFO = "mypipe"

try:
    os.mkfifo(FIFO)
except OSError as oe:
    if oe.errno != errno.EEXIST:
        raise

print("open PIPE...")
fifo = os.open(FIFO,os.O_RDONLY|os.O_NONBLOCK)
print("FIFO opened")


while True:
    try:
        data = os.read(fifo,1024)
        print(type(data))
        print('read:"{0}"'.format(data))
        time.sleep(1)
    except KeyboardInterrupt:
        print ('Finish')
        break   
     