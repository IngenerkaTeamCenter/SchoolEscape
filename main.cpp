#include "Lib\\TXLib.h"
#include "Lib\\menu.cpp"



int main()
{
    txDisableAutoPause();
    int Window = OKNO_GLAVNOGO_MENU;
    txCreateWindow(1090,654);
    Menu m = {{100, 250, 322, 304, txLoadImage ("IMG\\ImgMainMenu\\Playing.bmp")},
              {100, 350, 449, 404, txLoadImage ("IMG\\ImgMainMenu\\Setting.bmp")},
              {100, 450, 322, 504, txLoadImage ("IMG\\ImgMainMenu\\Exit.bmp")},
              {20, 580, 242, 634,   txLoadImage ("IMG\\ImgMainMenu\\Backword.bmp")},
              {500, 230, 650, 549,   txLoadImage ("IMG\\ImgMainMenu\\Man.bmp")},
              {200, 230, 400, 549,   txLoadImage ("IMG\\ImgMainMenu\\Girl.bmp")},
              {800, 230, 1000, 530,   txLoadImage ("IMG\\ImgMainMenu\\person.bmp")},
                                   txLoadImage ("IMG\\ImgMainMenu\\Menu.bmp")};

    txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), m.fon , 0, 0);
    txBitBlt(txDC(), m.Start.x, m.Start.y,           222, 54, m.Start.pic, 0, 0);
    txBitBlt(txDC(), m.Settings.x, m.Settings.y,     349, 54, m.Settings.pic, 0, 0);
    txBitBlt(txDC(), m.Exit.x, m.Exit.y,             222, 54, m.Exit.pic, 0, 0);

    rabotaMenu(Window, m);



}
