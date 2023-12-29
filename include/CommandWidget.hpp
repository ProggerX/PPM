#pragma once
#include <iostream>
#include <commons.h>

class CommandWidget : public Widget {
protected:
	std::string _cmd = "echo Hello World!";
public:
	CommandWidget(int x, int y, int height, int width, std::string cmd) : _cmd(cmd), Widget(x, y, height, width) {

	};
	virtual void print_text(WINDOW* scr) {
		system((_cmd + " > '" + std::to_string(_x) + std::to_string(_y) + "_output.txt'&").c_str());
		std::ifstream file(std::to_string(_x) + std::to_string(_y) + "_output.txt");
		std::vector<std::string> lines;
		std::string tmp;
		while(std::getline(file, tmp)) lines.push_back(tmp);
		file.close();
		int y = _y + (_height / 2) - lines.size() / 2;
		for (int i = y; lines.size() > 0; i++) {
			int x = _x + (_width / 2) - lines.back().size() / 2;
			mvwprintw(scr, i, x, lines.front().c_str());
			lines.erase(lines.begin());
		}
	}
	virtual void get_events(char ch) {}
};
