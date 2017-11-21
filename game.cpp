#include "Lib\\TXLib.h"
#include "Lib\\Bomzh.cpp"

 void scene1(Bomzh b/*, Director d*/)
 {
     while (!GetAsyncKeyState(VK_ESCAPE))
     {
         txSetFillColor(TX_BLACK);
         txRectangle(0, 0, 1200, 900);
         moveBomzh(&b);
         drawBomzh(b);
         //moveDirector(&d);
         //drawDirector(d);
         txSleep(10);
     }
 }

 int main()
 {
     txCreateWindow (1090, 654);
     txBegin();

     //Director d;
     //d.x = 50;
     //...
     //d.picRight = ...

     Bomzh b;
     b.x = 400;
     b.y = 300;
     b.width = 54;
     b.height = 86;
     b.speed = 2;
     b.manyframeRight = 3;
     b.manyframeLeft = 3;
     b.PointStartX1 = 27;
     b.PointStartX2 = 24;
     b.PointStartY = 74;
     b.manyframeUp = 5;
     b.manyframeDown = 5;
     b.direction = 0;
     b.frame = 0;
     b.frameTimer = 0;
     b.picDown = txLoadImage("IMG\\Men\\Homeless\\HomelessDown.bmp");
     b.picUp = txLoadImage("IMG\\Men\\Homeless\\HomelessUp.bmp");
     b.picLeft = txLoadImage("IMG\\Men\\Homeless\\HomelessLeft.bmp");
     b.picRight = txLoadImage("IMG\\Men\\Homeless\\HomelessRight.bmp");

     scene1(b/*, d*/);
     txDeleteDC(b.picDown);
     txDeleteDC(b.picUp);
     txDeleteDC(b.picLeft);
     txDeleteDC(b.picRight);
 }
