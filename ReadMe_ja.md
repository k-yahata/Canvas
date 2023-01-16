# Canvasクラス
アンチエイリアス付き2Dベクトル描画(ポリゴンの描画)のためのクラスです。

ESP32などのメモリの豊富な高性能マイコン向けを想定しています。

アンチエイリアス実現のため、メンバー変数としてフレームメモリを確保します。

ディスプレイのドライバは含まれていないので、フレームメモリをディスプレイに転送するソフトが別に必要です。
(Ardino IDE x ESP32 x SSD1331の場合は、別途リポジトリを公開しています)

# 使い方
Canvasクラスは描画関数などを実装したテンプレートクラスで、画像サイズや1画素あたりのバイト数、色クラス型がテンプレートパラメターなので、これを指定して使います。


8bitモノクロ画像やRGB16bit画像などは、定義済みのCanvas_Gray8やCanvas_RGB565などから画素数を指定できます。

sampleディレクトリにアナログ時計を描画する例があります。

ESP32-C3などFPUの無いマイコンについては、resolution.hppでdefine文をコメントアウトすることで、
演算の重いところで極力浮動小数点数演算を使わない実装になります。

# 描画関数
Polygon2D型、もしくはColoredPolygon型のインスタンスで
ポリゴンを定義して、Canvasのサブクラスのインスタンスから、
fillPolygon関数などを呼び出して描画します。
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
以下、書きかけ


