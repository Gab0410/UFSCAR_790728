#include "Universidade.h"
int main() {
    
    Universidade *ufscar = new Universidade("UFSCar");
    cout << "-------------------------------" << endl;
    ufscar->adicionaDepto("Computaçao", "DC");
    ufscar->adicionaDepto("Matematica", "DM");
    ufscar->adicionaDepto("Fisica", "DF");
    cout << "-------------------------------" << endl;
    ufscar->imprime();
    cout << "-------------------------------" << endl;
    ufscar->removeDepto("DM");
    cout << "-------------------------------" << endl;
    ufscar->imprime();
    cout << "-------------------------------" << endl;
    delete ufscar;
    return 0;
}