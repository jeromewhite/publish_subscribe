import socket

socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket.connect(('localhost', 50000))

fileToSend = open('subscriber.xml', 'rb')
while True:
    data = fileToSend.readline()
    if data:
        socket.send(data)
    else:
        break
 
fileToSend.close()
print 'end'
socket.close()
exit()
