#include <iostream>
#include<string>
#include<cstring>
#include<stdlib.h>

#include "Aluno.h"

using namespace std;

int main(){
    Aluno a1("Gabriel",10);
    a1.setNota();
    a1.imprime();

    Aluno a2("Felipe", 11);
    a2.setNota();
    a2.imprime();
}