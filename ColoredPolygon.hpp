#ifndef __COLORED_POLYGON_2D_HPP_
#define __COLORED_POLYGON_2D_HPP_

#include "Polygon2D.hpp"

class ColoredPolygon2D : public Polygon2D {
    public:
    unsigned char r; // 0-31
    unsigned char g; // 0-63
    unsigned char b; // 0-31
    float alpha;

    inline void set_color( const unsigned char r, const unsigned char g, const unsigned char b, const float alpha ){
        this->r = r;
        this->g = g;
        this->b = b;
        this->alpha = alpha;
    }
};

#endif