from socket import socket, AF_INET, SOCK_STREAM
import time
import serial
import time



HOST        = 'localhost'
PORT        = 51001

ser = serial.Serial('/dev/ttyACM0',9600)
time.sleep(1)


def com_send():

    while True:
        try:
            # 通信の確立
            sock = socket(AF_INET, SOCK_STREAM)
            sock.connect((HOST, PORT))

            # メッセージ送信 （以下では 0〜9までを１秒おきに送信）
            while True:

                
                String_data = ser.readline()
                print(String_data.strip().decode())
                # encode で文字列型をデータ型に変換
                sock.send(String_data)

                time.sleep(1)


        except KeyboardInterrupt:
            print ('Finish')
            # 通信の終了
            sock.close()
            ser.close()

def main():
    com_send()

if __name__ == "__main__":
    main()
            


