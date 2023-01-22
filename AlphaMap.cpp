#include "AlphaMap.hpp"

// Constructor
AlphaMap::AlphaMap(){
    alpha = nullptr;
}

AlphaMap::AlphaMap( Polygon2D polygon ){

    // init
    alpha = nullptr;

    // Get bouding box to determine the size of the alpha map 
    pixel_index_t isx, isy, iex, iey;
    polygon.get_bounding_box( isx, isy, iex, iey );
    {
        int width_temp = iex - isx + 1;
        int height_temp = iey - isy + 1;
        if( width_temp <= 0 ){
            width_temp = 1;
        }else if( width_temp > this->max_size ){
            width_temp = max_size;
        }
        if( height_temp <= 0 ){
            height_temp = 1;
        }else if( height_temp > max_size ){
            height_temp = max_size;
        }
        this->width = width_temp;
        this->height = height_temp;
        this->center_x = -isx;
        this->center_y = -isy;
    }

    // alloc memory
    try{ 
        uint32_t size_of_map = this->width * this->height;
        this->alpha = new uint8_t[size_of_map];
        uint8_t* p = alpha;
        for( uint32_t n = 0; n < size_of_map; n++ ){
            *p = 0;
            p++;
        }
    }catch(std::bad_alloc){
        // do nothing
        return;
    }
    
    // Convert 
    Polygon2D polygon_shifted = (polygon + Point2D( this->center_x, this->center_y ));

    // pixel loop
    pixel_index_t pixel_index = 0;
    for( pixel_index_t iy = 0; iy < this->height; iy++ ){
        pixel_index_t sx_mix, sx_out;
        polygon_shifted.get_sx_mix_and_out( iy, sx_mix, sx_out );
        // 座標を画面内に制限
        if( sx_mix < 0 ) sx_mix = 0;
        if( sx_out > this->width -1 ) sx_out = this->width - 1;
         // 描画
        uint8_t *ppixel = this->alpha + sx_mix + iy * this->width;
        // 占有率を計算
        polygon.compute_covered_areas( iy, sx_mix, sx_out, ppixel );
        for( int ix = sx_mix; ix <= sx_out; ix++ ){
            *ppixel = (128 * (*ppixel) ) / Polygon2D::n_subpixels;
            ppixel++;
        }
    }
}

// Destructor
AlphaMap::~AlphaMap(){
    if( alpha != nullptr ){
        delete [] alpha;
    }
}
