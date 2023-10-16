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
        Position* temp = new Position(row,col);
        for (int i = 0; i < currentLength - 1; i++) {
            if (arrayPosition[i]==temp) {
                arrayPosition[i].visualitza();
                delete temp;
                return true;
            }
        }
        if(arrayPosition[currentLength - 1] == temp)
            arrayPosition[currentLength - 1].visualitza(currentDir);

        delete temp;
        return false;
    }
    bool Snake::contains(int row, int col) {
        Position* temp =new Position(row,col);
        for (int i = 0; i <= currentLength; i++) {
            if (arrayPosition[i]==(temp)) {
                delete temp;
                return true;
            }
        }
        delete temp;
        return false;
    }
    void Snake::movimentAvall() {
        for (int i = currentLength - 1; i > 0; i--) {
            arrayPosition[i] = arrayPosition[i - 1];
        }
    }

    void Snake::movimentAdalt() {
        for (int i = 0; i < currentLength - 1; i++) {
            arrayPosition[i] = arrayPosition[i + 1];
        }
    }
    int* Snake::movimentSerp(MyEnum::eDirection newdir, int nRow, int nCol) {
        currentDir = newdir;
        int *newPos = MyEnum::movement(currentDir);
        if (newPos[0] >= 0 && newPos[0] < nRow && newPos[1] >= 0 && newPos[1] < nCol) {
            if (!contains(newPos[0], newPos[1])) {
                if (currentDir == MyEnum::Down || currentDir == MyEnum::Rigth) {
                    movimentAvall();
                    arrayPosition[0].putData(newPos[0], newPos[1]);
                }
                else if (currentDir == MyEnum::Up || currentDir == MyEnum::Left) {
                    movimentAdalt();
                    arrayPosition[currentLength - 1].putData(newPos[0], newPos[1]);
                }
                currentLength++;
            }
        } else {
            if (newPos[0] < 0) newPos[0] = nRow - 1;
            else if (newPos[0] >= nRow) newPos[0] = 0;
            else if (newPos[1] < 0) newPos[1] = nCol - 1;
            else if (newPos[1] >= nCol) newPos[1] = 0;
            if (currentDir == MyEnum::Down || currentDir == MyEnum::Rigth) {
                movimentAvall();
                arrayPosition[0].putData(newPos[0], newPos[1]);
            } else if (currentDir == MyEnum::Up || currentDir == MyEnum::Left) {
                movimentAdalt();
                arrayPosition[currentLength - 1].putData(newPos[0], newPos[1]);
            }
            currentLength++;
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




