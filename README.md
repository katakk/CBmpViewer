# cimage-viewer [![Build Status](https://travis-ci.org/katakk/CBmpViewer.svg?branch=master)](https://travis-ci.org/katakk/CBmpViewer) [![codecov.io](https://codecov.io/github/katakk/CBmpViewer/coverage.svg?branch=master)](https://codecov.io/github/katakk/CBmpViewer?branch=master) [![coverity](https://scan.coverity.com/projects/11484/badge.svg)](https://scan.coverity.com/projects/katakk-cbmpviewer)

cimage-viewer (しめじビューワー) はコンソール上で BMP 画像を (無理矢理) 表示するプログラム。
とりあえず作ったものなのでごくわずかのフォーマットにしか対応していない。
具体的には、Windows Bitmap の無圧縮24ビットで画像データがボトムアップで保存されているビットマップのみ対応。
コンソールでのエスケープシーケンスでの色表示するのは完全に機種依存だからうまく表示されるかは保証しない。
もちろん使用色は 256 色になって画素密度は小さくなるので粗い画像 (のようなもの) になる。
今後、ビットマップ以外の画像 (JPEG、PNG 等) も対応予定である。


## コンパイル・インストール・使い方

```
$ make
$ make install
$ cbmpviewer <input.bmp> [threshold_r=128 threshold_g=128 threshold_b=128]
```

make install は別にしなくてもいい。
実行方法は第 1 引数に BMP 画像のファイル名を入力する。
第 2, 3, 4 引数には RGB 各値の 2 値化のときのしきい値を 0~255 の間で入力できる。省いたときのデフォルト値は 128。

```
$ TERM=xterm COLUMNS=120 ./cbmpviewer ikamusume_sq.bmp | tee ikamusume_sq.txt
```

透過画像として表示するにはTRANSPARENT=1 を指定してください。　透過には　x=0, y=0 の座標の色を透過色とします。SNEG

```
$ TERM=xterm COLUMNS=300 TRIML=40 TRIMR=30 HEAD=270 TRANSPARENT=1 ./cbmpviewer ../風町陽歌（立ち絵）.bmp
```

パイプも使用可能。  
環境変数 COLUMNS にて横幅設定　デフォルトで 80  
環境変数 TERM が xterm なのは 256 色にするため必須　大抵の場合は xterm になっている  

## 環境変数
- COLUMNS 横幅設定 デフォルト 80  
- t_Co 色数強制指定 8 256 16777216 デフォルト指定なし
- TRIML 左トリム桁数 デフォルト 0
- TRIMR 右トリム桁数 デフォルト 0
- HEAD 上表示行数   デフォルト MAX
- TRANSPARENT=1 透過処理有効  デフォルト 無効
- NORLE=1 RLE無効化   デフォルト RLE有効

ffmpeg が入っている環境下であれば下記が可能:

```
$ bmp ikamusume_sq.jpg
```

端末でとりあえず画像確認できます、teratermで内容の確認がさくさくできます。

```
$ play "ストライク・ザ・ブラッド　#16.mp4"
```

動画もサムネイル確認程度ならできるようです (動画は添付されません)。

```
$ cd /home/foltia/php/tv/4441.localized/mp4
$ play MHD-4441-2-20170118-0135-27.MP4
```

すごーい。君はそこまでしてアニメ見たいフレンズなんだね。たーのしー。

## デモ
元画像 ikamusume_sq.bmp (のjpg画像)  
![元画像](https://raw.github.com/kotarot/cimage-viewer/master/ikamusume_sq.jpg)  

```
$ TERM=vt100 cbmpviewer ikamusume_sq.bmp 150 160 160
```

を実行すると、  
![出力結果](https://raw.github.com/kotarot/cimage-viewer/master/Screenshot.png)  
こんな感じ。

```
$ TERM=xterm cbmpviewer ikamusume_sq.bmp
```

を実行すると、  
![出力結果](https://raw.github.com/katakk/CBmpViewer/master/Screenshot256.png)  
こんな感じ。

## メモ
Teraterm 4.76 以降では SGR 38:2;r:g:b が使えるが現在の所 256 色表示なので効果なし。
SGR 38;5;col は Teraterm 4.8.0, xterm 271, Xfce terminal 0.4.8 で使用できることを確認。

## 参考サイト
* bmp ファイルフォーマット - Kondo, Masayoshi WebPage  
http://www.kk.iij4u.or.jp/~kondo/bmp/

* 第6章 C言語による実践プログラミング - Armadillo実践開発ガイド  
http://manual.atmark-techno.com/armadillo-guide/armadillo-guide-2_ja-1.0.0/ch06.html

* もう一度基礎からC言語 第47回 特殊な画面制御～コンソール入出力関数とエスケープシーケンス エスケープシーケンスによる画面制御  
http://www.grapecity.com/tools/support/powernews/column/clang/047/page02.htm

* シェル - echoで文字に色をつける その1 - Miuran Business Systems  
http://www.m-bsys.com/linux/echo-color-1

* 端末ウィンドウサイズの取得 - 自問自答  
http://d.hatena.ne.jp/iostream/20100219/1266566970

* 文字属性 (SGR)  
http://ttssh2.sourceforge.jp/manual/ja/about/ctrlseq.html#charattr
