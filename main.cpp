#include "TXLib.h"


struct Point
{
    int x, y;
    int x1, y1;
    int x2, y2;
    int nomerPoint;
    //int kolvoPoint;
    //int amount;/*количество монет*/
};


struct Director
{
    int x, y;
    int speed;
    int manyframeUp;
    int manyframeDown;
    int manyframeLeft;
    int manyframeRight;
    int width;
    int height;
    int PointStartX1;
    int PointStartX2;
    int PointStartY;
    int direction; // 0 Down   1  Up   2 Left    3 Right
    HDC picDown;
    HDC picUp;
    HDC picLeft;
    HDC picRight;
    int frame;
    int frameTimer;
    //int exit_time;
};

/*void drawBomzh(Director d)
{
if (d.direction == 0)
{
txTransparentBlt(txDC(), d.x, d.y, d.width, d.height, d.picDown, d.frame * 54, 0, RGB(255, 255, 255));
}

if (d.direction == 1)
{
txTransparentBlt(txDC(), d.x, d.y, d.width, d.height, d.picUp, d.frame * 54, 0, RGB(255, 255, 255));
}

if (d.direction == 2)
{
txTransparentBlt(txDC(), d.x, d.y, d.width - 6, d.height, d.picLeft, d.frame * 48, 0, RGB(255, 255, 255));
}
if (d.direction == 3)
{
txTransparentBlt(txDC(), d.x, d.y, d.width - 6, d.height, d.picRight, d.frame * 48, 0, RGB(255, 255, 255));
}
}*/



void moveDirector(Director *d, Point *p)
{
    if((d->x - p->x2) * (d->x - p->x2) + (d->y - p->y2) * (d->y - p->y2) <= 50 * 50)
    {
        p->nomerPoint = 2;
    }
    else if(p->x == d->x && p->y == d->y)
    {
        p->nomerPoint = 1;
    }
    else if(p->x1 == d->x && p->y1 == d->y)
    {
        p->nomerPoint = 0;
    }

    int x, y;
    if (p->nomerPoint == 0)
    {
        x = p->x;
        y = p->y;
    }
    else if(p->nomerPoint == 1)
    {
        x = p->x1;
        y = p->y1;
    }
    else if(p->nomerPoint == 2)
    {
        x = p->x2;
        y = p->y2;
    }

    if(d->y < y)
    {
        d->y = d->y + d->speed;
        d->direction = 0;
    }
    else if(d->y > y){
        d->y = d->y - d->speed;
        d->direction = 1;
    }
    else if(d->x < x)
    {
        d->x = d->x + d->speed;
        d->direction = 3;
    } else if(d->x > x){
        d->x = d->x - d->speed;
        d->direction = 2;
    }
}

void drawDirector(Director d)
{
 if (d.direction == 0)
{
txTransparentBlt(txDC(),  d.x - d.PointStartX1 , d.y - d.PointStartY, d.width, d.height, d.picDown, d.frame * 54, 0, RGB(255, 255, 255));
}

if (d.direction == 1)
{
txTransparentBlt(txDC(), d.x - d.PointStartX1 , d.y - d.PointStartY , d.width, d.height, d.picUp, d.frame * 54, 0, RGB(255, 255, 255));
}

if (d.direction == 2)
{
txTransparentBlt(txDC(), d.x - d.PointStartX2 , d.y - d.PointStartY, d.width - 6, d.height, d.picLeft, d.frame * 48, 0, RGB(255, 255, 255));
}
if (d.direction == 3)
{
txTransparentBlt(txDC(), d.x - d.PointStartX2 , d.y - d.PointStartY , d.width - 6, d.height, d.picRight, d.frame * 48, 0, RGB(255, 255, 255));
}
}

 int main()
 {
     txCreateWindow (1090, 654);
     txBegin();

     Director d;
     d.x = 300;
     d.y = 200;
     d.speed = 10;
     d.width = 54;
     d.height = 86;
     d.speed = 2;
     d.manyframeRight = 3;
     d.manyframeLeft = 3;
     d.PointStartX1 = 27;
     d.PointStartX2 = 24;
     d.PointStartY = 74;
     d.manyframeUp = 5;
     d.manyframeDown = 5;
     d.direction = 0;
     d.frame = 0;
     d.frameTimer = 0;
     d.picDown = txLoadImage ("IMG\\Men\\Homeless\\HomelessDown.bmp");
     d.picUp = txLoadImage ("IMG\\Men\\Homeless\\HomelessUp.bmp");
     d.picLeft = txLoadImage ("IMG\\Men\\Homeless\\HomelessLeft.bmp");
     d.picRight = txLoadImage ("IMG\\Men\\Homeless\\HomelessRight.bmp");
     //d.exit_time = 100000;

    Point p;
    p.x = 100;
    p.y = 100;
    p.x1 = 200;
    p.y1 = 100;
    p.x2 = 150;
    p.y2 = 150;
    p.nomerPoint = 0;


    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txClear();

        txSetColor(TX_RED, 3);
        txCircle(p.x, p.y, 5);
        txCircle(p.x1, p.y1, 5);
        txCircle(p.x2, p.y2, 5);

        //printf("%d", p.nomerPoint);

        drawDirector(d);
        moveDirector(&d, &p);

        txSleep(10);
    }


 }
