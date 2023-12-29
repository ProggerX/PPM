# WARNING!!! README IS NOT FINISHED!!!
# PPM is highly-customizable dashboard with widgets

### You can create your own widgets on c++!

# Classes:
- ```Widget(int x, int y, int height, int width)``` -- ```include/widget.hpp``` -- an abstract widget class
- ```CommandWidget(int x, int y, int height, int width, std::string cmd) : public Widget``` -- ```include/CommandWidget.hpp``` -- a class with additional ```cmd``` field that runs **NOT ENDLESS** command every update and shows output in widget
- ```Clock(int x, int y, int height, int width, std::string time_command, bool show_seconds)``` -- ```include/default_widgets/Clock.hpp``` -- a digital 
