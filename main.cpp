#include "graphics.hpp"
#include "sakk.h"
#include "babuk.h"
#include "widget.h"
#include <iostream>

using namespace genv;

const int XX = 401;
const int YY = 401;
int xx = XX;
int yy = YY;
int main()
{
    gout.open(XX, YY);
    event ev;
    Sakk s(xx);
    bool vegevan = false;
    while (gin >> ev && ev.keycode != key_escape)
    {
        s.esemeny(ev);

        if (!vegevan)
        {
            s.tablaRajzolas();

            int eredmeny = s.sakkMatt();
            if (eredmeny != 0)
            {
                vegevan = true;
                if (eredmeny == 1)
                {
                    gout << move_to(0, 0) << color(255, 255, 255) << box(XX, YY);
                    // gout << move_to(0, 0) << color(255, 255, 255) << text("Világos nyert!");
                }
                else
                {
                    gout << move_to(0, 0) << color(0, 0, 0) << box(XX, YY);
                    // gout << move_to(0, 0) << text("Sötét nyert!");
                }
            }
        }

        gout << refresh;
    }
    return 0;
}
