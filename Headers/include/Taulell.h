<<<<<<< Updated upstream
=======
#ifndef TAULELL_H
#define TAULELL_H

#include "MyEnum.h"
#include "Snake.h"

class Taulell {
private:
    const int files = 8;
    const int columnes = 8;
    int contenidor[8][8];
    int nBonificacions;
    Snake *aSnake;
public:
    Taulell();
    ~Taulell();
    int getFiles();
    int getColumnes();
    int getnBonificacions();
    void inici(int quantes);
    void visualitzar();
    bool movimentSerp(MyEnum::eDirection dir);
    void finalitzar();
};

#endif
>>>>>>> Stashed changes
