#include <iostream>
#include <string>
#include "MyEnum.h"
#include "Position.h"



class Snake{
    private:
        Position * arrayPosition;
        int currentLength;
        MyEnum::eDirection currentDir;
    public:
        Snake(int nBonificacions);
        Snake();
        bool visualitza(int row, int col);
        bool contains(int row, int col);
        bool isDead();
        int movimentSerp(MyEnum::eDirection newdir, int nRow, int nCol);
        void doesntEat();
};



