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


        robots[*nomerRobota].height = 62;
        robots[*nomerRobota].speed = 10;
        robots[*nomerRobota].manyframeRight = 4;
        robots[*nomerRobota].manyframeLeft = 4;
        robots[*nomerRobota].manyframeUp = 4;
        robots[*nomerRobota].manyframeDown = 4;
        robots[*nomerRobota].width = 50;
        directionFrameFrameTimer(&robots[*nomerRobota].direction, &robots[*nomerRobota].frame, &robots[*nomerRobota].frameTimer);
        if (*nomerRobota > 0)
        {
            robots[*nomerRobota].picDown = robots[0].picDown;
            robots[*nomerRobota].picUp = robots[0].picUp;
            robots[*nomerRobota].picLeft = robots[0].picLeft;
            robots[*nomerRobota].picRight = robots[0].picRight;
        }
        else
        {
            robots[*nomerRobota].picDown = txLoadImage("IMG\\Men\\Robot\\RobotDown.bmp");
            robots[*nomerRobota].picUp = txLoadImage("IMG\\Men\\Robot\\RobotUp.bmp");
            robots[*nomerRobota].picLeft = txLoadImage("IMG\\Men\\Robot\\RobotLeft.bmp");
            robots[*nomerRobota].picRight = txLoadImage("IMG\\Men\\Robot\\RobotRight.bmp");
        }

        *nomerRobota = *nomerRobota + 1;
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

