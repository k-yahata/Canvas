#ifndef __SVG_HPP__
#define __SVG_HPP__
#include "VectorPicture.hpp"
#include "Color.hpp"
#include <vector>
#include <string>

class SVG{

    public:
    // copy ColoredPolygons in vp into internal VectorPicture
    void set_VectorPicture( VectorPicture &vp );

    void add_Polygon(Polygon2D &polygon, ColorRGB color, uint8_t alpha = 128 );
    void add_ColoredPolygon(ColoredPolygon2D &cp );

    // save a SVG file
    int save( std::string file_name );
    // read( std::string file_name );
    
    private:
    VectorPicture pic;

    std::string get_svg_command_from_a_ColoredPolygon( ColoredPolygon2D &cp );

    // std::string file_name;
    // ifstream fin;
    // ofstream fout;


};

#endif