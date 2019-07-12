all: server.o fileServer.o path.o
	g++ -std=c++11 index.cpp server.o fileServer.o path.o -pthread -O2 -o main -lboost_system -lboost_filesystem

server.o:
	g++ -std=c++11 -DBOOST_ERROR_CODE_HEADER_ONLY -pthread -O2 -c src/server/server.cpp

fileServer.o:
	g++ -std=c++11 -O2 -c src/fileServer/fileServer.cpp

path.o:
	g++ -std=c++11 -O2 -c src/path/path.cpp

clean:
	rm *.o
	rm main