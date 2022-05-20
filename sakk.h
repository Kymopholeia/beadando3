#ifndef SAKK_H_INCLUDED
#define SAKK_H_INCLUDED

#include <vector>

class Sakk
{
    int meret, cellaMeret;
    int v[8][8] = {-1};
    int kijeloltX, kijeloltY = -1;

    bool feherJon = true;

public:
    bool kezd;
    Sakk(int meret);
    void tablaRajzolas();
    void esemeny(genv::event ev);
    int sakkMatt();
};
#endif // SAKK_H_INCLUDED
