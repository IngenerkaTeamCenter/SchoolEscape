#include "TXLib.h"
#include "consmenu.cpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Robot
{
    int x, y;
    int manyframeUp;
    int manyframeDown;
    int manyframeLeft;
    int manyframeRight;
    int speed;
    int width;
    int height;
    int direction; // 0 Down   1  Up   2 Left    3 Right
    HDC picDown;
    HDC picUp;
    HDC picLeft;
    HDC picRight;
    int frame;
    int frameTimer;
};

Robot robots[100];
int nomerRobota = 0;

void drawRobot(Robot r, int nomerRobota)
{

    if (r.direction == DIRECTION_DOWN)
    {
        txTransparentBlt(txDC(), r.x - r.width/2, r.y - r.height/2, r.width, r.height, r.picDown, r.frame * 45, 0, RGB(255, 255, 255));
    }
    else if (r.direction == DIRECTION_UP)
    {
        txTransparentBlt(txDC(), r.x - r.width/2, r.y - r.height/2, r.width, r.height, r.picUp, r.frame * 47, 0, RGB(255, 255, 255));
    }
    else if (r.direction == DIRECTION_LEFT)
    {
        txTransparentBlt(txDC(), r.x - r.width/2, r.y - r.height/2, r.width, r.height, r.picLeft, r.frame * 45, 0, RGB(255, 255, 255));
    }
    else if (r.direction == DIRECTION_RIGHT)
    {
        txTransparentBlt(txDC(), r.x - r.width/2, r.y - r.height/2, r.width, r.height, r.picRight, r.frame * 47, 0, RGB(255, 255, 255));
    }

    for ( int nomer = 0; nomer < nomerRobota; nomer++)
    {
        /*robots[nomer].height = 62;
        robots[nomer].speed = 10;
        robots[nomer].manyframeRight = 4;
        robots[nomer].manyframeLeft = 4;
        robots[nomer].manyframeUp = 4;
        robots[nomer].manyframeDown = 4;
        directionFrameFrameTimer(&robots[nomer].direction, &robots[nomer].frame, &robots[nomer].frameTimer);
        robots[nomer].width = 50;*/
        if (nomer > 0)
        {
            robots[nomer].picDown = robots[0].picDown;
            robots[nomer].picUp = robots[0].picUp;
            robots[nomer].picLeft = robots[0].picLeft;
            robots[nomer].picRight = robots[0].picRight;
        }
        else
        {
            robots[nomer].picDown = txLoadImage("IMG\\Men\\Robot\\RobotDown.bmp");
            robots[nomer].picUp = txLoadImage("IMG\\Men\\Robot\\RobotUp.bmp");
            robots[nomer].picLeft = txLoadImage("IMG\\Men\\Robot\\RobotLeft.bmp");
            robots[nomer].picRight = txLoadImage("IMG\\Men\\Robot\\RobotRight.bmp");
        }
    }
}

void directionFrameFrameTimer(int *direction, int *frame, int *frameTimer)
{
    *direction = 0;
    *frame = 0;
    *frameTimer = 0;
}


void readRobot(ifstream* Map, string stroka_Personage, Robot* robots, int* nomerRobota)
{
    string stroka_X = "";
    string stroka_Y = "";
    if (strcmp(stroka_Personage.c_str(), "robot") == 0)
    {
        getline (*Map, stroka_X);
        robots[*nomerRobota].x = atoi(stroka_X.c_str());
        getline (*Map, stroka_Y);
        robots[*nomerRobota].y = atoi(stroka_Y.c_str());
        *nomerRobota = *nomerRobota + 1;
    }
    for(int nomer = 0; nomer < *nomerRobota; nomer++)
    {
    robots[nomer].height = 62;
    robots[nomer].speed = 10;
    robots[nomer].manyframeRight = 4;
    robots[nomer].manyframeLeft = 4;
    robots[nomer].manyframeUp = 4;
    robots[nomer].manyframeDown = 4;
    directionFrameFrameTimer(&robots[nomer].direction, &robots[nomer].frame, &robots[nomer].frameTimer);
    robots[nomer].width = 50;
    }
}

void moveRobot(Robot* r)
{
    int predX = r->x;
    int predY = r->y;
    int maxCountOfFrames = 4;

    if (r->direction == DIRECTION_RIGHT)
    {
        r->x += r->speed;
    }
    else if (r->direction == DIRECTION_LEFT)
    {
        r->x -= r->speed;
    }
    else if (r->direction == DIRECTION_UP)
    {
        r->y -= r->speed;
    }
    else if (r->direction == DIRECTION_DOWN)
    {
        r->y += r->speed;
    }

    if (r->x > txGetExtentX() - r->width)
    {
        while (r->direction == DIRECTION_RIGHT)
        {
            r->direction = random(4);
        }
    }
    else if (r->x < 0 + r->width)
    {
        while (r->direction == DIRECTION_LEFT)
        {
            r->direction = random(4);
        }
    }
    if (r->y > txGetExtentY() - r->height)
    {
        while (r->direction == DIRECTION_DOWN)
        {
            r->direction = random(4);
        }
    }
    else if (r->y < 0 + r->height)
    {
        while (r->direction == DIRECTION_UP)
        {
            r->direction = random(4);
        }
    }


    if (predX != r->x || predY != r->y)
    {
        if (r->frame == 0)
        {
            r->frame = 1;
            r->frameTimer = 0;
        }
        else
        {
            r->frameTimer++;
            if (r->frameTimer >= 20)
            {
                r->frame++;
                if (r->frame >= maxCountOfFrames)
                    r->frame = 1;
                r->frameTimer = 0;
            }
        }
    }


    /*char str[100];
    sprintf(str, "%d", r->x);  //Writing car_x_coord value to str
    txTextOut(100, 100, str);

    sprintf(str, "%d", r->y);  //Writing car_x_coord value to str
    txTextOut(100, 200, str);*/

}

