#pragma once
#include <ncurses.h>

class Widget {
protected:
	int _x, _y, _height, _width;
public:
	bool is_selected;
	Widget(int x, int y, int height, int width) : _height(height), _width(width), _x(x), _y(y) {};
	void print_area(WINDOW* scr) {
		// print area
		for (int i = _x; i < _x + _width; i += _width - 1) {
			for (int j = _y + 1; j < _y + _height - 1; j++) {
				mvwprintw(scr, j, i, "│");
			}
		}
		for (int i = _y; i < _y + _height; i += _height - 1) {
			for(int j = _x + 1; j < _x + _width - 1; j++) {
				mvwprintw(scr, i, j, "─");
			}
		}
		mvwprintw(scr, _y, _x, "┌");
		mvwprintw(scr, _y + _height - 1, _x, "└");
		mvwprintw(scr, _y, _x + _width - 1, "┐");
		mvwprintw(scr, _y + _height - 1, _x + _width - 1, "┘");
		if (is_selected) {
			mvwprintw(scr, _y, _x, "*");
		}
	}
	virtual void print_text(WINDOW* scr) = 0;
	void basic_events(char ch) {
		switch (ch) {
			case 'h': {
				_x--;
				break;
			}
			case 'l': {
				_x++;
				break;
			}
			case 'j': {
				_y++;
				break;
			}
			case 'k': {
				_y--;
				break;
			}
			case '[': {
				_width--;
				break;
			}
			case ']': {
				_width++;
				break;
			}
			case '.': {
				_height++;
				break;
			}
			case ',': {
				_height--;
				break;
			}
		}
	}
	virtual void get_events(char ch) = 0;
	virtual void update(WINDOW* scr, char ch) {
		if (is_selected) {
			basic_events(ch);
			get_events(ch);
		}
		print_area(scr);
		print_text(scr);
	}
};
