/*
 * LineBressenham.cpp
 *
 * -------------------------------------
 * Draw Line with Bressenham's Algorithm
 * -------------------------------------
 *
 * Copyright 2014 Imancha <imancha_266@ymail.com>
 *
 */

#include <iostream>
#include <cmath>
#include <graphics.h>

using namespace std;

//	|m| < 1
void LineBressenhamKurang(int xa, int xb, int ya, int yb){
	int dx = abs(xb - xa);
	int dy = abs(yb - ya);
	int twoDx = 2 * (dy - dx);
	int twoDy = 2 * dy;
	int p = 2 * dy - dx;
	int x, y, xEnd, i = 0;

	if(xa > xb){
		x = xb;
		y = yb;
		xEnd = xa;
	}else{
		x = xa;
		y = ya;
		xEnd = xb;
	}

	cout << "\n i \tP \t(x,y) \n----------------------";

	putpixel(x, getmaxy()-y, CYAN);

	while(x < xEnd){
		x++;

		cout << "\n " << i++ << "\t" << p << "\t";

		if(p < 0){
			p += twoDy;
		}else{
			y++;
			p += twoDx;
		}

		cout << "(" << x << "," << y << ")";
		putpixel(x, getmaxy()-y, CYAN);
		delay(20);
	}

	cout << "\n";
}

//	|m| >= 1
void LineBressenhamLebih(int xa, int xb, int ya, int yb){
	int dx = abs(xb - xa);
	int dy = abs(yb - ya);
	int twoDx = 2 * dx;
	int twoDy = 2 * (dx - dy);
	int p = 2 * dx - dy;
	int x, y, yEnd, i = 0;

	if(ya > yb){
		x = xb;
		y = yb;
		yEnd = ya;
	}else{
		x = xa;
		y = ya;
		yEnd = yb;
	}

	cout << "\n i \tP \t(x,y) \n ----------------------";

	putpixel(x, getmaxy()-y, YELLOW);

	while(y < yEnd){
		y++;

		cout << "\n " << i++ << "\t" << p << "\t";

		if(p < 0){
			p += twoDx;
		}else{
			x++;
			p += twoDy;
		}

		cout << "(" << x << "," << y << ")";
		putpixel(x, getmaxy()-y, YELLOW);
		delay(20);
	}
	cout << "\n";
}

int main(int argc, char **argv)
{
	int xa, ya, xb, yb = 0;

	printf("Koordinat awal  X Y : "); scanf("%d %d", &xa, &ya);
	printf("Koordinat akhir X Y : "); scanf("%d %d", &xb, &yb);

	int m = abs((yb-ya) / (xb-xa));

	int gd = DETECT;
	int gm = getmaxmode();

	initgraph(&gd, &gm, NULL);

	if(m < 1)
		LineBressenhamKurang(xa, xb, ya, yb);
	else
		LineBressenhamLebih(xa, xb, ya, yb);

	getchar();
	closegraph();

	return 0;
}
