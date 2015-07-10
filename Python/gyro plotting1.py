import serial
import matplotlib.pyplot as plt
import sys
import time as t
try:
    s  = serial.Serial('COM9',9600)
except IOError:
    print('Could not open COM port')
    sys.exit()

time = []
data = []
count = 0

def PlotData(count):
    waiting = s.inWaiting()
    print(waiting)
    for i in range(waiting):
        data.append(int(s.readline()))
        count += 0.5
        time.append(count)
        
    plt.cla()
    plt.plot(time, data)

print(s.readline())
t.sleep(0.1)
PlotData(count)
plt.show()

d = []
for i in range(len(data)):
    d.append(bin(data[i]))

s.close()        