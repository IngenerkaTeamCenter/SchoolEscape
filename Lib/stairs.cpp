#include "TXLib.h"
struct stairs
{
    int x1, x2;
    int y1, y2;
    CrashZone crash;
    bool tipStairs;
};

void drawStairs(stairs s)
{
    txSetColour(TX_WHITE);
    txRectangle(s.x1 - absolutX, s.y1 - absolutY, s.x2 - absolutX, s.y2 - absolutY);

    if(GameMode == 1)
    {
        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txRectangle(s.crash.x1 - absolutX, s.crash.y1 - absolutY, s.crash.x2 - absolutX, s.crash.y2 - absolutY);
    }
}

void fillCrashZone(stairs* s)
{
    s->crash.x1 = s->x1;
    s->crash.y1 = s->y1;
    s->crash.x2 = s->x1 + 10;
    s->crash.y2 = s->y2;
}


void readStairs(ifstream* Map, string stroka_Personage, stairs* s, int* nomerStairs)
{
    if (strcmp(stroka_Personage.c_str(), "stairs") == 0)
        {
            string stroka_X = "";
            string stroka_Y = "";
            getline (*Map, stroka_X);
            s[*nomerStairs].x1 = atoi(stroka_X.c_str());
            s[*nomerStairs].x2 = s[*nomerStairs].x1 + 200;
            getline (*Map, stroka_Y);
            s[*nomerStairs].y1 = atoi(stroka_Y.c_str());
            s[*nomerStairs].y2 = s[*nomerStairs].y1 + 100;
            getline (*Map, stroka_Y);


            /*
            if (x == 5)
            {
                b = true;
            }
            else
            {
                b = false;
            }

            То же самое, что и

            b = (x == 5);

            */
            s[*nomerStairs].tipStairs = false;
            s[*nomerStairs].tipStairs = (strcmp(stroka_Y.c_str(), "Вверх") == 0);
            fillCrashZone(&s[*nomerStairs]);

            *nomerStairs = *nomerStairs + 1;
        }
        //s->tipStairs = false;
}

stairs s[100];
int nomerStairs = 0;
