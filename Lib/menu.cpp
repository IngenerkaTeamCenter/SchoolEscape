/*const int OKNO_GLAVNOGO_MENU = 1;
const int OKNO_PERSONAGA = 2;
const int OKNO_PODTVERGDENIA = 22;
const int OKNO_GAME = 222;
const int OKNO_NASTROEK = 3;*/
#include "consmenu.cpp"

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
    Button Person1;
    Button Person2;
    Button Person3;
    HDC fon;
};

void rabotaMenu(int Window, Menu m)
{
    int nomerPerson = 1;

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
                txBitBlt(txDC(), m.Person2.x, m.Person2.y,           150, 319, m.Person2.pic, 0, 0);
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
                nomerPerson = 2;
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
                nomerPerson = 1;
                txClear();
                txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
                txBitBlt(txDC(), m.Person1.x, m.Person1.y,           150, 319, m.Person2.pic, 0, 0);
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
                nomerPerson = 3;
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
                //txTextOut(100, 100, "dsgsdgsdgf");
                char cmd[100];
                sprintf (cmd, "game.exe %d" , nomerPerson);

                txTextOut(200, 200, cmd);
                txSleep(1000);
                system(cmd);
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
                txBitBlt(txDC(), m.Person2.x, m.Person2.y,           150, 319, m.Person2.pic, 0, 0);
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


}
