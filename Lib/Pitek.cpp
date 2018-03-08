#include "TXLib.h"
#include <fstream>
#include <string>

using namespace std;

struct Pitek
{
    int x, y;
    int width;
    int height;
    HDC picDown;
    CrashZone crash;
};

Pitek Piteks[100];
int nomerPiteka = 0;

void readPitek(ifstream* Map, string stroka_Personage, Pitek* Piteks, int* nomerPiteka)
{
    string stroka_X = "";
    string stroka_Y = "";
    if (strcmp(stroka_Personage.c_str(), "pitek") == 0)
        {
            getline (*Map, stroka_X);
            Piteks[*nomerPiteka].x = atoi(stroka_X.c_str());
            getline (*Map, stroka_Y);
            Piteks[*nomerPiteka].y = atoi(stroka_Y.c_str());
            *nomerPiteka = *nomerPiteka + 1;
            //nomerPiteka++;
        }
}
void drawPitek(Pitek pi)
{
    txTransparentBlt(txDC(),  pi.x - pi.width / 2, pi.y - pi.height / 2, pi.width, pi.height, pi.picDown, 0, 0, RGB(255, 255, 255));
}

void fillCrashZone(Pitek* pi)
{
    pi->crash.x1 = pi->x - 90;
    pi->crash.y1 = pi->y - 29;
    pi->crash.x2 = pi->x + 90;
    pi->crash.y2 = pi->y + 40;
}
