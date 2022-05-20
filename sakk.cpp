#include "graphics.hpp"
#include "widget.h"
#include "babuk.h"
#include "sakk.h"
#include <vector>
#include <iostream>

using namespace genv;
Sakk::Sakk(int meret) : meret(meret)
{
    cellaMeret = (meret) / 8;
    kezd = true;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            v[i][j] = -1;
        }
    }

    int k = 0;
    int p = 1;
    while (k < 8)
    {
        v[0][k] = p;
        v[1][k] = p + 1;
        v[2][k] = p + 2;
        v[3][k] = p + 3;
        v[4][k] = p + 4;
        v[5][k] = p + 2;
        v[6][k] = p + 1;
        v[7][k] = p;
        k += 7;
        p += 7;
    }

    for (int i = 0; i < 8; i++)
    {
        v[i][1] = 0;
        v[i][6] = 7;
    }
}

void Sakk::tablaRajzolas()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            genv::color szin = genv::color(0, 0, 0);
            if ((i + j) % 2 == 0)
            {
                szin = genv::color(255, 255, 255);
            }
            gout << move_to(i * cellaMeret, j * cellaMeret) << szin << box(cellaMeret, cellaMeret);
        }
    }

    // draw a blue selection border at kijeloltX and kijeloltY
    if (kijeloltX != -1 && kijeloltY != -1)
    {
        gout << move_to(kijeloltX * cellaMeret, kijeloltY * cellaMeret) << color(0, 0, 255) << line(cellaMeret, 0) << line(0, cellaMeret) << line(-cellaMeret, 0) << line(0, -cellaMeret);
        gout << move_to(kijeloltX * cellaMeret + 1, kijeloltY * cellaMeret + 1) << color(0, 0, 255) << line(cellaMeret - 2, 0) << line(0, cellaMeret - 2) << line(-cellaMeret + 2, 0) << line(0, -cellaMeret + 2);

        Babu babu = Babu(kijeloltX, kijeloltY, cellaMeret, v[kijeloltX][kijeloltY]);
        // draw a green border around every square that the selected piece can move to
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (v[kijeloltX][kijeloltY] && babu.mozoghat(i, j, v))
                {
                    gout << move_to(i * cellaMeret, j * cellaMeret) << color(0, 255, 0) << line(cellaMeret, 0) << line(0, cellaMeret) << line(-cellaMeret, 0) << line(0, -cellaMeret);
                }
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Babu babu(i, j, cellaMeret, v[i][j]);
            babu.rajz();
        }
    }
}
void Sakk::esemeny(genv::event ev)
{
    if (ev.type == ev_mouse && (ev.button == btn_left || ev.button == btn_right))
    {
        int ex = ev.pos_x;
        int ey = ev.pos_y;
        int mezoX = ex / cellaMeret;
        int mezoY = ey / cellaMeret;

        if (ev.button == btn_left)
        {
            kijeloltX = -1;
            kijeloltY = -1;
            int figura = v[mezoX][mezoY];
            if (figura != -1)
            {
                if (feherJon && figura > 6 || !feherJon && figura < 7)
                {
                    kijeloltX = mezoX;
                    kijeloltY = mezoY;
                }
            }
        }

        if (ev.button == btn_right && kijeloltX != -1 && kijeloltY != -1)
        {
            Babu babu(kijeloltX, kijeloltY, cellaMeret, v[mezoX][mezoY]);
            if (babu.mozoghat(mezoX, mezoY, v))
            {
                v[mezoX][mezoY] = v[kijeloltX][kijeloltY];
                v[kijeloltX][kijeloltY] = -1;
                kijeloltX = -1;
                kijeloltY = -1;
                feherJon = !feherJon;
            }
        }

        tablaRajzolas();
    }
}

// -1 if white lost, 1 if black lost, 0 if not over
int Sakk::sakkMatt()
{
    // if one of the kings is gone, the game is over
    bool whiteLost = true;
    bool blackLost = true;

    // find white king, value 12
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (v[i][j] == 12)
            {
                whiteLost = false;
            }
        }
    }
    // find black king, value 5
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (v[i][j] == 5)
            {
                blackLost = false;
            }
        }
    }

    if (whiteLost)
    {
        return -1;
    }
    else if (blackLost)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}