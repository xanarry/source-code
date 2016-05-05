from PyQt5 import QtCore, QtGui, QtWidgets
from threading import Thread
from PyQt5.QtWidgets import *
from itemWidget import ItemWidget
from mainUI import Ui_LanTrans
from os import path
import getpass
import platform
import Service
import socket

class service(object):
    """docstring for service"""
    updated = QtCore.pyqtSignal(str)
    def __init__(self):
        super(service, self).__init__()
        self.host = socket.gethostname()
        self.port = 8888
      
    def searchreceiver(self, caller, timeout = 2, trytimes = 5):
        '''"search udp server in LAN"'''
        self.udpClient = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.udpClient.settimeout(timeout)
        self.udpClient.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

        mes = socket.gethostname()
        buf = None
        address = None

        #caller.updateState("searching")
        self.updated.emit("agsdafasdf")
        while True:
            self.udpClient.sendto(mes.encode(), ("<broadcast>", 8888))
            #self.udpClient.sendto(mes.encode(), ("127.0.0.1", 8888))
            try:
                buf, address = self.udpClient.recvfrom(1024)
                if address is not None and buf is not None:
                    break
            except socket.timeout:
                #caller.updateState("timeout error, remain" + str(trytimes) + "to try")
                self.updated.emit("timeout error, remain" + str(trytimes) + "to try")
                print("timeout error, remain", trytimes, "to try")
                trytimes -= 1

            if trytimes == 0:
                break
        if address is None:
            #caller.updateState("failed to search server")
            self.updated.emit("failed to search server")
            print("failed to search server")
        else:
            #caller.statusText.append("find receiver:" + str(address))
            self.updated.emit("find receiver:" + str(address))
            print(buf.decode(), "from:", address)
        #self.udpClient.shutdown(socket.SHUT_RDWR)
        caller.receiverAddr = address
        caller.recoverState()
        return address

    def waitsender(self):
        '''"wait file sender"'''
        self.udpServer = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.udpServer.bind(("", self.port))
        print("upd server waiting")

        buf, address = self.udpServer.recvfrom(1024)
        print(buf.decode(), "from:", address)

        self.udpServer.sendto(buf, address)

        #self.udpServer.shutdown(socket.SHUT_RDWR)
        return address

    def sendfile(self, filepath):
        '''send single file to receiver'''
        fileSize = path.getsize(filepath)
        file = open(filepath)
        start = time.time()
        cnt = 0
        hasSend = 0
        speed = 0
        self.tcpClient.sendall(path.basename(filepath) + "|" + str(fileSize))
        while True:
            content = file.read(8192)
            if not content:
                break
            self.tcpClient.sendall(content)
            cnt += 8192
            hasSend += 8192
            end = time.time()

            if end - start >= 1:
                speed = (cnt / 1024) / (start - end)
                print("send finish:",hasSend / fileSize, "speed", speed)
                start = end
                hasSend = 0





    def receiveFile(self, savepath):
        '''receive file'''
        msg = self.tcpConnection.recv(1024)
        print("client send:", msg.decode())

        fileDesc = msg.decode().split("|")

        f = open(savepath + "/" + fileDesc[0], "wb")
        filesize = int(fileDesc[1])

        start = time.time()
        cnt = 0
        hasRecv = 0
        speed = 0
        while True:
            content = self.tcpConnection.recv(8192)
            if not content:
                break
            f.write(content)
            cnt += len(content)
            hasRecv += len(content)

            end = time.time()
            if end - start >= 1:
                speed = (cnt / 1024) / (end - start)
                print("recv finish:", int(hasRecv / filesize * 100), "speed:", speed, "size:", len(content))
                start = end
                cnt = 0



    def connectToReceiver(self, receiverAddr):
        self.tcpClient = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        print("connect server:", receiverAddr)
        self.tcpClient.connect(receiverAddr)
        print("send server msg")

        msg = socket.gethostname()
        self.tcpClient.sendall(msg.encode())
        msg = None
        msg = self.tcpClient.recv(1024)
        print("server reply:", msg.decode())
        return

    def waitSenderConnect(self, senderAddr):

        self.tcpServer = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.tcpServer.bind(("", self.port))
        print("waiting")
        self.tcpServer.listen(4)
        conn, senderAddr = self.tcpServer.accept()
        self.tcpConnection = conn
        print("connect by:", senderAddr)

        data = conn.recv(1024)
        print("client send:", data.decode())
        conn.sendall(data)


if __name__ == "__main__":
    serv = service()
    serv.connectToReceiver(('192.168.1.113', 8888))
    print("====================")
    serv.connectToReceiver(('192.168.1.113', 8888))




