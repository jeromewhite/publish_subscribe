import socket

clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientsocket.connect(('localhost', 50000))
f = open('subscriber.xml')
text = f.read()
clientsocket.send(text)
