.PHONY:all
all:tcpClient tcpServer

tcpClient:tcpClient.cpp
	g++ -o $@ $^ 
tcpServer:tcpServer.cpp
	g++ -o $@ $^ 

.PHONY:clean
clean:
	rm tcpClient tcpServer
