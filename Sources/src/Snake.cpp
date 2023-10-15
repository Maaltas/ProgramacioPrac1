#include "Snake.h"
# include <iostream>
using namespace std;

Snake::~Snake() {
    delete [] arrayPosition;
}
Snake::Snake(int nBonificacions) {
    arrayPosition = new Position[nBonificacions+3];
    for (int i = 0; i < 3; i++) {
        arrayPosition[i].putData(0, i);
    }
    for (int i = 3; i < nBonificacions + 3; i++) {
        arrayPosition[i].putData(-1, -1);
    }
    currentLength = 3;
    currentDir = MyEnum::Rigth;
}
bool Snake::visualitza(int row, int col) {
    for (int i = 0; i < currentLength; i++) {
        if (arrayPosition[i].operator==(new Position(row,col))) {
            arrayPosition[i].visualitza();
            return true;
        }
    }
    return false;
}
bool Snake::contains(int row, int col) {
    for (int i = 0; i < currentLength; i++) {
        if (arrayPosition[i].operator==(new Position(row,col))) {
            return true;
        }
    }
    return false;
}

int* Snake::movimentSerp(MyEnum::eDirection newdir, int nRow, int nCol) {
    currentDir = newdir;
    int *newPos = MyEnum::movement(currentDir);
    arrayPosition[currentLength].putData(newPos[0], newPos[1]);
    if (currentLength > 2) {
        for (int i = 0; i < currentLength - 1; i++) {
            arrayPosition[i] = arrayPosition[i + 1];
        }
        arrayPosition[currentLength - 1].putData(newPos[0], newPos[1]);
    } else if (currentLength == 2) {
        arrayPosition[0].putData(newPos[0], newPos[1]);
    }
    return newPos;
}
void Snake::doesntEat() {
    if (currentLength > 3) {
        arrayPosition[currentLength - 1].putData(-1, -1);
        currentLength--;
    }
}
bool Snake::isDead() {
    return currentLength <= 0;
}