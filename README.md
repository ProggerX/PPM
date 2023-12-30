# PPM is highly-customizable dashboard with widgets

### You can create your own widgets on c++!

# Requirements:
### U need to recompile ppm on every config change, so:
- compiler (i use g++)
- ncursesw library
### U also need
- Linux host
- terminal with unicode support

# Usage:
q - exit
Tab - select next widget
Events only captured by selected widget
h j k l (like vim) - move selected widget
[ - widget width - 1
] - widget width + 1
, - widget height - 1
. - widget height + 1

# How to create ur own widget
- Ur class should be in ```include/custom_widgets/``` and named like SomeWidget.hpp
- Ur class should inherit ```Widget``` class
- Ur class should have ```void print_text(WINDOW* scr)``` method and ```get_events(char ch)```
#### You can look for example in include/custom_widgets/ExampleWidget.hpp

# Classes (list is not finished):
- ```Widget(int x, int y, int height, int width)``` -- ```include/widget.hpp``` -- an abstract widget class
- ```CommandWidget(int x, int y, int height, int width, std::string cmd) : public Widget``` -- ```include/CommandWidget.hpp``` -- a class with additional ```cmd``` field that runs **NOT ENDLESS** command every update and shows output in widget
- ```Clock(int x, int y, int height, int width, std::string time_command, bool show_seconds)``` -- ```include/default_widgets/Clock.hpp``` -- a digital 
