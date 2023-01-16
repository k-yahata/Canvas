# Canvasクラス
アンチエイリアス付き2Dベクトル描画(ポリゴンの描画)のためのクラスです。

ESP32などのメモリの豊富な高性能マイコン向けを想定しています。

アンチエイリアス実現のため、メンバー変数としてフレームメモリを確保します。

ディスプレイのドライバは含まれていないので、フレームメモリをディスプレイに転送するソフトが別に必要です。
(Ardino IDE x ESP32 x SSD1331の場合は、別途リポジトリを公開しています)

# 使い方
## クラスの定義
Canvasクラスは描画関数などを実装したテンプレートかつスーパークラスです。
お使いのディスプレイがRGB16bit(RGB565)やモノクロ8bitであれば、Canvas_RGB565クラスやCanvas_Gray8クラスの
テンプレートパラメターを指定するだけで使えるかもしれません。
```
class Canvas_SSD1331 : public Canvas_RGB565<96,64>{}; // 96 x 64 ピクセル, RGB565のcanvasクラスを定義
class Canvas_SSD1306 : public Canvas_Gray8<128,64>{}; // 128 x 64 ピクセル, モノクロのcanvasクラスを定義
```
もしディスプレイのデータフォーマットが合わない場合は、Canvasクラスから派生させる必要があります。派生時は以下の３つの仮想関数のオーバーライドが必要です。
```
    // ColorRGBはテンプレートで指定
    inline void get_Color( uint8_t *p_data, ColorRGB &color ) const;    // データ配列からRGBの画素値を取得
    inline void set_Color( uint8_t *p_data, ColorRGB &color ) override; // RGBの画素値からデータ配列に変換
    void Color_to_RGB888( ColorRGB &color,  uint8_t &r8, uint8_t &g8, uint8_t &b8 ) const override; // RGBの画素値を8bitに変換(BMPに保存するため)
```
## 演算精度
ESP32-C3などFPUの無いマイコンについては、resolution.hppでdefine文をコメントアウトすることで、
演算の重いところで極力浮動小数点数演算を使わない実装になります。

## 描画
Polygon2D型、もしくはColoredPolygon型のインスタンスで
ポリゴンを定義して、Canvasのサブクラスのインスタンスから、
fill_polygon関数などを呼び出して描画します。
```
Canvas_SSD1331 canvas;          // Canvasクラス
Polygon2D polygon;              // ポリゴン
Color_RGB565 color(0,63,31);    // 色, 
uint8_t alpha = 0;              // 透明度[0-128], 0:透明, 128:透明
polygon.add_Point2D( 10, 10 );
polygon.add_Point2D( 10, 30 );
polygon.add_Point2D( 30, 30 );
canvas.fill_polygon( polygon, color, alpha );
```
[時計のサンプル](sample)もあります。

## 定義済み描画関数
Canvas.hpp抜粋
```
    //---------------------
    // Drawing functions
    //---------------------
    public:
    // Set all pixel values to val
    void clear( uint8_t val = 0U );

    // Draw filled polygon, no edge / ポリゴンを塗りつぶす。ポリゴンは自動で閉じる。
    void fill_polygon( Polygon2D &polygon, Color &color, const uint8_t alpha = 0U);

    // Draw a segment, from p0 to p1 
    void draw_line( const Point2D p0, const Point2D p1, const float weight, Color &color, const uint8_t alpha = 0U);

    // Fill the pixel including the point p0
    void draw_dot( Point2D p0, Color &color, const uint8_t alpha = 0U);

    // Draw edges of polygon. The polygon is automatically closed.
    // If weight is larger than 2.0f, the draw_polygon_HQ(..) is recommended.
    // ポリゴンの辺を描画する。閉じる。高速簡易実装のため、線が太い場合はdraw_polygon_HQの方がおすすめ
    void draw_polygon( Polygon2D &polygon, const float weight, Color &color, const uint8_t alpha = 0U);

    // Draw edges of polygon. The polygon is automatically closed.
    // Because this function internaly create a new polygon representing the edges, it is relatively slow.
    // If edges are crossing, the crossing area may not be filled. 
    // ポリゴンの辺を描画する。閉じる。低速だが高品質。ただし、辺が交差したところは塗られない仕様
    void draw_polygon_HQ( Polygon2D &polygon, const float weight, Color &color, const uint8_t alpha = 0U);
```    
以下、書きかけ


