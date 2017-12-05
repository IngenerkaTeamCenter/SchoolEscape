#include "TXLib.h"

const int DIRECTION_DOWN = 0;
const int DIRECTION_UP = 1;
const int DIRECTION_LEFT = 2;
const int DIRECTION_RIGHT = 3;

struct Robot
{
    int x, y;
    int manyframeUp;
    int manyframeDown;
    int manyframeLeft;
    int manyframeRight;
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

void drawRobot(Robot r)
{
    r.frame = 0;
    if (r.direction == DIRECTION_DOWN)
    {
        txTransparentBlt(txDC(), r.x - r.width/2, r.y - r.height/2, r.width, r.height, r.picDown, r.frame * 65, 0, RGB(255, 255, 255));
    }
    else if (r.direction == DIRECTION_UP)
    {
        txTransparentBlt(txDC(), r.x - r.width/2, r.y - r.height/2, r.width, r.height, r.picUp, r.frame * 65, 0, RGB(255, 255, 255));
    }
    else if (r.direction == DIRECTION_LEFT)
    {
        txTransparentBlt(txDC(), r.x - r.width/2, r.y - r.height/2, r.width, r.height, r.picLeft, r.frame * 64, 0, RGB(255, 255, 255));
    }
    else if (r.direction == DIRECTION_RIGHT)
    {
        txTransparentBlt(txDC(), r.x - r.width/2, r.y - r.height/2, r.width, r.height, r.picRight, r.frame * 64, 0, RGB(255, 255, 255));
    }
}

void moveRobot(Robot* r)
{
    int predX = r->x;
    int predY = r->y;
    int maxCountOfFrames = 0;

    if (r->direction == DIRECTION_RIGHT)
    {
        r->x += 4;
    }
    else if (r->direction == DIRECTION_LEFT)
    {
        r->x -= 4;
    }
    else if (r->direction == DIRECTION_UP)
    {
        r->y -= 4;
    }
    else if (r->direction == DIRECTION_DOWN)
    {
        r->y += 4;
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


    char str[100];
    sprintf(str, "%d", r->x);  //Writing car_x_coord value to str
    txTextOut(100, 100, str);

    sprintf(str, "%d", r->y);  //Writing car_x_coord value to str
    txTextOut(100, 200, str);

}

