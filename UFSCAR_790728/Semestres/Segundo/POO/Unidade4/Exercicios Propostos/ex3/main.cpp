#include "Pessoas.h"
#include "alunos.h"

int main() {

    Pessoas p1(18,"Fulano da Silva");
    Pessoas p2(19,"Sincrano Andrade");
    Pessoas p3(18,"Beltrano dos Santos");
    
    p1.imprime();
    
    cout << "Nome: " << p2.getNome() << endl;
    cout << "Idade: " << p2.getIdade() << endl;
    
    p3.imprime();
        
    cout << p1.compare(p2) << endl;
    cout << p1.compare(p3) << endl;
    cout << p2.compare(p1) << endl;
   
    Alunos a1( 18,"Aluno teste", 927450);

    a1.imprime(); // invocando o método implementado na classe Aluno
    cout << endl;
    
    a1.Pessoas::imprime(); // invocando o método implementado na classe Pessoa (ou seja, não quer usar o método sobreposto na classe filha)
    cout << endl;

    cout << p1.compare(a1) << endl;

    return 0;
}

