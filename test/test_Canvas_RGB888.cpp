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
    triangle.add_Point2D(Point2D(38,34));
    triangle.print();
    ColorRGB c0(200,0,255);
    ColorRGB c1(25,0,31);
    ColorRGB red(31,0,0);
    ColorGray cg0(128);
    uint8_t alpha = 64;

    canvas888.fill_polygon(triangle, c0, alpha);
    canvas_SSD1331.fill_polygon(triangle, c1, alpha);
    canvas_SSD1331.draw_polygon_HQ(triangle, 8.0, red, alpha);
    canvas_SSD1306.fill_polygon(triangle, cg0, alpha);

    canvas888.saveBMP("test_Canvas_RGB888.bmp");
    canvas_SSD1331.saveBMP("test_Canvas_SSD1331.bmp");
    canvas_SSD1306.saveBMP("test_Canvas_SSD1306.bmp");

    Canvas_SSD1331 copied_canvas;
    copied_canvas = canvas_SSD1331;
    copied_canvas.saveBMP("test_copied_canvas.bmp");


    Canvas_SSD1331 canvas3;
    Polygon2D outer, inner;
    outer.circle24( Point2D(48, 32), 30 );
    outer.add_Point2D( outer.get_Point2D(0) );
    inner.circle24( Point2D(48, 32), 28 );
    inner.add_Point2D( inner.get_Point2D(0) );
    outer.concat_inversely(inner);
    ColorRGB white(31,63,31 );
    canvas3.fill_polygon( outer, white, 0 );
    Polygon2D hour;
    hour.add_Point2D(  48, 6 );
    hour.add_Point2D(  48, 10 );
    for( int t = 0; t < 360; t+=30 ){
        hour.rotate_equal(30, Point2D(48,32));
        canvas3.draw_segments(hour, 2.0, white, 0 );
    }

    canvas3.saveBMP("test_circle.bmp");
    


    return 0;
}