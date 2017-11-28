const int OKNO_GLAVNOGO_MENU = 1;
const int OKNO_PERSONAGA = 2;
const int OKNO_PODTVERGDENIA = 22;
const int OKNO_GAME = 222;
const int OKNO_NASTROEK = 3;

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