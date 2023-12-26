#include <ncurses.h>
#include "Widget.hpp"

#include "default_widgets/Clock.hpp"

int main() {
	initscr();
	nodelay(stdscr, true);
	curs_set(0);
	noecho();

	Widget w(0, 0, 15, 15);
	while (getch() != 'q') {w.print(stdscr);}
	endwin();
}
