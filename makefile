all: server.o fileHandler.o pathHandler.o
	g++ -std=c++11 index.cpp server.o fileHandler.o pathHandler.o -pthread -O2 -o main -lboost_system -lboost_filesystem

server.o:
	g++ -std=c++11 -DBOOST_ERROR_CODE_HEADER_ONLY -pthread -O2 -c src/server/server.cpp

fileHandler.o:
	g++ -std=c++11 -O2 -c src/fileHandler/fileHandler.cpp

pathHandler.o:
	g++ -std=c++11 -O2 -c src/pathHandler/pathHandler.cpp

clean:
	rm *.o
	rm main