#include "TXLib.h"
struct stairs
{
    int x1, x2;
    int y1, y2;
    CrashZone crash;
};

void stairs1(stairs* s)
{
    txSetColour(TX_WHITE);
    txSetFillColour(TX_RED);
    txRectangle(s->x1 - absolutX, s->y1 - absolutY, s->x2 - absolutX, s->y2 - absolutY);

    if(GameMode == 1)
    {
        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txRectangle(s->crash.x1 - absolutX, s->crash.y1 - absolutY, s->crash.x2 - absolutX, s->crash.y2 - absolutY);
    }
}

void fillCrashZone(stairs* s)
{
    s->crash.x1 = s->x1;
    s->crash.y1 = s->y1;
    s->crash.x2 = s->x1 + 10;
    s->crash.y2 = s->y2;
}

void checkTransitionNextFloor(Bomzh b, stairs* s)
{
    if(intersect(s->crash, b.crash) == true)
    {
        nomerLevel++;
    }
}

void readStairs(ifstream* Map, string stroka_Personage, stairs s)
{
    if (strcmp(stroka_Personage.c_str(), "stairs") == 0)
        {
            string stroka_X = "";
            string stroka_Y = "";
            getline (*Map, stroka_X);
            s.x1 = atoi(stroka_X.c_str());
            getline (*Map, stroka_Y);
            s.y1 = atoi(stroka_Y.c_str());
        }
}
