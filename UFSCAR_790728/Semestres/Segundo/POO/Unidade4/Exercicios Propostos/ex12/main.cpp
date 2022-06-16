#include <cstdlib>

#include "Pess.h"
#include "Professor.h"
#include "Coordenador.h"

using namespace poo;

int main() {
    
    Pess* pessoas[3];
    
    Pess p1("Fulano", 12345);
     
    Professor p2("Sincrano", 54321, 1000);
    
    Coordenador p3("Beltrano", 13579, 2000, "BCC");
        
    pessoas[0] = &p1;
    pessoas[1] = &p2;
    pessoas[2] = &p3;
    
    for (int i = 0; i < 3; i++) {
        pessoas[i]->imprime();
        cout << endl;
    }
    
    return 0;
}

