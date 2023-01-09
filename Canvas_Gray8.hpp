#include "Canvas.hpp"
#include "Color.hpp"

template < unsigned int WIDTH, unsigned int HEIGHT >
class Canvas_Gray8 : public Canvas<WIDTH, HEIGHT, 1, ColorGray>{
    
    inline void get_Color( uint8_t *p_data, ColorGray &color ) const override{
        color.color[0] = *(p_data  );
    };
    inline void set_Color( uint8_t *p_data, ColorGray &color ) override{
        *p_data     = color.color[0];
    };

    void Color_to_RGB888( ColorGray &color, uint8_t &r8, uint8_t &g8, uint8_t &b8 ) const override{
        r8 = color.color[0];
        g8 = color.color[0];
        b8 = color.color[0];
    };

};