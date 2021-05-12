import socket

clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientsocket.connect(('localhost', 50000))
fp = open('books.xml')
dom = fp.read()
clientsocket.send(dom)
