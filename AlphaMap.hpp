#include "Polygon2D.hpp"

/*==============================================================//
  class AlphaMap
     2D image of alpha channnel.
     The alpha value should be in range from 0 to 128, where 0 
     means opaque and 128 means transparent.
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
    
    
};
