#include <iostream>
#include "MyEnum.h"
#include "Position.h"

#ifndef SNAKE_H
#define SNAKE_H

class Snake{
    private:
        Position * arrayPosition;
        int currentLength;
        MyEnum::eDirection currentDir;
        void movimentAvall();
        void movimentAdalt();
    public:
        ~Snake();
        explicit Snake(int nBonificacions);
        bool visualitza(int row, int col);
        bool contains(int row, int col);
        bool isDead();
        int* movimentSerp(MyEnum::eDirection newdir, int nRow, int nCol);
        void doesntEat();
};

#endif

