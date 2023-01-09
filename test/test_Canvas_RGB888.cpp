#include "Canvas_888.hpp"
#include "Canvas_SSD1331.hpp"
#include "Canvas_SSD1306.hpp"
#include "Color.hpp"

int main(){

    Canvas_888 canvas888;
    Canvas_SSD1331 canvas_SSD1331;
    Canvas_SSD1306 canvas_SSD1306;

    Polygon2D triangle;
    triangle.add_Point2D(Point2D(10,10));
    triangle.add_Point2D(Point2D(86,20));
    triangle.add_Point2D(Point2D(48,54));
    triangle.print();
    ColorRGB c0(200,0,255);
    ColorRGB c1(25,0,31);
    ColorGray cg0(128);
    uint8_t alpha = 64;

    canvas888.fill_polygon(triangle, c0, alpha);
    canvas_SSD1331.fill_polygon(triangle, c1, alpha);
    canvas_SSD1306.fill_polygon(triangle, cg0, alpha);

    canvas888.saveBMP("test_Canvas_RGB888.bmp");
    canvas_SSD1331.saveBMP("test_Canvas_SSD1331.bmp");
    canvas_SSD1306.saveBMP("test_Canvas_SSD1306.bmp");

    return 0;
}