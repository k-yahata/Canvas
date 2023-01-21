#include "Polygon2D.hpp"

class AlphaMap{

    private:
    uint16_t width;
    uint16_t height;
    uint8_t *alpha;
    uint16_t center_x;
    uint16_t center_y;

    public:
    AlphaMap( );
    AlphaMap( Polygon2D polygon );

    

};
