import serial # https://pythonforundergradengineers.com/python-arduino-LED.html
from time import sleep
#https://stackoverflow.com/questions/16077912/python-serial-how-to-use-the-read-or-readline-function-to-read-more-than-1-char
comm=serial.Serial('COM7',9600,timeout=1)
waitToConnect=True
def call_arduino(val):
    global comm
    #https://stackoverflow.com/questions/21017698/converting-int-to-bytes-in-python-3
    if(type(val) is int):
        comm.write(bytes([val]))
    if (type(val) is str):
        comm.write(str.encode(val))


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    while waitToConnect:
        for c in comm.read():
            if c==13 or c==10:
                waitToConnect=False
                break
            #else:
            #    print(c)
    call_arduino('S')
    call_arduino(40)
    call_arduino(10)
    call_arduino('E')
    sleep(1)
    call_arduino(80)
    call_arduino(10)
    call_arduino('E')
    comm.close()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
