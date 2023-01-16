#ifndef __CANVAS_RGB232_HPP__
#define __CANVAS_RGB232_HPP__

#include "Canvas.hpp"
#include "Color.hpp"

template < unsigned int WIDTH, unsigned int HEIGHT >
class Canvas_RGB232 : public Canvas<WIDTH, HEIGHT, 1, ColorRGB >{

    inline void get_Color( uint8_t *p_data, ColorRGB &color ) const override{
        uint8_t b0 = *p_data;
        // RRGGGBB
        color.color[0] = ( b0 >> 5 );
        color.color[1] = ((b0 >> 2) & 0x7);
        color.color[2] = ( b0 & 0x3);
    };
    inline void set_Color( uint8_t *p_data, ColorRGB &color ) override{
        *p_data     = (color.color[0] << 5) + (color.color[1] << 2) + color.color[2];
    };

    void Color_to_RGB888( ColorRGB &color,  uint8_t &r8, uint8_t &g8, uint8_t &b8 ) const override{
        r8 = color.color[0] * 0x55;  // RR * 0b01010101 = 0bRRRRRRRR
        g8 = color.color[1] * 0x24  + (color.color[1]>>1);   // GGG * 0b00100100 + (GGG >> 1) = 0bGGGGGGGG
        b8 = color.color[2] * 0x55;
    };
};

#endif