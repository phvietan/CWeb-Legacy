all: server.o util.o
	g++ -std=c++11 index.cpp server.o util.o -pthread -O2 -o main -lboost_system -lboost_filesystem

util.o:
	g++ -std=c++11 -O2 -c src/util/util.cpp

server.o:
	g++ -std=c++11 -DBOOST_ERROR_CODE_HEADER_ONLY -pthread -O2 -c src/server/server.cpp

clean:
	rm *.o
	rm main