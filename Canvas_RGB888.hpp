#ifndef __CANVAS_RGB888_HPP__
#define __CANVAS_RGB888_HPP__

#include "Canvas.hpp"
#include "Color.hpp"

template < unsigned int WIDTH, unsigned int HEIGHT >
class Canvas_RGB888 : public Canvas<WIDTH, HEIGHT, 3, ColorRGB>{
    
    inline void get_Color( uint8_t *p_data, ColorRGB &color ) const override{
        color.color[0] = *(p_data  );
        color.color[1] = *(p_data+1);
        color.color[2] = *(p_data+2);
    };
    inline void set_Color( uint8_t *p_data, ColorRGB &color ) override{
        *p_data     = color.color[0];
        *(p_data+1) = color.color[1];
        *(p_data+2) = color.color[2];
    };

    void Color_to_RGB888( ColorRGB &color, uint8_t &r8, uint8_t &g8, uint8_t &b8 ) const override{
        r8 = color.color[0];
        g8 = color.color[1];
        b8 = color.color[2];
    };

};

#endif