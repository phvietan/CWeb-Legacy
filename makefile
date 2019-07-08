all: server.o
	g++ index.cpp server.o -std=c++11 -pthread -O2 -o main

server.o:
	g++ -std=c++11 -DBOOST_ERROR_CODE_HEADER_ONLY -pthread -O2 -c src/server/server.cpp

clean:
	rm *.o
	rm main