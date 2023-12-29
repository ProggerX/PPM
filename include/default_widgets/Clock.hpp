#include <CommandWidget.hpp>

class Clock : public CommandWidget {
public:
	Clock (int x, int y, int height, int width, std::string time_command, bool show_seconds) : CommandWidget(x, y, height, width, time_command + " $(date +%H:%M" + (show_seconds ? ":%S" : "") + ")") {};
};
