import serial
from firebase import firebase

firebase = firebase.FirebaseApplication('FIREBASE REALTIME DB URL', None)

ser = serial.Serial('/dev/cu.usbmodem14401')
print(ser.name)
while ser.is_open:
    # [temperature, humidity, heat index]
    sensor_read = ser.readline().decode('utf-8').strip('\r\n').split(' ')

    res = firebase.post(
        '/temphumidity', 
        {
            'temperature': sensor_read[0], 
            'humidity': sensor_read[1], 
            'humidex': sensor_read[2]
        }
    )

    print(res)

ser.close()