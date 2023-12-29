#include <commons.h>

#include <default_widgets/Clock.hpp>
#include <default_widgets/Weather.hpp>


std::vector<Widget*> get_wgts() {
	std::vector<Widget*> vec;

	// WIDGETS LIST BEGIN

	vec.push_back(new Clock(0, 0, 11, 33, "cowsay", true));
	vec.push_back(new CompactWeather(0, 11, 5, 19));

	// WIDGETS LIST END

	return vec;
}
