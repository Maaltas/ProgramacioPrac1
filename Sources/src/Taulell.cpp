
#include "Taulell.h"
#include "Snake.h"
#include "Position.h"

#include <cstdlib>
#include <ctime>
using namespace std;


Taulell::Taulell(){
    nBonificacions = 0;
    aSnake = new Snake(nBonificacions);

    for (int i = 0; i < files; i++){
        for (int j = 0; j < columnes; j++){
            contenidor[i][j] = 0;
        }
    }
}

Taulell::~Taulell(){
    if (aSnake != nullptr){
        delete aSnake;
        aSnake = nullptr;
    }
}

int Taulell::getFiles(){
    return files;
}

int Taulell::getColumnes(){
    return columnes;
}

int Taulell::getnBonificacions(){
    return nBonificacions;
}

void Taulell::inici(int quantes){
    srand(time(0));

    int bonificacionsCreades = 0;

    for (int i = 1; i < files && bonificacionsCreades < quantes; i++) {
        for (int j = 0; j < columnes && bonificacionsCreades < quantes; j++) {
            if (bonificacionsCreades >= quantes) {
                break;
            }

            int random = rand() % 10;
            if (random == 0) {
                contenidor[i][j] = 1;
                bonificacionsCreades++;
                cout << "Activem la posició: " << i << ", " << j << "\n";
            }
        }
    }
    nBonificacions = bonificacionsCreades;
}

void Taulell::visualitzar(){
    cout << "  ";
    for (int i = 0; i < columnes; i++) {
        cout << " " << i;
    }
    cout <<"\n";

    for (int i = 0; i < files; i++) {
        cout << i << "| ";
        for (int j = 0; j < columnes; j++) {
            if(aSnake->contains(i,j)){
                Position p(i,j);
            } else if (contenidor[i][j] == 1){
                cout << "& ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

bool Taulell::movimentSerp(MyEnum::eDirection dir){
    int* newPos = aSnake->movimentSerp(dir, files, columnes);
    bool esViva = !aSnake->isDead();

    if(esViva && contenidor[newPos[0]][newPos[1]] == 1){
        nBonificacions--;
        contenidor[newPos[0]][newPos[1]] = 0;
    }

    delete[] newPos;
    return esViva;
}

void Taulell::finalitzar() {
    delete aSnake;
    aSnake = new Snake(nBonificacions);

    for (int i = 0; i < files; i++) {
        for (int j = 0; j < columnes; j++) {
            contenidor[i][j] = 0;
        }
    }
    nBonificacions = 0;
}


