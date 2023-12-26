#include <ncurses.h>

class Widget {
private:
	int _x, _y, _height, _width;
public:
	Widget(int x, int y, int height, int width) : _height(height), _width(width), _x(x), _y(y) {};
	void print(WINDOW* scr) {
		// print area
		for (int i = _x; i < _width; i += _width - 1) {
			for (int j = _y; j < _height; j++) {
				mvwprintw(scr, j, i, "|");
			}
		}
		for (int i = _y; i < _height; i += _height - 1) {
			for(int j = _x + 1; j < _width - 1; j++) {
				mvwprintw(scr, i, j, "-");
			}
		}
	}
};
