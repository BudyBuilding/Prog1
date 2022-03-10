#include "new_window_type.h"

new_window_type::new_window_type(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    next_button{Point{x_max()-300,0}, 150, 40, "Next", 
    [](Address, Address pw) {reference_to<new_window_type>(pw).next(); }},

    quit_button{Point{x_max()-150,0}, 150, 40, "Quit", 
    [](Address, Address pw) {reference_to<new_window_type>(pw).quit(); }},

     menu_button{Point{x_max()-150,70}, 150, 40, "colors",
    [](Address, Address pw) {reference_to<new_window_type>(pw).hide_menu(); }},

    thick_menu_button{Point{x_max()-300,70}, 150, 40, "thick",
    [](Address, Address pw) {reference_to<new_window_type>(pw).hide_thick_menu(); }},


    next_x{Point{300,0}, 50, 40, "next_x:"},
    next_y{Point{450,0}, 50, 40, "next_y:"},
        
    xy_out{Point{100, 0}, 100, 40, "current x.y:"},
    
    colors{Point{x_max()-150, 70}, 150, 40, Menu::vertical, "colors"},

    thick{Point{x_max()-300, 70}, 150, 40, Menu::vertical, "thick"},

    
    red_menu_button{Point{x_max()-150,120}, 150, 40, "red",
    [](Address, Address pw) {reference_to<new_window_type>(pw).red_pressed(); }},

    blue_menu_button{Point{x_max()-150,165}, 150, 40, "blue",
    [](Address, Address pw) {reference_to<new_window_type>(pw).blue_pressed(); }},

    black_menu_button{Point{x_max()-150,210}, 150, 40, "black",
    [](Address, Address pw) {reference_to<new_window_type>(pw).black_pressed(); }},


    thick2_menu_button{Point{x_max()-300,120}, 150, 40, "thick2",
    [](Address, Address pw) {reference_to<new_window_type>(pw).thick2(); }},

    thick4_menu_button{Point{x_max()-300,165}, 150, 40, "thick4",
    [](Address, Address pw) {reference_to<new_window_type>(pw).thick4(); }},

    thick6_menu_button{Point{x_max()-300,210}, 150, 40, "thick6",
    [](Address, Address pw) {reference_to<new_window_type>(pw).thick6(); }},

    thick8_menu_button{Point{x_max()-300,255}, 150, 40, "thick8",
    [](Address, Address pw) {reference_to<new_window_type>(pw).thick8(); }}

{

    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);
    
    attach(menu_button);
    attach(thick_menu_button);

    colors.attach(red_menu_button);
    colors.attach(blue_menu_button);
    colors.attach(black_menu_button);

    thick.attach(thick1_menu_button);
    thick.attach(thick2_menu_button);
    thick.attach(thick3_menu_button);
    thick.attach(thick4_menu_button);
   
    attach(thick);
    thick.hide();

    

    attach(colors);
    colors.hide();


}

void new_window_type::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';

    xy_out.put(ss.str());

    redraw();
}

void new_window_type::quit()
{
    hide();
}

void new_window_type::hide_menu()
{

    menu_button.hide();
    colors.show();

}

void new_window_type::red_pressed()
{
    lines.set_color(Color::red);
    colors.hide();
    menu_button.show();

}

void new_window_type::blue_pressed()
{
    lines.set_color(Color::blue);
    colors.hide();
    menu_button.show();

}

void new_window_type::black_pressed()
{
    lines.set_color(Color::black);
    colors.hide();
    menu_button.show();

}

void new_window_type::hide_thick_menu()
{

    thick_menu_button.hide();
    thick.show();
    
}

void new_window_type::thick2()
{
    lines.set_style(Line_style(Line_style::solid,2));
    thick.hide();
    thick_menu_button.show();
}

void new_window_type::thick4()
{
    lines.set_style(Line_style(Line_style::solid,4));
    thick.hide();
    thick_menu_button.show();
}

void new_window_type::thick6()
{
    lines.set_style(Line_style(Line_style::solid,6));
    thick.hide();
    thick_menu_button.show();
}

void new_window_type::thick8()
{
    lines.set_style(Line_style(Line_style::solid,8));
    thick.hide();
    thick_menu_button.show();
}