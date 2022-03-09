// g++ program.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o program `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x)+slope(x); }




int main()
{
using namespace Graph_lib;
Point tl {1000,100};
Point orig{300,300};

Simple_window win {tl,600,600,"Canvas"};

Axis x{Axis::x, Point{100,300}, 400,
20};

Axis y{Axis::y, Point{300,500}, 400,
20};

x.set_color(Color::red);
y.set_color(Color::red);


Function s(one,-10,11, orig, 400, 20, 20);
Function s2(slope,-10,11,orig,400);
Function s3(square,-10,11,orig,400);

win.attach(s);
win.attach(s2);

Text t(Point{560,150}, "X/2");
win.attach(t);

win.attach(s3);

Function s4(cos,-10,11,orig,400,20,20);
s4.set_color(Color::blue);


Function s5(sloping_cos,-10,11,orig,400,20,20);

win.attach(s4);
win.attach(s5);

win.attach(x);
win.attach(y);
win.wait_for_button();


}