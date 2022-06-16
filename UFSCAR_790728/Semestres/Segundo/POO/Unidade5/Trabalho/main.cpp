#include "Peixe.h"
#include "Pessoa.h"
#include "Cachorro.h"

#define PEIXE 1
#define CACHORRO 2

using namespace poo;
using namespace std;
int main() {
    Pessoa* pessoa = new Pessoa("Joao", 12);
    Peixe* nemo = new Peixe("Nemo", 0.15, "Água salgada");
    pessoa->adicionaAnimal(nemo);
    Peixe* dory = new Peixe("Dory", 0.2, "Água doce");
    pessoa->adicionaAnimal(dory);
    Cachorro* teo = new Cachorro("Teo", 6.2, "pug");
    pessoa->adicionaAnimal(teo);

    
    cout << "================== TODOS ==================" << endl << endl;
    pessoa->imprime();
    cout << endl;
    cout << "================== PEIXES ==================" << endl << endl;
    pessoa->imprime(PEIXE);
    cout << endl;
    cout << "================== CACHORROS ==================" << endl << endl;
    pessoa->imprime(CACHORRO);
    cout << endl;
    cout << "================== REMOÇÃO DE UM ELEMENTO ==================" << endl << endl;
    pessoa->removeAnimal("Dory");
    pessoa->imprime();
    return 0;
}