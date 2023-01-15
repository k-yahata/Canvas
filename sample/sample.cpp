#include "ClockDrawer.hpp"
#include <time.h>
#include <sys/time.h>
#include <iostream>

int main(){
    Drawer drawer;
    drawer.init();

    Canvas_SSD1331 canvas;

    struct timeval st_time;
    gettimeofday( &st_time, NULL );
    struct tm *p_tm = localtime( &(st_time.tv_sec) );

    drawer.draw_clock( canvas, p_tm->tm_hour, p_tm->tm_min, p_tm->tm_sec + st_time.tv_usec/1000000.0f );
    //drawer.draw_clock( canvas, 10, 10, 25.5f );

    canvas.saveBMP("Clock.bmp");
}