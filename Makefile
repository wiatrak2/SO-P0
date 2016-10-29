Flags = -pthread -std=c++11 -Wall -Werror
CC = g++

all: main

main: main.cpp
	$(CC) $(Flags) -o main main.cpp

run: main
	./main

clean:
	rm main

.PHONY: all run clean