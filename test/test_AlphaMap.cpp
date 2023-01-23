#include "Canvas_SSD1331.hpp"
#include "Color.hpp"
#include "AlphaMap.hpp"

int main(){

    Canvas_SSD1331 canvas_SSD1331;

    Polygon2D triangle;
    triangle.add_Point2D(Point2D(10,10));
    triangle.add_Point2D(Point2D(86,20));
    triangle.add_Point2D(Point2D(58,54));
    AlphaMap a_triangle(triangle);

    Polygon2D circle;
    circle.circle24( Point2D(65.3,20.4), 25.3 );
    AlphaMap a_circle(circle);

    Polygon2D square;
    square.rectangle( Point2D(-22.5,-22.5), Point2D(22.5, 22.5));
    square.rotate_equal(23.0);
    square += Point2D( 35.0, 45.0);
    AlphaMap a_square(square);


    ColorRGB color_triangle(31,0,0);
    ColorRGB color_circle(0,0,31);
    ColorRGB color_square(0,63,0);
    uint8_t alpha = 64; 


    canvas_SSD1331.draw_AlphaMap(a_triangle, 0, 0, color_triangle, alpha);
    //canvas_SSD1331.fill_polygon(circle, color_circle, alpha);
    //canvas_SSD1331.fill_polygon(square, color_square, alpha);

    canvas_SSD1331.saveBMP("test_AlphaMap.bmp");
    


    return 0;
}