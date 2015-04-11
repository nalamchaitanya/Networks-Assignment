all: main.o
	g++ -o HuffmanTransceiver main.o;

main.o:
	g++ -c main.cpp;