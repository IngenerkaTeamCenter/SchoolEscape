void Cleaner(int x, int y, int direction)
{
if (direction == 0)
        {
            x += 4;
        }
        else if (direction == 1)
        {
            x -= 4;
        }
        else if (direction == 2)
        {
            y += 4;
        }
        else
        {
            y -= 4;
        }

        if (x > txGetExtentX() - 50)
        {
            while (direction == 0)
            {
                direction = random(4);
            }
            x -= 65;
        }
        if (x < 0 + 50)
        {
            while (direction == 1)
            {
                direction = random(4);
            }
            x += 90;
        }

        if (y > txGetExtentY() - 40)
        {
            while (direction == 2)
            {
                direction = random(4);
            }
            y -= 10;
        }
        if (y < 0 + 70)
        {
            while (direction == 3)
            {
                direction = random(4);
            }
            y += 10;
        }

        txSleep(10);
    }
