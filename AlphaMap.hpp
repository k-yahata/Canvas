#ifndef __ALPHA_MAP_HPP_
#define __ALPHA_MAP_HPP_

#include "Polygon2D.hpp"

/*==============================================================//
  class AlphaMap
     2D image of alpha channnel.
     The alpha value should be in range from 0 to 128, where 0 
     means transparent and 128 means opaque.
/===============================================================*/

class AlphaMap{

    private:
    static const uint16_t max_size = 16384;

    private:
    uint16_t width;
    uint16_t height;
    uint8_t *alpha;
    int16_t center_x;
    int16_t center_y;

    public:
    AlphaMap( );
    // Create the alpha map from Polygon2D.
    AlphaMap( Polygon2D polygon );
    //
    ~AlphaMap();
    
    // return center_x
    inline int16_t cx() const{ return center_x; }
    // return center_y
    inline int16_t cy() const{ return center_y; }
    // return center_x
    inline uint16_t w() const{ return width; }
    // return center_y
    inline uint16_t h() const{ return height; }
    
    // 
    uint8_t* get_pointer_at( pixel_index_t x, pixel_index_t y );

    inline bool not_defined(){ return (alpha == nullptr); }
};

#endif