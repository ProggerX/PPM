default: build run clean

build:
	g++ ./src/*.cpp -oout -I./include/ -lncurses -w

run:
	./out

clean:
	rm -rf ./out *output.txt
