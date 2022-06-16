#include "Aluno.h"
#include <iostream>
using namespace std;
int main() {

    // Ponteiro para objeto (instancia de classe)
    
    Endereco* end1;
    // Construtor que seta os valores de todos os atributos
    end1 = new Endereco("Rua da Saudade", 10, "Sao Carlos", "Sao Paulo");
    
    // Criaçao de objeto estatico.
    // Construtor que seta os valores de todos os atributos
    Endereco end2("Rua das Bandeiras", 1000, "Sao Carlos", "Sao Paulo");
    // Construtor com 3 parametros
    Aluno aluno1("Fulano", 12345, *end1);

    // Ponteiro para objeto (instancia de classe)
    // Construtor que seta os valores de todos os atributos
    Aluno* aluno2 = new Aluno("Sincrano", 54321, end2);

    // imprime as informaçoes do aluno1
     aluno1.imprime();

    // imprime as informaçoes do aluno2

    aluno2->imprime();

    cout << endl;

    cout << "(Destrutor) - Explicitos (delete)" << endl;

    delete end1;
    delete aluno2;

    cout << "(Destrutor) - Implicitos (fim de funçao)" << endl;
}