#include <iostream>

using namespace std;

#include "Date.h"
#include "Employ.h"

#include <cstring>

Employ::Employ(const char *const first, const char *const second, const Date &dateBirth, const Date &dateHire)
    :birthDay(dateBirth),
    hireDay(dateHire)
    {
        int tam = strlen(first);
        tam = (tam<25?tam:24);
        strncpy(fName,first,tam);
        fName[tam] = '\0';

        tam = strlen(second);
        tam = (tam<25?tam:24);
        strncpy(sName,second,tam);
        sName[tam] = '\0';

        cout<<"Construtor do objeto de: "<<fName<<" "<<sName<<endl;
    }
void Employ::print() const{
    cout<<"Datas de "<<fName<<" "<<sName<<endl;
    cout<<"Contratado: ";
    hireDay.print();
    cout<<endl;
    cout<<"Aniversario: ";
    birthDay.print();
    cout<<endl;
}
Employ::~Employ(){
    cout<<"Destrutor de "<<fName<<" "<<sName<<" ativado"<<endl;
}

