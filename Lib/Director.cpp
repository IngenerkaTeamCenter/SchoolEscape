#include "TXLib.h"
#include "consmenu.cpp"
#include "Bomzh.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct Point
{
    int x, y;
    int x1, y1;

    int x2, y2;
    int nomerPoint;
};

Point p[100];

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
    int radius;//область в которой директор тебя почуствует
    CrashZone crash;
    //int exit_time;
    int predX;
    int predY;
    int Stolknuls;
};

Director director[15];
int nomerDirector = 0;

void readDirector(ifstream* Map, string stroka_Personage, Director* director, int* nomerDirector, Point* p)
{
    string stroka_X = "";
    string stroka_Y = "";
    if (strcmp(stroka_Personage.c_str(), "director") == 0)
    {
        getline (*Map, stroka_X);
        director[*nomerDirector].x = atoi(stroka_X.c_str());
        getline (*Map, stroka_Y);
        director[*nomerDirector].y = atoi(stroka_X.c_str());
        getline (*Map, stroka_X);
        //stroka_X.c_str() - конвертация string в const char*
        //strlen - длина строки
        //substr(a, b)- часть строки начиная с №a длиной b символов (6 символов под p.x_=_)

        p[*nomerDirector].x = atoi(stroka_X.substr(6, strlen(stroka_X.c_str())-6).c_str());
        getline (*Map, stroka_X);
        p[*nomerDirector].y = atoi(stroka_X.substr(6, strlen(stroka_X.c_str())-6).c_str());
        getline (*Map, stroka_X);
        p[*nomerDirector].x1 = atoi(stroka_X.substr(7, strlen(stroka_X.c_str())-7).c_str());
        getline (*Map, stroka_X);
        p[*nomerDirector].y1 = atoi(stroka_X.substr(7, strlen(stroka_X.c_str())-7).c_str());

        *nomerDirector = *nomerDirector + 1;
    }
}

void initDirector(Director* d)
{
    d->speed = 1;
    d->width = 61;
    d->height = 96;
    d->PointStartX1 = 27;
    d->PointStartX2 = 24;
    d->PointStartY = 74;
    d->manyframeRight = 4;
    d->manyframeLeft = 4;
    d->manyframeUp = 4;
    d->manyframeDown = 4;
    directionFrameFrameTimer(&d->direction, &d->frame, &d->frameTimer);
    d->radius = 170;
}

void fillCrashZone(Director* d)
{
    d->crash.x1 = d->x - 27;
    d->crash.y1 = d->y - 12;
    d->crash.x2 = d->x + 27;
    d->crash.y2 = d->y + 12;
}

void catchCheck(Bomzh* b, Director d, bool R1)
{
    if((d.x - b->x) * (d.x - b->x) + (d.y - b->y) * (d.y - b->y) <= 75 && R1 == true)
    {
        b->life = b->life - 1;
    }
}


void moveDirector(Director *d, Point* p, bool R1)
{
    int predX = d->x;
    int predY = d->y;
    int maxCountOfFrames = 4;

    if((d->x - p->x2) * (d->x - p->x2) + (d->y - p->y2) * (d->y - p->y2) <= d->radius * d->radius && R1 == true)
    {
        p->nomerPoint = 2;
    }
    else if( abs(p->x - d->x) < 10 && abs(p->y - d->y) < 10)
    {
        p->nomerPoint = 1;
    }
    else if( abs(p->x1 - d->x) < 10 && abs(p->y1 - d->y) < 10)
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

    if(d->Stolknuls == 2)
    {
        d->y = d->y + d->speed;
        d->direction = DIRECTION_DOWN;
    }
    else if(d->y < y - d->speed && d->Stolknuls != 1)
    {
        d->y = d->y + d->speed;
        d->direction = DIRECTION_DOWN;
    }
    else if(d->y > y + d->speed && d->Stolknuls != 1){
        d->y = d->y - d->speed;
        d->direction = DIRECTION_UP;
    }

    if(d->Stolknuls == 1)
    {
        d->x = d->x - d->speed;
        d->direction = DIRECTION_LEFT;
    }
    else if(d->x < x - d->speed && d->Stolknuls != 2)
    {
        d->x = d->x + d->speed;
        d->direction = DIRECTION_RIGHT;
    } else if(d->x > x + d->speed && d->Stolknuls != 2){
        d->x = d->x - d->speed;
        d->direction = DIRECTION_LEFT;
    }

    if(GameMode == 1)
    {
        txArc (d->x - absolutX - d->radius, d->y - absolutY - d->radius,
               d->x - absolutX + d->radius, d->y - absolutY + d->radius, 0, 180);
        txArc (d->x - absolutX - d->radius, d->y - absolutY - d->radius,
               d->x - absolutX + d->radius, d->y - absolutY + d->radius, 180, 180);

        char str[100];
        sprintf(str, "%d", p->nomerPoint);
        txTextOut(d->x - absolutX, d->y + 100 - absolutY, str);

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
        txTransparentBlt(txDC(),  d.x - d.PointStartX1 - absolutX , d.y - d.PointStartY - absolutY, d.width, d.height, d.picDown, d.frame * 61, 0, RGB(255, 255, 255));
    }
    else if (d.direction == DIRECTION_UP)
    {
        txTransparentBlt(txDC(), d.x - d.PointStartX1 - absolutX, d.y - d.PointStartY - absolutY, d.width, d.height, d.picUp, d.frame * 61, 0, RGB(255, 255, 255));
    }
    else if (d.direction == DIRECTION_LEFT)
    {
        txTransparentBlt(txDC(), d.x - d.PointStartX2 - absolutX , d.y - d.PointStartY - absolutY, d.width - 6, d.height, d.picLeft, d.frame * 61, 0, RGB(255, 255, 255));
    }
    else if (d.direction == DIRECTION_RIGHT)
    {
        txTransparentBlt(txDC(), d.x - d.PointStartX2 - absolutX , d.y - d.PointStartY - absolutY, d.width - 6, d.height, d.picRight, d.frame * 61, 0, RGB(255, 255, 255));
    }


    if (d.Stolknuls > 0)
    {
        txTextOut(d.x - absolutX, d.y - 20 - absolutY, "I'm embarassed");
    }
}

