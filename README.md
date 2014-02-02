# CBmpViewer
## とは
コンソール上でBMP画像を(無理矢理)表示するプログラム。
とりあえず作ったものなのでごくわずかのフォーマットにしか対応していない。  
具体的には、Windows Bitmapの無圧縮24ビットで画像データがボトムアップで保存されているビットマップのみ対応。  
コンソールでのエスケープシーケンスでの色表示するのは完全に機種依存だからうまく表示されるかは保証しない。  
.... をforkして拡張背景色^[[38;5;を指定するように変更
もちろん使用色は256色になって画素密度は小さくなるので粗い画像(のようなもの)になる。

## コンパイル・インストール・使い方
    $ make  
    $ make install  
    $ cbmpviewer <input.bmp>
make installは別にしなくてもいい。
実行方法は第1引数にBMP画像のファイル名を入力する。  

## デモ
元画像 ikamusume_sq.bmp (のjpg画像)  
![元画像](https://raw.github.com/kotarot/CBmpViewer/master/ikamusume_sq.jpg)  
    $ cbmpviewer ikamusume_sq.bmp
を実行すると、  
![出力結果](https://raw.github.com/katakk/CBmpViewer/master/Screenshot256.png)  
こんな感じ。  

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

