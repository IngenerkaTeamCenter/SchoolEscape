#include "TXLib.h"
#include <stdlib.h>

struct Button
{
    int x;
    int y;
    int x2;
    int y2;
    HDC pic;
};

struct Menu
{
    Button Start;
    Button Settings;
    Button Exit;
    Button Back;
    Button Person;
    HDC fon;
};


int main(/*txMouseY() > 504 && 450 > txMouseY() && txMouseButtons() != 1*/)
{
    int Window = 1;
    txCreateWindow(1090,654);
    Menu m = {{100, 250, 322, 304, txLoadImage (" артинки√лавногоћеню\\»грать.bmp")},
              {100, 350, 449, 404, txLoadImage (" артинки√лавногоћеню\\Ќастройки.bmp")},
              {100, 450, 322, 504, txLoadImage (" артинки√лавногоћеню\\¬ыход.bmp")},
              {20, 550, 120, 650,   txLoadImage (" артинки√лавногоћеню\\back.bmp")},
              {500, 50, 700, 350,   txLoadImage (" артинки√лавногоћеню\\перс.bmp")},
                                   txLoadImage (" артинки√лавногоћеню\\menu.bmp")};

    txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
    txBitBlt(txDC(), m.Start.x, m.Start.y,           222, 54, m.Start.pic, 0, 0);
    txBitBlt(txDC(), m.Settings.x, m.Settings.y,     349, 54, m.Settings.pic, 0, 0);
    txBitBlt(txDC(), m.Exit.x, m.Exit.y,             222, 54, m.Exit.pic, 0, 0);
    //txBitBlt(txDC(), m.Back.x, m.Back.y,             100, 100, m.Back.pic, 0, 0);
    //txBitBlt(txDC(), 0, 0, 1000, 700, background_FromTXLibHelp, 0, 0);

    while(1){
    if( m.Start.y2 >= txMouseY() && txMouseY() >= m.Start.y && txMouseButtons() == 1 && Window == 1)
    {
    Window = 2;
    txClear();
    txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
    txBitBlt(txDC(), m.Person.x, m.Person.y,           200, 300, m.Person.pic, 0, 0);
    txBitBlt(txDC(), m.Back.x, m.Back.y,             100, 100, m.Back.pic, 0, 0);
    }


    if( m.Person.y2 >= txMouseY() && txMouseY() >= m.Person.y && m.Person.x2 >= txMouseX() && txMouseX() >= m.Person.x && txMouseButtons() == 1 && Window == 2)
    {
    Window == 22;
    txClear();
    txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
    txBitBlt(txDC(), m.Person.x, m.Person.y,           200, 300, m.Person.pic, 0, 0);
    txBitBlt(txDC(), m.Start.x, m.Start.y,           222, 54, m.Start.pic, 0, 0);
    txBitBlt(txDC(), m.Back.x, m.Back.y,             100, 100, m.Back.pic, 0, 0);
    }

    if( m.Start.y2 >= txMouseY() && txMouseY() >= m.Start.y && txMouseButtons() == 1 && Window == 22)
    {
    Window = 222;
    txClear();
    txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);

    }


    if( m.Settings.y2 >= txMouseY() && txMouseY() >= m.Settings.y &&txMouseButtons() == 1 && Window == 1)
    {
    Window = 3;
    txClear();
    txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
    txBitBlt(txDC(), m.Settings.x, m.Settings.y,     349, 54, m.Settings.pic, 0, 0);
    txBitBlt(txDC(), m.Back.x, m.Back.y,             100, 100, m.Back.pic, 0, 0);
    }
    if( m.Exit.y2 >= txMouseY() && txMouseY() >= m.Exit.y && txMouseButtons() == 1 && Window == 1)
    {
    txDeleteDC(m.Settings.pic);
    txDeleteDC(m.Exit.pic);
    txDeleteDC(m.Start.pic);
    txDeleteDC(m.fon);
    txDeleteDC(m.Back.pic);
    txDeleteDC(m.Person.pic);

    exit(1);
    txDestroyWindow();


    }

    //кнопка назад
    if( m.Back.y2 >= txMouseY() && txMouseY() >= m.Back.y && m.Back.x2 >= txMouseX() && txMouseX() >= m.Back.x && txMouseButtons() == 1 && Window == 2)
    {
    Window == 1;
    txClear();
    txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
    txBitBlt(txDC(), m.Start.x, m.Start.y,           222, 54, m.Start.pic, 0, 0);
    txBitBlt(txDC(), m.Settings.x, m.Settings.y,     349, 54, m.Settings.pic, 0, 0);
    txBitBlt(txDC(), m.Exit.x, m.Exit.y,             222, 54, m.Exit.pic, 0, 0);
    }

    if( m.Back.y2 >= txMouseY() && txMouseY() >= m.Back.y && m.Back.x2 >= txMouseX() && txMouseX() >= m.Back.x && txMouseButtons() == 1 && Window == 22)
    {
    Window == 2;
    txClear();
    txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
    txBitBlt(txDC(), m.Person.x, m.Person.y,           200, 300, m.Person.pic, 0, 0);
    txBitBlt(txDC(), m.Back.x, m.Back.y,             100, 100, m.Back.pic, 0, 0);
    }

    if( m.Back.y2 >= txMouseY() && txMouseY() >= m.Back.y && m.Back.x2 >= txMouseX() && txMouseX() >= m.Back.x && txMouseButtons() == 1 && Window == 3)
    {
    Window = 1;
    txClear();
    txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
    txBitBlt(txDC(), m.Start.x, m.Start.y,           222, 54, m.Start.pic, 0, 0);
    txBitBlt(txDC(), m.Settings.x, m.Settings.y,     349, 54, m.Settings.pic, 0, 0);
    txBitBlt(txDC(), m.Exit.x, m.Exit.y,             222, 54, m.Exit.pic, 0, 0);
    }

    }
    txDeleteDC(m.Settings.pic);
    txDeleteDC(m.Exit.pic);
    txDeleteDC(m.Start.pic);
    txDeleteDC(m.fon);
    txDeleteDC(m.Person.pic);
    txDeleteDC(m.Back.pic);
}
