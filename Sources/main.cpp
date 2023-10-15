#include <iostream>
#include "Taulell.h"

using namespace std;

int demanarValor(int min, int max) {
    int valor;
    do {
        cout << "Especifica un valor dins de l'interval [" << min << ", " << max << "]" << endl;
        cin >> valor;
    } while (valor < min || valor > max);
    return valor;
}
bool tornarJugar(Taulell *tau) {
    char resposta;
    do {
        cout << "Vols jugar una altra partida? (S/N)" << endl;
        cin >> resposta;
        resposta = toupper(resposta);
    } while (resposta != 'S' && resposta != 'N');
    if (resposta == 'S') {
        tau->finalitzar();
        tau->inici(demanarValor(1, 8));
        return true;
    } else {
        return false;
    }
}
int main() {
    Taulell *tau = new Taulell();
    cout << "Indica quantes bonificacions vols:\n";
    tau->inici(demanarValor(1, 10));
    bool jugar = true;
    while (jugar) {
        tau->visualitzar();
        MyEnum::eDirection dir = MyEnum::giveDirection();
        bool esViva = tau->movimentSerp(dir);
        if (!esViva) {
            cout << "Has perdut!" << endl;
            jugar = tornarJugar(tau);
        } else if (tau->getnBonificacions() == 0) {
            cout << "Has guanyat!" << endl;
            jugar = tornarJugar(tau);
        }
    }
    delete tau;
    return 0;
}
