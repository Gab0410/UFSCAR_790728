#include "Medico.h"
#include "Enfermeiro.h"
#include <vector>
#include <algorithm>

int main() {
    
    vector<Funcionario*> funcionarios;

    funcionarios.push_back(new Enfermeiro(67890, "Nurse Beth", 12345));
    funcionarios.push_back(new Enfermeiro(24680, "Enfermeira Mary", 54321));
    funcionarios.push_back(new Medico(12345, "Dr. House", "Neurologista"));
    funcionarios.push_back(new Medico(54321, "Drauzio Varella", "Oncologista"));

    cout << "Imprimindo vector" << endl << endl;

    for (unsigned int i = 0; i < funcionarios.size(); i++) {
        funcionarios[i]->imprime();
        cout << endl;
    }

    cout << "Ordenando vector (nome)" << endl << endl;

    sort(funcionarios.begin(), funcionarios.end(), Funcionario::comparaNome);
    
    for (unsigned int i = 0; i < funcionarios.size(); i++) {
        funcionarios[i]->imprime();
        cout << endl;
    }

    cout << "Ordenando vector (CPF)" << endl << endl;

    sort(funcionarios.begin(), funcionarios.end(), Funcionario::comparaCPF);

    for (unsigned int i = 0; i < funcionarios.size(); i++) {
        funcionarios[i]->imprime();
        cout << endl;
    }
    
    return 0;
}