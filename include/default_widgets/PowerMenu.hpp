#include <commons.h>
#include <Widget.hpp>

class PowerButton {
private:
	std::string* _cmd;
	std::vector<std::string>* _lines;
public:
	PowerButton(std::vector<std::string>* lines, std::string* cmd) : _lines(lines), _cmd(cmd) {}
	void print(WINDOW* scr, int x, int y) {
		mvwprintw(scr, y, x, _lines[0][0].c_str());
		mvwprintw(scr, y + 1, x, _lines[0][1].c_str());
		mvwprintw(scr, y + 2, x, _lines[0][2].c_str());
	}
	void clicked() {
		system(_cmd->c_str());
	}
};

std::map<std::string, std::vector<std::string>> lines = {
	{"poweroff", {"┌─╂─┐","│   │","└───┘"}},
	{"reboot", {"<───┐","│   │","└───┘"}},
	{"logout", {"┌───┐","│  ─>","└───┘"}},
	{"lockscreen", {"┌───┐","│ ⚿ │","└───┘"}}
};

class PowerMenu : public Widget {
private:
	int _mode = 0;
	int selected = 0;
	std::string _poweroff_cmd = "systemctl poweroff",
				_reboot_cmd = "systemctl reboot",
				_logout_cmd = "pkill Hyprland",
				_lockscreen_cmd = "lockscreen";
	std::vector<PowerButton> buttons;
	void change_select() {
		if (selected >= buttons.size() - 1) {
			selected = 0;
		}
		else {
			selected++;
		}
	}
	
	void setup() {
		buttons.clear();
		if (_mode == 0) {
			buttons.push_back(PowerButton(&lines["poweroff"], &_poweroff_cmd));
			buttons.push_back(PowerButton(&lines["reboot"], &_reboot_cmd));
			buttons.push_back(PowerButton(&lines["logout"], &_logout_cmd));
			buttons.push_back(PowerButton(&lines["lockscreen"], &_lockscreen_cmd));
		}
	}
public:
	PowerMenu (int x, int y, int height, int width) : Widget(x, y, height, width) {setup();}
	PowerMenu (int x, int y, int height, int width, int mode) : _mode(mode), Widget(x, y, height, width) {setup();}
	void set_poweroff_command (std::string cmd) {
		_poweroff_cmd = cmd;
		setup();
	}
	void set_reboot_command (std::string cmd) {
		_reboot_cmd = cmd;
		setup();
	}
	void set_logout_command (std::string cmd) {
		_logout_cmd = cmd;
		setup();
	}
	void set_lockscreen_command (std::string cmd) {
		_lockscreen_cmd = cmd;
		setup();
	}
	void get_events (char ch) {
		if (ch == '\n') {
			buttons[selected].clicked();
		}
		if (ch == ' ') {
			change_select();
		}
	}
	void print_text(WINDOW* scr) {
		int y = _y + _height / 2 - 1;
		int x = _x + (_width / 2) - (buttons.size() * 6 - 1) / 2;
		for (int i = 0; i < buttons.size(); i++) {
			buttons[i].print(scr, x + i * 6, y);
		}
		mvwprintw(scr, y, x + selected * 6, "*");
	}
};
