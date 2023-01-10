#ifndef __COLORED_POLYGON_2D_HPP_
#define __COLORED_POLYGON_2D_HPP_

#include "Polygon2D.hpp"

class ColoredPolygon2D : public Polygon2D {
    public:
    uint8_t r;
    uint8_t g;
    uint8_t b;
    float alpha;

    inline void set_color( const unsigned char r, const unsigned char g, const unsigned char b, const float alpha ){
        this->r = r;
        this->g = g;
        this->b = b;
        this->alpha = alpha;
    }
};

#endif