#include <commons.h>
#include <unistd.h>

class ExampleWidget : public Widget {
public:
	ExampleWidget(int x, int y, int height, int width) : Widget(x, y, height, width) {}
	void print_text(WINDOW* scr) {
		mvwprintw(scr, _y + 1, _x + 1, "Click(Enter) for exit");
	}
	void get_events(char ch) {
		if (ch == '\n') {
			exit(0);
		}
	}
};
