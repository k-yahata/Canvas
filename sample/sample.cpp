#include "ClockDrawer.hpp"

int main(){
    Drawer drawer;
    drawer.init();

    Canvas_SSD1331 canvas;

    drawer.draw_clock( canvas, 10, 10, 25.0f );

    canvas.saveBMP("Clock.bmp");
}