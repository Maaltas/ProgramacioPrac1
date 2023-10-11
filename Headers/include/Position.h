#include <iostream>
#include <string>
#include "MyEnum.h"

#ifndef POSITION_H
#define POSITION_H


class Position {
    private:
        int row;
        int col;
    public:
        Position();
        Position(int i, int j);
        void putData(int row, int col);
        int getRow();
        int getCol();
        void visualitza();
        void visualitza(MyEnum::eDirection dir);
        bool operator == (Position *altre) const;
        bool operator != (Position *altre) const;
};

#endif