[日本語はこちら](ReadMe_ja.md)
# What is this?
- This repository contains classes to provide 2D vector graphics with __antialiasing__
and alpha blending for small displays drived by microcomputers like ESP32. 

- These classes only provide image data array and draw functions to edit the image data, 
and do not provide any display drivers. 
Therefore, in order to display the image data to the displays, appropriate drivers are necessary 
to send the image data to a display controller.

- The class "Canvas" is the base, template class containing data array and 
drawing functions. Three virtual functions shoud be defined in derived class 
in order to support specific data format.

- The Canvas class has 4 template parameters, width, heighet, bytes per pixel and Color class. 
Therefore, this Canvas class is designed so that the instance of the derived
class has memory for the entire image data. 
This memory is necessary for antialiasing and alpha blending.


# How to use.
## Define sub class when the data format og the disply has been implemented.
1. If the data format is RGB232 (2bytes), RGB565 (2bytes) or grayscale(1bytes), define sub class from 
Canvas_RGB232, Canvas_RGB565 class or Canvas_Gray8 with specifying images size like below. 
```
#include "Canvas_RGB565.hpp"

class Canvas_SSD1331 : public Canvas_RGB565<96,64>{};
```
Then, you can draw polygons like below:
```
Canvas_SSD1331 canvas;
Polygon2D polygon;
polygon.add_Point2D(Point2D( 48, 10 ));
polygon.add_Point2D(Point2D( 28, 50 ));
polygon.add_Point2D(Point2D( 68, 50 ));
ColorRGB c(0,0,31);
uint8_t alpha = 128;
canvas.fill_polygon( polygon, c, alpha );

// Save BMP file to see the image.
canvas.saveBMP("test.bmp");
```
For more details, please see examples.

## Define sub class when the data format has not been implemented.
1. Define a sub class from the Canvas class with the 4 template parameters.
    This section will be written later.
    
1. Define the three virtual functions of the Canvas class in the sub class.
    ```
    inline void set_Color( uint8 *p_data, Color &color ) const override{};
    inline void set_Color( uint8 *p_data, Color &color ) override{};
    void Color_to_RGB888( Color &color,  uint8 &r8, uint8 &g8, uint8 &b8 ) const override{};
    ```
    The function, get_RGB() and set_RGB() are functions to get/set pixel values from a head pointer to a pixel.
    The function, RGB_to_RGB888() is a function to convert the RGB values to 8-bit length RGB to save BMP file.
    
## 
