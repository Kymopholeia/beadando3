#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

class Widget
{
protected:
    int x, y, z;

public:
    Widget(int x, int y, int z) : x(x), y(y), z(z){};
    virtual void rajz(int fajt) = 0;
    bool actual(int ex, int ey)
    {
        return ex >= x * z && ex <= x * z + z && ey > y * z && ey < y * z + z;
    }
};

#endif // WIDGET_H_INCLUDED
