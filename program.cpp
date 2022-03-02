/*
    g++ program.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o program `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
  using namespace Graph_lib;

    int xmax = 1000;
    int ymax = 800;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};



/*
    Lines grid;
    
    int a = ymax / 8;
    int b = xmax / 8;
    for (int i=1; i < 8; i++) 
        grid.add(Point(0, i*100),Point(800, i*100));   
    for (int i=1; i < 9; i++) 
        grid.add(Point(i*100, 0),Point(i*100, 800));   
    win.attach(grid); 
  */

/*
Vector_ref<Rectangle> vr;  // use like vector
                    // but imagine that it holds references to objects
for (int i = 0; i<16; ++i) {        // i is the horizontal coordinate
    for (int j = 0; j<16; ++j) {    // j is the vertical coordinate
        vr.push_back(new Rectangle(Point(i*20,j*20),20,20));
        vr[vr.size()-1].set_fill_color(i*16+j);
        win.attach(vr[vr.size()-1]);
    }
}
*/



    Vector_ref<Rectangle> vr;  
    for (int i = 0; i<8; ++i) {        
        for (int j = 0; j<8; ++j) {   
            vr.push_back(new Rectangle(Point(i*100,j*100),100,100));
            if (i == j){
                vr[vr.size()-1].set_fill_color(Color::red);
            }
            win.attach(vr[vr.size()-1]);
    }
    }

    /*
    Image ii1 {Point(400,0),"car.jpg"};
    win.attach(ii1);
    Image ii2 {Point(200,600),"car.jpg"};
    win.attach(ii2);
    Image ii3 {Point(600,200),"car.jpg"};
    win.attach(ii3);
    */
    int x = 0;
    int y = 0;
    Image ii4 {Point(0,0),"car1.jpg"};
    win.attach(ii4);

    int a = 5;



    while (a < 6)
        {
        for(int j = 0; j < 8; j++)
        	{
        	for (int i = 0; i<8; i++)
         		{
         		//	win.wait_for_button();
             		x = 100; 
             		ii4.move(x,y);
         		}
         	ii4.move(-800, 100);
			}
			ii4.move(-800,-800);

        }




} 