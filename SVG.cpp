#include "SVG.hpp"
#include <fstream>
#include <sstream>

void SVG::set_VectorPicture( VectorPicture &vp ){
    this->pic = vp;
}

void SVG::add_Polygon( Polygon2D &polygon, ColorRGB color, uint8_t alpha ){
    this->pic.add_ColoredPolygon( ColoredPolygon2D( polygon, color ));
}
void SVG::add_ColoredPolygon(ColoredPolygon2D &cp ){
    this->pic.add_ColoredPolygon( ColoredPolygon2D(cp) ); 
}
int SVG::save( std::string file_name ){
    std::ofstream fout(file_name.c_str(), std::ios::out);
    if( !fout ){
        return -1;
    }
    // header
    fout << "<?xml version=\"1.0\"?>\n";
    fout << "    <svg xmlns=\"http://www.w3.org/2000/svg\">\n";

    // data
    int n_polygons = (this->pic).p.size();
    for( int n = 0; n < n_polygons; n++ ){
        fout << get_svg_command_from_a_ColoredPolygon(this->pic.p[n]) << std::endl;
    }

    //footer
    fout << "</svg>" << std::endl;

    fout.close();

    return 0;
}
//SVG::read( std::string file_name );

std::string SVG::get_svg_command_from_a_ColoredPolygon( ColoredPolygon2D &cp ){
    std::string out_str = "<polygon points=\"";
    int n_points = cp.polygon.size();
    for( int n = 0; n < n_points; n++ ){
        Point2D p = cp.polygon.get_Point2D(n);
        out_str += (std::to_string(p.x/internal_scale) + " " + std::to_string(p.y/internal_scale) + ", " );
    }    
    out_str += ("\" fill=\"#");

std::cout << "COLOR" << std::endl;
    // color
    std::stringstream ss;
    if( cp.face_color.color[0] < 16 ){
        ss << "0";
    }
    ss << std::hex << (int)cp.face_color.color[0];
std::cout << ss.str() << std::endl;

    if( cp.face_color.color[1] < 16 ){
        ss << "0";
    }    
    ss  << std::hex << (int)cp.face_color.color[1];
std::cout << ss.str() << std::endl;

    if( cp.face_color.color[2] < 16 ){
        ss << "0";
    }
    ss << std::hex << (int)cp.face_color.color[2];
std::cout << ss.str() << std::endl;

    uint16_t alpha_scaled = 2*(uint16_t)cp.alpha;
    if( alpha_scaled >= 256 ) alpha_scaled = 255;
    if( alpha_scaled < 16 ){
        ss << "0";
    }
    ss << std::hex << alpha_scaled;   
std::cout << ss.str() << std::endl;

    std::cout << (int)cp.face_color.color[0] << std::endl;
    std::cout << (int)cp.face_color.color[1] << std::endl;
    std::cout << (int)cp.face_color.color[2] << std::endl;
    std::cout << (int)cp.alpha << std::endl;
    out_str += (ss.str() + "\" />");

    return out_str;
}