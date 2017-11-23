#include "TXLib.h"
#include "Lib\\menu.cpp"

int main()
{
    txDisableAutoPause();
    int Window = OKNO_GLAVNOGO_MENU;
    txCreateWindow(1090,654);
    Menu m = {{100, 250, 322, 304, txLoadImage ("IMG\\КартинкиГлавногоМеню\\Играть.bmp")},
              {100, 350, 449, 404, txLoadImage ("IMG\\КартинкиГлавногоМеню\\Настройки.bmp")},
              {100, 450, 322, 504, txLoadImage ("IMG\\КартинкиГлавногоМеню\\Выход.bmp")},
              {20, 580, 242, 634,   txLoadImage ("IMG\\КартинкиГлавногоМеню\\Назад.bmp")},
              {500, 230, 650, 549,   txLoadImage ("IMG\\КартинкиГлавногоМеню\\перс1.bmp")},
              {200, 230, 400, 530,   txLoadImage ("IMG\\КартинкиГлавногоМеню\\перс2.bmp")},
              {800, 230, 1000, 530,   txLoadImage ("IMG\\КартинкиГлавногоМеню\\перс3.bmp")},
                                   txLoadImage ("IMG\\КартинкиГлавногоМеню\\Меню.bmp")};

    txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
    txBitBlt(txDC(), m.Start.x, m.Start.y,           222, 54, m.Start.pic, 0, 0);
    txBitBlt(txDC(), m.Settings.x, m.Settings.y,     349, 54, m.Settings.pic, 0, 0);
    txBitBlt(txDC(), m.Exit.x, m.Exit.y,             222, 54, m.Exit.pic, 0, 0);

    while (1)
    {
        if(Window == OKNO_GLAVNOGO_MENU)
        {
            //Нажали на старт в главном меню
            if( m.Start.y2 >= txMouseY() && txMouseY() >= m.Start.y && m.Start.x2 >= txMouseX() &&
                m.Start.x <= txMouseX()&&
               txMouseButtons() == 1)
            {
                Window = OKNO_PERSONAGA;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                txBitBlt(txDC(), m.Person1.x, m.Person1.y,           150, 319, m.Person1.pic, 0, 0);
                txBitBlt(txDC(), m.Person2.x, m.Person2.y,           200, 300, m.Person2.pic, 0, 0);
                txBitBlt(txDC(), m.Person3.x, m.Person3.y,           200, 300, m.Person3.pic, 0, 0);
                txBitBlt(txDC(), m.Back.x, m.Back.y,            222, 54, m.Back.pic, 0, 0);
                txSleep(500);
            }
            else if( m.Settings.y2 >= txMouseY() && txMouseY() >= m.Settings.y && m.Settings.x2 >= txMouseX() &&
                m.Settings.x <= txMouseX()&&
               txMouseButtons() == 1)
            {
                Window = OKNO_NASTROEK;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                txBitBlt(txDC(), m.Settings.x, m.Settings.y,     349, 54, m.Settings.pic, 0, 0);
                txBitBlt(txDC(), m.Back.x, m.Back.y,             222, 54, m.Back.pic, 0, 0);
                txSleep(500);
            }
            else if( m.Exit.y2 >= txMouseY() && txMouseY() >= m.Exit.y &&
                    m.Exit.x2 >= txMouseX() &&
                    m.Exit.x <= txMouseX()&& txMouseButtons() == 1)
            {
                txDeleteDC(m.Settings.pic);
                txDeleteDC(m.Exit.pic);
                txDeleteDC(m.Start.pic);
                txDeleteDC(m.fon);
                txDeleteDC(m.Back.pic);
                txDeleteDC(m.Person1.pic);
                txDeleteDC(m.Person2.pic);
                txDeleteDC(m.Person3.pic);
                exit(1);
                txDestroyWindow();
            }
        }
        else if (Window == OKNO_PERSONAGA)
        {
            //В окне выбора персонажа нажали на "выбрать"
            if( m.Person1.y2 >= txMouseY() &&
                m.Person1.y <= txMouseY()  &&
                m.Person1.x2 >= txMouseX() &&
                m.Person1.x <= txMouseX() &&
               txMouseButtons() == 1)
            {
                Window = OKNO_PODTVERGDENIA;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                txBitBlt(txDC(), m.Person1.x, m.Person1.y,           150, 319, m.Person1.pic, 0, 0);
                txBitBlt(txDC(), m.Start.x, m.Start.y,           222, 54, m.Start.pic, 0, 0);
                txBitBlt(txDC(), m.Back.x, m.Back.y,             222, 54, m.Back.pic, 0, 0);
                txSleep(500);
            }
            else if( m.Person2.y2 >= txMouseY() &&
                m.Person2.y <= txMouseY()  &&
                m.Person2.x2 >= txMouseX() &&
                m.Person2.x <= txMouseX() &&
               txMouseButtons() == 1)
            {
                Window = OKNO_PODTVERGDENIA;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                txBitBlt(txDC(), m.Person1.x, m.Person1.y,           200, 300, m.Person2.pic, 0, 0);
                txBitBlt(txDC(), m.Start.x, m.Start.y,           222, 54, m.Start.pic, 0, 0);
                txBitBlt(txDC(), m.Back.x, m.Back.y,             222, 54, m.Back.pic, 0, 0);
                txSleep(500);
            }
            else if( m.Person3.y2 >= txMouseY() &&
                m.Person3.y <= txMouseY()  &&
                m.Person3.x2 >= txMouseX() &&
                m.Person3.x <= txMouseX() &&
               txMouseButtons() == 1)
            {
                Window = OKNO_PODTVERGDENIA;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                txBitBlt(txDC(), m.Person1.x, m.Person1.y,           200, 300, m.Person3.pic, 0, 0);
                txBitBlt(txDC(), m.Start.x, m.Start.y,           222, 54, m.Start.pic, 0, 0);
                txBitBlt(txDC(), m.Back.x, m.Back.y,             222, 54, m.Back.pic, 0, 0);
                txSleep(500);
            }
            //кнопка назад
            else if( m.Back.y2 >= txMouseY() && txMouseY() >= m.Back.y && m.Back.x2 >= txMouseX() &&
                txMouseX() >= m.Back.x && txMouseButtons() == 1)
            {
                Window = OKNO_GLAVNOGO_MENU;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                txBitBlt(txDC(), m.Start.x, m.Start.y,           222, 54, m.Start.pic, 0, 0);
                txBitBlt(txDC(), m.Settings.x, m.Settings.y,     349, 54, m.Settings.pic, 0, 0);
                txBitBlt(txDC(), m.Exit.x, m.Exit.y,             222, 54, m.Exit.pic, 0, 0);
                txSleep(500);
            }
        }
        else if (Window == OKNO_PODTVERGDENIA)
        {
            //Нажали на старт в окне подтверждения
            if(m.Start.y2 >= txMouseY() && txMouseY() >= m.Start.y && m.Start.x2 >= txMouseX() &&
               m.Start.x <= txMouseX()&&
               txMouseButtons() == 1)
            {
                Window = OKNO_GAME;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                system("main.exe");
                txSleep(500);
                break;
            }
            else if( m.Back.y2 >= txMouseY() && txMouseY() >= m.Back.y &&
                    m.Back.x2 >= txMouseX() && txMouseX() >= m.Back.x && txMouseButtons() == 1)
            {
                Window = OKNO_PERSONAGA;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                txBitBlt(txDC(), m.Person1.x, m.Person1.y,           150, 319, m.Person1.pic, 0, 0);
                txBitBlt(txDC(), m.Person2.x, m.Person2.y,           200, 300, m.Person2.pic, 0, 0);
                txBitBlt(txDC(), m.Person3.x, m.Person3.y,           200, 300, m.Person3.pic, 0, 0);
                txBitBlt(txDC(), m.Back.x, m.Back.y,            222, 54, m.Back.pic, 0, 0);
                txSleep(500);
            }
        }
        else if (Window == OKNO_NASTROEK)
        {
            if( m.Back.y2 >= txMouseY() && txMouseY() >= m.Back.y && m.Back.x2 >= txMouseX() && txMouseX() >= m.Back.x && txMouseButtons() == 1 && Window == 3)
            {
                Window = OKNO_GLAVNOGO_MENU;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                txBitBlt(txDC(), m.Start.x, m.Start.y,           222, 54, m.Start.pic, 0, 0);
                txBitBlt(txDC(), m.Settings.x, m.Settings.y,     349, 54, m.Settings.pic, 0, 0);
                txBitBlt(txDC(), m.Exit.x, m.Exit.y,             222, 54, m.Exit.pic, 0, 0);
                txSleep(500);
            }
        }
    }

    txDeleteDC(m.Settings.pic);
    txDeleteDC(m.Exit.pic);
    txDeleteDC(m.Start.pic);
    txDeleteDC(m.fon);
    txDeleteDC(m.Person1.pic);
    txDeleteDC(m.Back.pic);
}
