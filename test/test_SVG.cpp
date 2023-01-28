#include "SVG.hpp"
#include <cmath>
int main(){

    SVG svg;

    VectorPicture vp;

    ColoredPolygon2D cp;
    cp.polygon.add_Point2D(10,10);
    cp.polygon.add_Point2D(10,20);
    cp.polygon.add_Point2D(20,10);
    cp.set_color( 0, 0, 255, 128 );
    vp.add_ColoredPolygon(cp);

    cp.polygon += Point2D(20,20);    
    cp.set_color( 255, 0, 0, 128 );
    vp.add_ColoredPolygon(cp);

    Polygon2D circle;
    double rad = 3.14159265358979 / 180.0;
    for( int t = 0; t <= 360; t+=3 ){
        double sin_t = sin(t*rad);
        double cos_t = cos(t*rad);
        Point2D p(cos_t,sin_t);
        circle.add_Point2D(p);
    }
    for( int t = 360; t >= 0; t-=3 ){
        double sin_t = 0.9*sin(t*rad);
        double cos_t = 0.9*cos(t*rad);
        Point2D p(cos_t,sin_t);
        circle.add_Point2D(p);
    }

    circle *= 100.0;
    circle +=Point2D(100,100);
    cp.polygon = circle;
    cp.set_color( 0, 128, 0, 32 );
    vp.add_ColoredPolygon(cp);

    svg.set_VectorPicture(vp);

    svg.save("test.svg");

    return 0;
}