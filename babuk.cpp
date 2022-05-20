#include "graphics.hpp"
#include "babuk.h"
#include "iostream"

using namespace genv;
Babu::Babu(int x, int y, int z, int fajta) : Widget(x, y, z)
{
    this->fajta = fajta;
}

void Babu::rajz()
{
    x = x * z;
    y = y * z - 1;
    x = x + 3;
    y = y + 7;
    if (fajta < 7)
    {
        gout << color(200, 0, 0);
    }
    else
    {
        gout << color(0, 200, 0);
    }
    if (fajta == 0 || fajta == 7) // pawn
    {
        if (fajta < 7)
        {
            gout << color(200, 0, 0);
        }
        else
        {
            gout << color(0, 200, 0);
        }
        gout << move_to(x + 19, y + 10) << box_to(x + 21, y + 16);
        gout << move_to(x + 17, y + 12) << box_to(x + 23, y + 14);
        gout << move_to(x + 18, y + 11) << dot << move_to(x + 22, y + 15) << dot;
        gout << move_to(x + 22, y + 11) << dot << move_to(x + 18, y + 15) << dot;
        gout << move_to(x + 16, y + 17) << box_to(x + 24, y + 18);
        gout << move_to(x + 13, y + 19) << line_to(x + 27, y + 19);
        gout << move_to(x + 16, y + 20) << box_to(x + 24, y + 25);
        gout << move_to(x + 15, y + 25) << box_to(x + 25, y + 29);
        gout << move_to(x + 14, y + 29) << box_to(x + 26, y + 31);
        gout << move_to(x + 13, y + 31) << line_to(x + 27, y + 31);
        gout << move_to(x + 11, y + 31) << box_to(x + 29, y + 34);
    }
    if (fajta == 1 || fajta == 8) // rook
    {
        if (fajta < 7)
        {
            gout << color(200, 0, 0);
        }
        else
        {
            gout << color(0, 200, 0);
        }
        gout << move_to(x + 13, y + 10) << box(3, 2);
        gout << move_to(x + 18, y + 10) << box(4, 2);
        gout << move_to(x + 24, y + 10) << box(4, 2);
        gout << move_to(x + 13, y + 12) << box_to(x + 27, y + 14);
        gout << move_to(x + 14, y + 14) << box_to(x + 26, y + 16);
        gout << move_to(x + 15, y + 16) << box_to(x + 25, y + 18);
        gout << move_to(x + 13, y + 19) << line_to(x + 27, y + 19);
        gout << move_to(x + 16, y + 20) << box_to(x + 24, y + 25);
        gout << move_to(x + 15, y + 25) << box_to(x + 25, y + 29);
        gout << move_to(x + 14, y + 29) << box_to(x + 26, y + 31);
        gout << move_to(x + 13, y + 31) << line_to(x + 27, y + 31);
        gout << move_to(x + 11, y + 31) << box_to(x + 29, y + 34);
    }
    if (fajta == 2 || fajta == 9) // knight
    {
        if (fajta < 7)
        {
            gout << color(200, 0, 0);
        }
        else
        {
            gout << color(0, 200, 0);
        }
        gout << move_to(x + 20, y + 6) << line_to(x + 25, y + 6);
        gout << move_to(x + 18, y + 7) << line_to(x + 27, y + 7);
        gout << move_to(x + 16, y + 8) << line_to(x + 26, y + 8);
        gout << move_to(x + 15, y + 9) << line_to(x + 28, y + 9);
        gout << move_to(x + 14, y + 10) << line_to(x + 30, y + 10);
        gout << move_to(x + 13, y + 11) << line_to(x + 30, y + 11) << move_to(x + 26, y + 11) << box(4, 3);
        gout << move_to(x + 13, y + 12) << line_to(x + 21, y + 12);
        gout << move_to(x + 14, y + 13) << line_to(x + 21, y + 13);
        gout << move_to(x + 13, y + 14) << line_to(x + 21, y + 14);
        gout << move_to(x + 14, y + 15) << line_to(x + 21, y + 15);
        gout << move_to(x + 13, y + 16) << line_to(x + 22, y + 16);
        gout << move_to(x + 27, y + 12) << dot << move_to(x + 22, y + 12) << dot;

        gout << move_to(x + 14, y + 17) << line_to(x + 22, y + 17);
        gout << move_to(x + 16, y + 18) << line_to(x + 24, y + 18);
        gout << move_to(x + 13, y + 19) << line_to(x + 27, y + 19);
        gout << move_to(x + 16, y + 20) << box_to(x + 24, y + 25);
        gout << move_to(x + 15, y + 25) << box_to(x + 25, y + 29);
        gout << move_to(x + 14, y + 29) << box_to(x + 26, y + 31);
        gout << move_to(x + 13, y + 31) << line_to(x + 27, y + 31);
        gout << move_to(x + 11, y + 31) << box_to(x + 29, y + 34);
    }
    if (fajta == 3 || fajta == 10) // bishop
    {
        if (fajta < 7)
        {
            gout << color(200, 0, 0);
        }
        else
        {
            gout << color(0, 200, 0);
        }
        gout << move_to(x + 20, y + 6) << dot;
        gout << move_to(x + 19, y + 7) << box_to(x + 21, y + 9);
        gout << move_to(x + 18, y + 9) << box_to(x + 22, y + 11);
        gout << move_to(x + 17, y + 11) << box_to(x + 23, y + 13);
        gout << move_to(x + 16, y + 13) << box_to(x + 24, y + 15);
        gout << move_to(x + 17, y + 15) << box_to(x + 23, y + 19);
        gout << move_to(x + 13, y + 20) << line_to(x + 27, y + 20);
        gout << move_to(x + 16, y + 19) << box_to(x + 24, y + 25);
        gout << move_to(x + 15, y + 25) << box_to(x + 25, y + 29);
        gout << move_to(x + 14, y + 29) << box_to(x + 26, y + 31);
        gout << move_to(x + 13, y + 31) << line_to(x + 27, y + 31);
        gout << move_to(x + 11, y + 31) << box_to(x + 29, y + 34);
    }
    if (fajta == 4 || fajta == 11) // queen
    {
        if (fajta < 7)
        {
            gout << color(200, 0, 0);
        }
        else
        {
            gout << color(0, 200, 0);
        }
        gout << move_to(x + 19, y + 7) << box_to(x + 21, y + 9);
        gout << move_to(x + 23, y + 9) << dot;
        gout << move_to(x + 19, y + 2) << box_to(x + 21, y + 4);
        gout << move_to(x + 16, y + 10) << line_to(x + 16, y + 6) << line_to(x + 18, y + 10);
        gout << line_to(x + 20, y + 6) << line_to(x + 22, y + 10) << line_to(x + 24, y + 6) << line_to(x + 24, y + 10);
        gout << move_to(x + 16, y + 10) << box_to(x + 24, y + 12);
        gout << move_to(x + 17, y + 12) << box_to(x + 23, y + 14);
        gout << move_to(x + 17, y + 13) << box_to(x + 23, y + 18);
        gout << move_to(x + 18, y + 14) << line_to(x + 22, y + 14);
        gout << move_to(x + 13, y + 14) << line_to(x + 27, y + 14);
        gout << move_to(x + 16, y + 18) << box_to(x + 24, y + 21);
        gout << move_to(x + 15, y + 21) << box_to(x + 25, y + 25);
        gout << move_to(x + 14, y + 25) << box_to(x + 26, y + 29);
        gout << move_to(x + 13, y + 29) << box_to(x + 27, y + 31);
        gout << move_to(x + 12, y + 31) << line_to(x + 28, y + 31);
        gout << move_to(x + 10, y + 31) << box_to(x + 30, y + 34);
    }
    if (fajta == 5 || fajta == 12) // king
    {
        if (fajta < 7)
        {
            gout << color(200, 0, 0);
        }
        else
        {
            gout << color(0, 200, 0);
        }
        gout << move_to(x + 19, y + 1) << box_to(x + 21, y + 7);
        gout << move_to(x + 17, y + 3) << box_to(x + 23, y + 5); // kereszt
        gout << move_to(x + 13, y + 10) << box_to(x + 27, y + 11);
        gout << move_to(x + 16, y + 11) << box_to(x + 24, y + 13);
        gout << move_to(x + 17, y + 13) << box_to(x + 23, y + 18);
        gout << move_to(x + 13, y + 14) << line_to(x + 27, y + 14);
        gout << move_to(x + 16, y + 18) << box_to(x + 24, y + 21);
        gout << move_to(x + 15, y + 21) << box_to(x + 25, y + 25);
        gout << move_to(x + 14, y + 25) << box_to(x + 26, y + 29);
        gout << move_to(x + 13, y + 29) << box_to(x + 27, y + 31);
        gout << move_to(x + 12, y + 31) << line_to(x + 28, y + 31);
        gout << move_to(x + 10, y + 31) << box_to(x + 30, y + 34);
    }
}

bool canMoveOrTake(int myFigura, int otherFigura)
{
    // empty field
    if (otherFigura == -1)
        return true;
    // enemy figure
    if (myFigura < 7 && otherFigura > 6 || myFigura > 6 && otherFigura < 7)
        return true;
    return false;
}

bool Babu::mozoghat(int toX, int toY, int tabla[8][8])
{
    int fromType = tabla[x][y];
    int toType = tabla[toX][toY];
    int moveX = toX - x;
    int moveY = toY - y;

    if (moveX == 0 && moveY == 0)
        return false;

    int stepX = moveX / abs(moveX);
    int stepY = moveY / abs(moveY);

    bool isWhitePiece = fromType > 6;

    std::cout << "fromType: " << fromType << " toType: " << toType << std::endl;
    std::cout << "x: " << x << " y: " << y << " toX: " << toX << " toY: " << toY << std::endl;
    std::cout << "moveX: " << moveX << " moveY: " << moveY << std::endl;

    if (!canMoveOrTake(fromType, toType) || fromType == -1)
        return false;

    if (fromType == 0 || fromType == 7) // pawn
    {
        if (abs(moveY) > 2)
            return false;
        if (isWhitePiece)
        {
            if (moveY > -1)
                return false;
            if (toType == -1)
            {
                // simple move
                if (moveX == 0 && moveY == -1)
                    return true;
                if (y == 6 && moveX == 0 && moveY == -2)
                {
                    return true;
                }
            }
            else
            {
                // diagonal take, since toType is not -1, and we can move here (start condition above)
                if (abs(moveX) == 1 && moveY == -1)
                    return true;
            }
        }
        else
        {
            if (moveY < 1)
                return false;
            if (toType == -1)
            {
                // simple move
                if (moveX == 0 && moveY == 1)
                    return true;
                if (y == 1 && moveX == 0 && moveY == 2)
                {
                    return true;
                }
            }
            else
            {
                // diagonal take, since toType is not -1, and we can move here (start condition above)
                if (abs(moveX) == 1 && moveY == 1)
                    return true;
            }
        }
        return false;
    }

    if (fromType == 1 || fromType == 8) // rook
    {
        if (moveX == 0)
        {
            for (int i = y + stepY; i != toY; i += stepY)
            {
                if (tabla[x][i] != -1)
                    return false;
            }
            return true;
        }
        if (moveY == 0)
        {
            for (int i = x + stepX; i != toX; i += stepX)
            {
                if (tabla[i][y] != -1)
                    return false;
            }
            return true;
        }
    }
    if (fromType == 2 || fromType == 9) // knight
    {
        if (abs(moveX) == 1 && abs(moveY) == 2)
            return true;
        if (abs(moveX) == 2 && abs(moveY) == 1)
            return true;
    }
    if (fromType == 3 || fromType == 10) // bishop
    {
        // is movement on diagonal
        if (abs(moveX) != abs(moveY))
            return false;

        for (int i = 1; i < abs(moveX); i++)
        {
            if (tabla[x + stepX * i][y + stepY * i] != -1)
                return false;
        }
        return true;
    }
    if (fromType == 4 || fromType == 11) // queen
    {
        // queen can move if bishop or rook could make the same move
        // if diagonal, check same as bishop
        if (abs(moveX) == abs(moveY))
        {
            for (int i = 1; i < abs(moveX); i++)
            {
                if (tabla[x + stepX * i][y + stepY * i] != -1)
                    return false;
            }
            return true;
        }
        // if not diagonal, check same as rook
        if (moveX == 0)
        {
            for (int i = y + stepY; i != toY; i += stepY)
            {
                if (tabla[x][i] != -1)
                    return false;
            }
            return true;
        }
        if (moveY == 0)
        {
            for (int i = x + stepX; i != toX; i += stepX)
            {
                if (tabla[i][y] != -1)
                    return false;
            }
            return true;
        }
        return false;
    }
    if (fromType == 5 || fromType == 12) // king
    {
        // king can move one square in any direction
        if (abs(x - toX) <= 1 && abs(y - toY) <= 1)
        {
            // create the board where the king made the move
            int tableFuture[8][8];
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    tableFuture[i][j] = tabla[i][j];
                }
            }
            tableFuture[x][y] = -1;
            tableFuture[toY][toX] = fromType;

            // check if any other piece could move to the destination
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    int ellenorzottFigura = tableFuture[i][j];
                    if (ellenorzottFigura == -1)
                        continue;
                    // don't check against our own
                    if (fromType == 5 && ellenorzottFigura < 7)
                        continue;
                    if (fromType == 12 && ellenorzottFigura > 6)
                        continue;

                    // if enemy king, we can't move closer than 2 squares (checking this like others would run infinite)
                    if (isWhitePiece)
                    {
                        if (ellenorzottFigura == 5 && abs(i - toX) <= 1 && abs(j - toY) <= 1)
                            return false;
                    }
                    else // black king
                    {
                        if (ellenorzottFigura == 12 && abs(i - toX) <= 1 && abs(j - toY) <= 1)
                            return false;
                    }

                    // is there any other piece that could move here? if so, the king can't move there
                    Babu babu = Babu(i, j, z, ellenorzottFigura);
                    if (babu.mozoghat(toX, toY, tableFuture))
                    {
                        // check pawn taking separately
                        if (ellenorzottFigura == 0 || ellenorzottFigura == 7)
                        {
                            if (abs(i - toX) != 1)
                            {
                                continue;
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }
    }
    return false;
}
