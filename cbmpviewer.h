/**
 * cbmpviewer.h
 */

#ifndef __CBMPVIEWER_H__
#define __CBMPVIEWER_H__

#include <stdint.h>

// 構造体定義
// ファイルヘッダ
typedef struct TAG_BITMAPFILEHEADER {
    uint16_t type;      // ファイルタイプ'BM'
    uint32_t size;      // ファイルサイズ(byte)
    uint16_t reserved1; // 予約(常に0)
    uint16_t reserved2; // 予約(常に0)
    uint32_t offbits;   // ファイル先頭から画像データまでのオフセット(byte)
} bmpfileheader_t;

// 情報ヘッダ(Windows bitmap)
typedef struct TAG_BITMAPINFOHEADER {
    uint32_t size;         // 情報ヘッダのサイズ(40byte)
    int32_t  width;        // 画像の幅
    int32_t  height;       // 画像の高さ
    uint16_t planes;       // プレーン数(常に1)
    uint16_t bitcount;     // 1pixelあたりのデータサイズ(bit)
    uint32_t compression;  // 圧縮形式
    uint32_t sizeimage;    // 画像データ部のサイズ(byte)
    int32_t  xpixpermeter; // X方向解像度
    int32_t  ypixpermeter; // Y方向解像度
    uint32_t clrused;      // パレット数
    uint32_t clrimporant;  // 重要なパレットのインデックス
} bmpinfoheader_t;

// Pixel構造体
typedef struct TAG_PIXEL {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel_t;

// ConsoleBMP構造体
typedef struct TAG_CONSOLEBMP {
    uint32_t bpl_c;  // コンソール文字に対するbmpのピクセル比率 col
    uint32_t bpl_r;  // コンソール文字に対するbmpのピクセル比率 row
    uint32_t letter; // コンソール出力の1行の文字数
    uint32_t line;   // コンソール出力の1行の行数
    uint8_t threshold_r; // しきい値
    uint8_t threshold_g;
    uint8_t threshold_b;
} consolebmp_t;

// 関数プロトタイプ宣言
// Usage
void usage(void);
// Viewプロシージャ ファイル名としきい値を受け取る
void viewproc(char *filename, uint8_t threshold_r, uint8_t threshold_g, uint8_t threshold_b);
// 画像ヘッダ取得
void getbmpheader(FILE *fp, bmpfileheader_t *fh, bmpinfoheader_t *ih);
// ファイルポインタから指定のバイト取得(エラー処理付き)
void freadwitherror(void *buf, int byte, FILE *fp);
// 画像ヘッダの(このプログラムで対応する)フォーマットチェック
void checkbmpheader(bmpfileheader_t *fh, bmpinfoheader_t *ih);
// 画像ヘッダの表示
void showbmpheader(bmpfileheader_t *fh, bmpinfoheader_t *ih);
// 画像データをメモリに読み込む
void readbmpdata(FILE *fp, pixel_t **pix, int32_t width, int32_t height);
// 画像データの表示
void showbmpdata(pixel_t **pix, int32_t width, int32_t height);
// 色変換と出力
void outputbmp(pixel_t **pix, consolebmp_t *cbmp);

// 拡張パレット - RBGの変換テーブル
pixel_t pal2rgb[256] = {
    {0,0,0},      {192,0,0},    {0,192,0},    {192,192,0},  
    {64,64,192},  {192,0,192},  {0,192,192},  {192,192,192},
    {64,64,64},   {255,0,0},    {0,255,0},    {255,255,0},  
    {128,128,255},{255,0,255},  {0,255,255},  {255,255,255},
    {0,0,0},      {0,0,95},     {0,0,135},    {0,0,175},    
    {0,0,215},    {0,0,255},    {0,95,0},     {0,95,95},    
    {0,95,135},   {0,95,175},   {0,95,215},   {0,95,255},   
    {0,135,0},    {0,135,95},   {0,135,135},  {0,135,175},  
    {0,135,215},  {0,135,255},  {0,175,0},    {0,175,95},   
    {0,175,135},  {0,175,175},  {0,175,215},  {0,175,255},  
    {0,215,0},    {0,215,95},   {0,215,135},  {0,215,175},  
    {0,215,215},  {0,215,255},  {0,255,0},    {0,255,95},   
    {0,255,135},  {0,255,175},  {0,255,215},  {0,255,255},  
    {95,0,0},     {95,0,95},    {95,0,135},   {95,0,175},   
    {95,0,215},   {95,0,255},   {95,95,0},    {95,95,95},   
    {95,95,135},  {95,95,175},  {95,95,215},  {95,95,255},  
    {95,135,0},   {95,135,95},  {95,135,135}, {95,135,175}, 
    {95,135,215}, {95,135,255}, {95,175,0},   {95,175,95},  
    {95,175,135}, {95,175,175}, {95,175,215}, {95,175,255}, 
    {95,215,0},   {95,215,95},  {95,215,135}, {95,215,175}, 
    {95,215,215}, {95,215,255}, {95,255,0},   {95,255,95},  
    {95,255,135}, {95,255,175}, {95,255,215}, {95,255,255}, 
    {135,0,0},    {135,0,95},   {135,0,135},  {135,0,175},  
    {135,0,215},  {135,0,255},  {135,95,0},   {135,95,95},  
    {135,95,135}, {135,95,175}, {135,95,215}, {135,95,255}, 
    {135,135,0},  {135,135,95}, {135,135,135},{135,135,175},
    {135,135,215},{135,135,255},{135,175,0},  {135,175,95}, 
    {135,175,135},{135,175,175},{135,175,215},{135,175,255},
    {135,215,0},  {135,215,95}, {135,215,135},{135,215,175},
    {135,215,215},{135,215,255},{135,255,0},  {135,255,95}, 
    {135,255,135},{135,255,175},{135,255,215},{135,255,255},
    {175,0,0},    {175,0,95},   {175,0,135},  {175,0,175},  
    {175,0,215},  {175,0,255},  {175,95,0},   {175,95,95},  
    {175,95,135}, {175,95,175}, {175,95,215}, {175,95,255}, 
    {175,135,0},  {175,135,95}, {175,135,135},{175,135,175},
    {175,135,215},{175,135,255},{175,175,0},  {175,175,95}, 
    {175,175,135},{175,175,175},{175,175,215},{175,175,255},
    {175,215,0},  {175,215,95}, {175,215,135},{175,215,175},
    {175,215,215},{175,215,255},{175,255,0},  {175,255,95}, 
    {175,255,135},{175,255,175},{175,255,215},{175,255,255},
    {215,0,0},    {215,0,95},   {215,0,135},  {215,0,175},  
    {215,0,215},  {215,0,255},  {215,95,0},   {215,95,95},  
    {215,95,135}, {215,95,175}, {215,95,215}, {215,95,255}, 
    {215,135,0},  {215,135,95}, {215,135,135},{215,135,175},
    {215,135,215},{215,135,255},{215,175,0},  {215,175,95}, 
    {215,175,135},{215,175,175},{215,175,215},{215,175,255},
    {215,215,0},  {215,215,95}, {215,215,135},{215,215,175},
    {215,215,215},{215,215,255},{215,255,0},  {215,255,95}, 
    {215,255,135},{215,255,175},{215,255,215},{215,255,255},
    {255,0,0},    {255,0,95},   {255,0,135},  {255,0,175},  
    {255,0,215},  {255,0,255},  {255,95,0},   {255,95,95},  
    {255,95,135}, {255,95,175}, {255,95,215}, {255,95,255}, 
    {255,135,0},  {255,135,95}, {255,135,135},{255,135,175},
    {255,135,215},{255,135,255},{255,175,0},  {255,175,95}, 
    {255,175,135},{255,175,175},{255,175,215},{255,175,255},
    {255,215,0},  {255,215,95}, {255,215,135},{255,215,175},
    {255,215,215},{255,215,255},{255,255,0},  {255,255,95}, 
    {255,255,135},{255,255,175},{255,255,215},{255,255,255},
    {8,8,8},      {18,18,18},   {28,28,28},   {38,38,38},   
    {48,48,48},   {58,58,58},   {68,68,68},   {78,78,78},   
    {88,88,88},   {98,98,98},   {108,108,108},{118,118,118},
    {128,128,128},{138,138,138},{148,148,148},{158,158,158},
    {168,168,168},{178,178,178},{188,188,188},{198,198,198},
    {208,208,208},{218,218,218},{228,228,228},{238,238,238},
};

// 初期化
static uint16_t sqrtable[195076] = {0}; // 255x255 + 255x255 + 255x255 => 195075

static inline
void init_sqrt() {
    int i;
    for(i = 0; i < 195076; i++) sqrtable[i] = sqrt(i);
}

// 三次空間から距離を得る
static inline
uint32_t distance(uint32_t r0, uint32_t g0, uint32_t b0,
                  uint32_t r1, uint32_t g1, uint32_t b1) {
    uint32_t r, g, b;
    r = abs(r0 - r1) ;
    g = abs(g0 - g1) ;
    b = abs(b0 - b1) ;
    return sqrtable[r * r + g * g + b * b];
}

// RGB から 拡張カラーへの近似色を探す
static inline
uint8_t near(uint32_t r0, uint32_t g0, uint32_t b0) {
    uint32_t dmin = (uint32_t)1000 ;// > 441.672
    uint32_t d[256] = {0};
    uint32_t i;
    for (i = 0; i < 256; i++) {
        d[i] = distance( r0,g0,b0,
        pal2rgb[i].red,
        pal2rgb[i].green,
        pal2rgb[i].blue);
        if(dmin > d[i]) dmin = d[i];
    }
    for (i = 0; i < 256; i++) {
        if(d[i] == dmin) return i;
    }
    return 255;
}


#endif

