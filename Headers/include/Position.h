#include <iostream>
#include <string>
using namespace std;

#ifndef PRACTICA1_POSTION_H
#define PRACTICA1_POSTION_H

namespace Position{
    int row,col;
    void visualitza();
    void visualitza(MyEnum::eDirection dir);
    void putData(int row,int col);

    int getCol();
    int getRow();
}

#endif