#include <iostream>

#include "ex1.h"

using namespace std;

int main(){
    livro l("Cpp-Como Programar");
    livro l2;

    l.imprimir();
    l2.imprimir();

    l.inserir_autor("Ednaldo P.");
    l.imprimir();

    return 0;
}