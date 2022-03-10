/*
g++ program5.cpp Graph.cpp Window.cpp GUI.cpp new_window_type.cpp -o program5 `fltk-config --ldflags --use-images` -std=c++11
*/


#include "new_window_type.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	new_window_type win(Point{100,100}, 1920, 1080, "okay");

	return gui_main();



}