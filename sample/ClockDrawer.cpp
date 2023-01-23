#include "ClockDrawer.hpp"

const ColorRGB Drawer::color_dial(31,63,31);
const ColorRGB Drawer::color_hour_hand(31,0,0);
const ColorRGB Drawer::color_minute_hand(0,63,0);
const ColorRGB Drawer::color_second_hand(0,0,31);


void Drawer::init(){
    // hour hand, 短針
    hour_hand.add_Point2D(46,17);
    hour_hand.add_Point2D(50,17);
    hour_hand.add_Point2D(50,34);
    hour_hand.add_Point2D(46,34);
    // minute hand, 分針
    minute_hand.add_Point2D(46.5,6);
    minute_hand.add_Point2D(49.5,6);
    minute_hand.add_Point2D(49.5,34);
    minute_hand.add_Point2D(46.5,34);
    // second hand, 秒針
    second_hand.add_Point2D(47,6);
    second_hand.add_Point2D(49,6);
    second_hand.add_Point2D(49,34);
    second_hand.add_Point2D(47,34);

    // Define the dial, 文字盤の定義
    // Define a ring as the frame of the clock. 文字盤の外側のリングを二重の円で表現する
    ColoredPolygon2D frame;
    Polygon2D temp;
    // The center of the circle
    Point2D center(48,32); 
    // outer circle
    frame.polygon.circle24( center, 30 );  // center, radius / 中心座標, 半径
    // close the circle, 円を閉じる
    frame.polygon.add_Point2D( frame.polygon.get_Point2D(0));
    // inner circle
    temp.circle24(center, 28 );
    // close the circle, 円を閉じる
    temp.add_Point2D(temp.get_Point2D(0));
    // 外円に内円を逆順で追加する
    frame.polygon.concat_inversely( temp );
    // set color and transparency, 色と透明度の設定
    frame.face_color = this->color_dial;
    frame.alpha = 128;
    // 文字盤に色付きポリゴンを追加
    this->dial.addColoredPolygon(frame);
    // show the coordinates of the polygon for debug, 座標の表示。デバッグ用。
    frame.polygon.print();

    // ticks, 目盛
    // clear polygon data, ポリゴンデータの消去
    frame.polygon.clear(); 
    // tick of 0 o'clock, 12時の目盛
    frame.polygon.add_Point2D(  47, 6 );
    frame.polygon.add_Point2D(  47, 10 );
    frame.polygon.add_Point2D(  49, 10 );
    frame.polygon.add_Point2D(  49, 6 );
    // 追加
    this->dial.addColoredPolygon( frame );
    // Add ticks with rotating by 30 degree, 30度ずつ回転させながら、文字盤にメモリを追加
    for( int t = 1; t < 12; t++ ){
        frame.polygon.rotate_equal(30, center);
        this->dial.addColoredPolygon( frame );
    }

    // Draw the dial without the hands. 針のない文字盤を描画
    uint8_t np = this->dial.p.size();
    for( int p = 0; p < np; p++ ){
        canvas_with_dial.fill_polygon( this->dial.p[p] );
    }


}

void Drawer::draw_clock( Canvas_SSD1331 &canvas, int hour, int min, float second ){

    // Initialize the canvas by dial without the hands. 針のない文字盤でcanvasを初期化
    canvas = canvas_with_dial;

    // draw hands, 針の描画
    // compute angle of the hands, 角度の計算
    float deg_hour_hand   = hour * 30 + min * 0.5f + second / 120.0f;
    float deg_minute_hand = min * 6 + second * 0.1f;
    float deg_second_hand = second * 6.0f;
    Point2D center(48,32);
    // Compute polygones of the each hand by rotating the hands of 0 o'clock,  12時の針のポリゴンを回転させて、現在の針のポリゴンを取得
    Polygon2D h = hour_hand.rotate( deg_hour_hand, center );
    Polygon2D m = minute_hand.rotate( deg_minute_hand, center );
    Polygon2D s = second_hand.rotate( deg_second_hand, center );
    // draw the hands, 針の描画
    canvas.fill_polygon( h, const_cast<ColorRGB&>(color_hour_hand), 128); 
    canvas.fill_polygon( m, const_cast<ColorRGB&>(color_minute_hand), 128);
    canvas.fill_polygon( s, const_cast<ColorRGB&>(color_second_hand), 128);

}
