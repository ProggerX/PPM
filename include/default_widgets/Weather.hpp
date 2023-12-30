#include <CommandWidget.hpp>

class CompactWeather : public CommandWidget {
public:
	CompactWeather (int x, int y, int height, int width) : CommandWidget(x, y, height, width, "curl 'https://wttr.in/?format=1' -s") {};
};
