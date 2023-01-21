#include "Polygon2D.hpp"


int main(){

    Point2D p0(0,0);
    Point2D p1(10,10);

    Polygon2D line_segment;
    line_segment.line_segment( p0, p1, 1.41421356 );
    line_segment.print();

    Polygon2D rectangle;
    rectangle.rectangle( p0, p1);
    rectangle.print();
}