default: build run clean

build:
	g++ ./src/*.cpp -oout -I./include/ -lncursesw -w

run:
	./out

clean:
	rm -rf ./out ./*output.txt

install: build
	cp ./out ~/.local/bin/ppm

first_install: install
	cp ./src/example_config.hpp ./src/config.hpp
