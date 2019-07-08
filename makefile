all:
	g++ -DBOOST_ERROR_CODE_HEADER_ONLY -pthread -O2 index.cpp -o main

clean:
	rm main