#include <unistd.h>
#include <ncurses.h>
#include <commons.h>
#include <unistd.h>
#include <chrono>
#include <Stopwatch.hpp>
#include "config.hpp"

std::string keys = "qwertyuiopasdfghjklzxcvbnm[].,1234567890\n\t ";

int selected = 0;

void get_global_events(char ch, std::vector<Widget*>& wgts) {
	switch (ch) {
		case '\t': {
			if (selected >= wgts.size() - 1) {
				selected = 0;
				wgts[wgts.size() - 1]->is_selected = false;
				wgts[0]->is_selected = true;
			}
			else {
				wgts[selected]->is_selected = false;
				selected++;
				wgts[selected]->is_selected = true;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "");
	system("mkdir ppm-cache");

	Stopwatch stpw;
	stpw.start();

	initscr();
	nodelay(stdscr, true);
	curs_set(0);
	noecho();

	std::vector<Widget*> wgts;
	char ch;

	wgts = get_wgts();

	wgts[0]->is_selected = true;

	std::for_each(wgts.begin(), wgts.end(), [&ch](Widget* wgt){
		wgt->update(stdscr, '0');
	});


	while (ch != 'q') {
		ch = getch();
		get_global_events(ch, wgts);
		if (keys.find(ch) != std::string::npos) {
			clear();
			std::for_each(wgts.begin(), wgts.end(), [&ch](Widget* wgt){ wgt->update(stdscr, ch); });
		}
		else {
			std::for_each(wgts.begin(), wgts.end(), [&ch](Widget* wgt){ wgt->update(stdscr, ch); });
		}
		refresh();
	}
	system("rm -rf ppm-cache");
	endwin();
}
