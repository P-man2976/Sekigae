#pragma once

extern unsigned int White;

extern unsigned int Skyblue;

extern unsigned int Darkblue;

extern unsigned int Red;

extern unsigned int Darkred;

extern unsigned int Black;

extern unsigned int Purple;

extern unsigned int Gray;

extern unsigned int Lightgray;

// White, Skyblue, Red, Black, Purple, Gray, Lightgrayの色をほかのファイルでも使えるようにする

extern int Focustitle;

extern int Notfocustitle;

extern int Toptitle;

extern int Focusfontsize;

extern int Notfocusfontsize;

extern int Titlegraph;

extern int Settingsgraph;

extern int Startgraph;

extern int Sekigaegraph;

//画像関係

extern int Titlescreen;

//画面関係

extern int Seatwidth;

extern int Seatheight;

//席替え関係

extern int Hideflag;

extern int Fadeflag;

extern int Count;

//その他もろもろ

void  DrawFrame(int x1, int y1, int x2, int y2, int color, int FillFlag, int Thickness);

int SekigaeMan(int Hideflag);

int SekigaeWoman(int Hideflag);

int SekigaeResult();

int Settingskari(int Hideflag);

int Settingsframe();

int Sekigaeprocess();

int Loaddata();

int Sekigae_man();

int Sekigae_woman();

//席替え関係

double InQuad(double change, double base, double duration, double time);

double OutQuad(double change, double base, double duration, double time);

double InOutQuad(double change, double base, double duration, double time);

//イージング関係

int FadeIn(int Minbright, int Maxbright, int Frame, int Time);

int FadeOut(int Minbright, int Maxbright, int Frame, int Time);

//エフェクト関係
