#include "TXLib.h"
#include <stdlib.h>

const int MainMenu = 1;
const int WindowMan = 2;
const int ConfirmWindow = 22;
const int WindowGame = 222;
const int SettingWindow = 3;

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
    Button Man;
    HDC fon;
};


int main()
{
    int Window = MainMenu;
    txCreateWindow(1090,654);
    Menu m = {{100, 250, 322, 304, txLoadImage ("IMG\\ImgMainMenu\\Playing.bmp")},
              {100, 350, 449, 404, txLoadImage ("IMG\\ImgMainMenu\\Setting.bmp")},
              {100, 450, 322, 504, txLoadImage ("IMG\\ImgMainMenu\\Exit.bmp")},
              {20, 550, 120, 650,   txLoadImage ("IMG\\ImgMainMenu\\Backword.bmp")},
              {500, 50, 700, 350,   txLoadImage ("IMG\\ImgMainMenu\\Backword2.bmp")},
                                   txLoadImage ("IMG\\ImgMainMenu\\Menu.bmp")};

    txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
    txBitBlt(txDC(), m.Start.x, m.Start.y,           222, 54, m.Start.pic, 0, 0);
    txBitBlt(txDC(), m.Settings.x, m.Settings.y,     349, 54, m.Settings.pic, 0, 0);
    txBitBlt(txDC(), m.Exit.x, m.Exit.y,             222, 54, m.Exit.pic, 0, 0);

    while (1)
    {
        if(Window == MainMenu)
        {
            //Press start in main menu^_^
            if( m.Start.y2 >= txMouseY() && txMouseY() >= m.Start.y &&
               txMouseButtons() == 1)
            {
                Window = WindowMan;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                txBitBlt(txDC(), m.Person.x, m.Person.y,           200, 300, m.Person.pic, 0, 0);
                txBitBlt(txDC(), m.Back.x, m.Back.y,             100, 100, m.Back.pic, 0, 0);
                txSleep(1000);
            }
            else if( m.Settings.y2 >= txMouseY() && txMouseY() >= m.Settings.y &&
               txMouseButtons() == 1)
            {
                Window = SettingWindow;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                txBitBlt(txDC(), m.Settings.x, m.Settings.y,     349, 54, m.Settings.pic, 0, 0);
                txBitBlt(txDC(), m.Back.x, m.Back.y,             100, 100, m.Back.pic, 0, 0);
                txSleep(1000);
            }
            else if( m.Exit.y2 >= txMouseY() && txMouseY() >= m.Exit.y && txMouseButtons() == 1)
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
        }
        else if (Window == WindowMan)
        {
            //� ���� ������ ��������� ������ �� "�������"
            if( m.Person.y2 >= txMouseY() &&
                m.Person.y <= txMouseY()  &&
                m.Person.x2 >= txMouseX() &&
                m.Person.x <= txMouseX() &&
               txMouseButtons() == 1)
            {
                Window = ConfirmWindow;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                txBitBlt(txDC(), m.Person.x, m.Person.y,           200, 300, m.Person.pic, 0, 0);
                txBitBlt(txDC(), m.Start.x, m.Start.y,           222, 54, m.Start.pic, 0, 0);
                txBitBlt(txDC(), m.Back.x, m.Back.y,             100, 100, m.Back.pic, 0, 0);
                txSleep(1000);
            }
            //������ �����
            else if( m.Back.y2 >= txMouseY() && txMouseY() >= m.Back.y && m.Back.x2 >= txMouseX() &&
                txMouseX() >= m.Back.x && txMouseButtons() == 1)
            {
                Window = MainMenu;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                txBitBlt(txDC(), m.Start.x, m.Start.y,           222, 54, m.Start.pic, 0, 0);
                txBitBlt(txDC(), m.Settings.x, m.Settings.y,     349, 54, m.Settings.pic, 0, 0);
                txBitBlt(txDC(), m.Exit.x, m.Exit.y,             222, 54, m.Exit.pic, 0, 0);
                txSleep(1000);
            }
        }
        else if (Window == ConfirmWindow)
        {
            //������ �� ����� � ���� �������������
            if( m.Start.y2 >= txMouseY() &&
               txMouseY() >= m.Start.y && txMouseButtons() == 1)
            {
                txTextOut(100, 100, "WTF???");
                txSleep(1000);
                Window = WindowGame;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);

                txSleep(1000);
                break;
            }
            else if( m.Back.y2 >= txMouseY() && txMouseY() >= m.Back.y &&
                    m.Back.x2 >= txMouseX() && txMouseX() >= m.Back.x && txMouseButtons() == 1)
            {
                Window = WindowMan;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                txBitBlt(txDC(), m.Person.x, m.Person.y,           200, 300, m.Person.pic, 0, 0);
                txBitBlt(txDC(), m.Back.x, m.Back.y,             100, 100, m.Back.pic, 0, 0);
                txSleep(1000);
            }
        }
        else if (Window == SettingWindow)
        {
            if( m.Back.y2 >= txMouseY() && txMouseY() >= m.Back.y && m.Back.x2 >= txMouseX() && txMouseX() >= m.Back.x && txMouseButtons() == 1 && Window == 3)
            {
                Window = 1;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                txBitBlt(txDC(), m.Start.x, m.Start.y,           222, 54, m.Start.pic, 0, 0);
                txBitBlt(txDC(), m.Settings.x, m.Settings.y,     349, 54, m.Settings.pic, 0, 0);
                txBitBlt(txDC(), m.Exit.x, m.Exit.y,             222, 54, m.Exit.pic, 0, 0);
                txSleep(1000);
            }
        }
    }

    txDeleteDC(m.Settings.pic);
    txDeleteDC(m.Exit.pic);
    txDeleteDC(m.Start.pic);
    txDeleteDC(m.fon);
    txDeleteDC(m.Person.pic);
    txDeleteDC(m.Back.pic);
}
