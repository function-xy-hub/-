#ifndef	_BEPAGE_H_
#define	_BEPAGE_H_

void waveX(int x0, int y0, int x1, int color);
void WaveY(int x0, int y0, int y1, int n, int color);

void waveY(int x0, int y0, int y1, int color);
void WaveX(int x0, int y0, int x1, int n, int color)  ;

void parall(int x1,int y1,int longth,int high,int color);

void parall1(int x1, int y1, int longth, int high, int color);

void isosceles_trapezoid(int x1, int y1, int length, int height, int color);

void  ladder(int x1, int y1, int length, int height, int color);

void  ladder1(int x1, int y1, int length, int height, int color);

void bkcolor(int color);
int beginpage();
void back_key();

 #endif
