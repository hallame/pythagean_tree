#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "graphics.h"

void Pif_Tree(int n, int x0, int y0, int a, double angle, double alp) { 
   if (n==0) 
       return;
   int x1 = x0 + a; 
   int y1 = y0;
   int x2 = x0 + a;
   int y2 = y0 + a;
   int x3 = x0;
   int y3 = y0+a;
   int str_cos = a * cos(alp);
   int str_sin = a * sin(alp);  
   int x4 = x3 + str_cos * cos(alp);
   int y4 = y3 + str_cos * sin(alp);
   
   int tckX = x1; 
   x1 =  x0 + (x1 - x0) * cos(angle) - (y1 - y0) * sin(angle);
   y1 =  y0 + (y1 - y0) * cos(angle) + (tckX - x0) * sin(angle);
   tckX = x2;
   x2 =  x0 + (x2 - x0) * cos(angle) - (y2 - y0) * sin(angle);  
   y2 =  y0 + (y2 - y0) * cos(angle) + (tckX - x0) * sin(angle);
   tckX = x3;
   x3 =  x0 + (x3 - x0) * cos(angle) - (y3 - y0) * sin(angle);  
   y3 =  y0 + (y3 - y0) * cos(angle) + (tckX - x0) * sin(angle);
   tckX = x4;
   x4 =  x0 + (x4 - x0) * cos(angle) - (y4 - y0) * sin(angle); 
   y4 =  y0 + (y4 - y0) * cos(angle) + (tckX - x0) * sin(angle);
   
   line(x0,y0,x1,y1); 
   line(x1,y1,x2,y2);
   line(x2,y2,x3,y3);
   line(x3,y3,x0,y0); 
   Pif_Tree(n - 1, x4, y4, str_sin, angle + alp - 0.5 * M_PI,  alp);
   Pif_Tree(n - 1, x3, y3, str_cos, angle + alp, alp);
}  
int main() {
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "");
  
   Pif_Tree(1 0, 600, 650, 120, 60, 65  * M_PI / 180);
   getch();
   closegraph();
   return 0;
} 
