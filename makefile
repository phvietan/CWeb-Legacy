all: fileHandler.o pathHandler.o pageServer.o staticServer.o specialServer.o server.o
	g++ -std=c++11 index.cpp fileHandler.o pathHandler.o pageServer.o staticServer.o specialServer.o server.o -pthread -O2 -o main -lboost_system -lboost_filesystem

fileHandler.o:
	g++ -std=c++11 -O2 -c src/fileHandler/fileHandler.cpp

pathHandler.o:
	g++ -std=c++11 -O2 -c src/pathHandler/pathHandler.cpp

pageServer.o:
	g++ -std=c++11 -pthread -O2 -c src/pageServer/pageServer.cpp

staticServer.o:
	g++ -std=c++11 -pthread -O2 -c src/staticServer/staticServer.cpp

specialServer.o:
	g++ -std=c++11 -pthread -O2 -c src/specialServer/specialServer.cpp

server.o:
	g++ -std=c++11 -DBOOST_ERROR_CODE_HEADER_ONLY -pthread -O2 -c src/server/server.cpp

clean:
	rm *.o
	rm main