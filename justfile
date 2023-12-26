default: build run clean

build:
	g++ ./src/*.cpp -oout -I./include/ -lncurses

run:
	./out

clean:
	rm -rf ./out
