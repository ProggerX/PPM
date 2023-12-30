#include <commons.h>

#include <default_widgets/Clock.hpp>
#include <default_widgets/PowerMenu.hpp>
#include <default_widgets/Weather.hpp>
#include <custom_widgets/ExampleWidget.hpp>


std::vector<Widget*> get_wgts() {
	std::vector<Widget*> vec;

	// WIDGETS LIST BEGIN

	vec.push_back(new Clock(0, 0, 12, 33, "cowsay", true));
	vec.push_back(new CompactWeather(34, 0, 7, 27));
	vec.push_back(new PowerMenu(34, 7, 5, 27));
	vec.push_back(new ExampleWidget(20, 30, 7, 40));

	// WIDGETS LIST END

	return vec;
}
