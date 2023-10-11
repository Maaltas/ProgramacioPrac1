#include "Taulell.h"

Taulell::Taulell(){
    nBonificacions = 0;
    aSnake = nullptr;

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

}

void Taulell::visualitzar(){

}

bool Taulell::movimentSerp(MyEnum::eDirection dir){

}

void Taulell::finalitzar(){

}