#include "TXLib.h"
#include "consmenu.cpp"
#include "Bomzh.cpp"
#include <iostream>
#include <string>




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

void CatchCheck(Bomzh b, Director d)
{
    if((d.x - b.x) * (d.x - b.x) + (d.y - b.y) * (d.y - b.y) <= 75)
        {
            txTextOut(0, 0, "game over");
            //cout << "ты облажался";
            exit(1);
            txDestroyWindow();
        }
}


void moveDirector(Director *d, Point* p)
{

    int predX = d->x;
    int predY = d->y;
    int maxCountOfFrames = 4;

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
        d->direction = DIRECTION_DOWN;
    }
    else if(d->y > y){
        d->y = d->y - d->speed;
        d->direction = DIRECTION_UP;
    }
    if(d->x < x)
    {
        d->x = d->x + d->speed;
        d->direction = DIRECTION_RIGHT;
    } else if(d->x > x){
        d->x = d->x - d->speed;
        d->direction = DIRECTION_LEFT;
    }

    if(GameMode == 1)
    {
        char str[100];
        sprintf(str, "%d", p->nomerPoint);
        txTextOut(400, 400, str);
    }

    if (predX != d->x || predY != d->y)
    {
        if (d->frame == 0)
        {
            d->frame = 1;
            d->frameTimer = 0;
        }
        else
        {
            d->frameTimer++;
            if (d->frameTimer >= 20)
            {
                d->frame++;
                if (d->frame >= maxCountOfFrames)
                    d->frame = 1;
                d->frameTimer = 0;
            }
        }
    }
}

void drawDirector(Director d)
{
    if (d.direction == DIRECTION_DOWN)
    {
        txTransparentBlt(txDC(),  d.x - d.PointStartX1 - abs_x , d.y - d.PointStartY, d.width, d.height, d.picDown, d.frame * 61, 0, RGB(255, 255, 255));
    }
    else if (d.direction == DIRECTION_UP)
    {
        txTransparentBlt(txDC(), d.x - d.PointStartX1 - abs_x , d.y - d.PointStartY , d.width, d.height, d.picUp, d.frame * 61, 0, RGB(255, 255, 255));
    }
    else if (d.direction == DIRECTION_LEFT)
    {
        txTransparentBlt(txDC(), d.x - d.PointStartX2 - abs_x , d.y - d.PointStartY, d.width - 6, d.height, d.picLeft, d.frame * 61, 0, RGB(255, 255, 255));
    }
    else if (d.direction == DIRECTION_RIGHT)
    {
        txTransparentBlt(txDC(), d.x - d.PointStartX2 - abs_x , d.y - d.PointStartY , d.width - 6, d.height, d.picRight, d.frame * 61, 0, RGB(255, 255, 255));
    }
}
