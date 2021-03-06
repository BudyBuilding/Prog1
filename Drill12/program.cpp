//g++ program.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o program `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"
int main()
{
using namespace Graph_lib;
Point tl {100,100};

Simple_window win {tl,1000,700,"Canvas"};
//triangle
/*

	Polygon poly; // make a shape (a polygon)
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	poly.set_color(Color::red); // adjust properties of poly
	win.attach (poly); // connect poly to the window

*/


/*
//x axis
	Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};
	win.attach(xa);
	win.set_label("Canvas #2");
//y axis
	Axis ya {Axis::y, Point{20,300}, 280, 10, "kiskutya"};
	win.attach(ya);
	win.set_label("Canvas #3");

*/

//sine
/*

	Function sine {sin,0,100,Point{20,150},1000,50,50};
	sine.set_color(Color::yellow);
	win.attach(sine);
	win.set_label("Canvas #4");

*/


//polygon
/*

	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Canvas #5");
*/


//rectangle
/*

	Rectangle r {Point{200,200}, 100, 50};
	win.attach(r);
	win.set_label("Canvas #6");

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);

	poly_rect.add(Point{50,75});

*/


//fill
/*

	r.set_fill_color(Color::yellow);

//	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("Canvas #7");
*/


//text
/*

	Text t {Point{150,150}, "Hello, graphical world!"};
	win.attach(t);
	win.set_label("Canvas #8");

	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.set_label("Canvas #9");

*/

//image
/*

	Image ii {Point{100,50},"bombi.jpg"};
	win.attach(ii);
	win.set_label("Canvas #10");

//	ii.move(100,200);
//	win.set_label("Canvas #11");

*/


	Circle c {Point{100,200},50};
	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::dark_red);
	Mark m {Point{100,200},'x'};
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	Image cal {Point{225,225},"snow_cpp.gif"};
	cal.set_mask(Point{40,40},200,150);
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);

	win.set_label("Canvas #12");


win.wait_for_button();
}
