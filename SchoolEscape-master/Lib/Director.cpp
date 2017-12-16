#include "TXLib.h"


struct Point
{
    int x, y;
    int x1, y1;
    int x2, y2;
    int nomerPoint;
    //int kolvoPoint;
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
    int radius;//נאהטףס מבחמנא
    //int exit_time;
};


void moveDirector(Director *d, Point *p)
{
    if((d->x - p->x2) * (d->x - p->x2) + (d->y - p->y2) * (d->y - p->y2) <= d->radius * d->radius)
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
    else if ((d->x - p->x2) * (d->x - p->x2) + (d->y - p->y2) * (d->y - p->y2) > d->radius * d->radius && p->nomerPoint == 2)
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
    if(d->x < x)
    {
        d->x = d->x + d->speed;
        d->direction = 3;
    } else if(d->x > x){
        d->x = d->x - d->speed;
        d->direction = 2;
    }

    if (p->nomerPoint == 0)
        txTextOut(400, 400, "0");
    if (p->nomerPoint == 1)
        txTextOut(400, 400, "1");
    if (p->nomerPoint == 2)
        txTextOut(400, 400, "2");
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
