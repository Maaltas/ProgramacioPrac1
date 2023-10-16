# include <iostream>
# include "Position.h"


Position::Position() {
    row = -1;
    col = -1;
}

Position::Position(int i, int j) {
    row = i;
    col = j;
}

void Position::putData(int row, int col) {
    this->row=row;
    this->col=col;
}

int Position::getRow() {
    return row;
}

int Position::getCol() {
    return col;
}

void Position::visualitza() {
    cout << " *";
}

void Position::visualitza(MyEnum::eDirection dir) {
    cout << MyEnum::toSymbol(dir);
}

bool Position::operator==(Position *altre) const {
    return (row == altre->getRow()) && (col == altre->getCol());
}

bool Position::operator!=(Position *altre) const {
    return !(*this == altre);
}
