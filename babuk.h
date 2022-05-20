#ifndef BABUK_H_INCLUDED
#define BABUK_H_INCLUDED

#include "graphics.hpp"
#include "widget.h"

class Babu : public Widget
{
protected:
    int fajta;

public:
    Babu(int x, int y, int z, int fajta);
    virtual void rajz();
    bool mozoghat(int toX, int toY, int tabla[8][8]);
};

#endif // BABUK_H_INCLUDED
