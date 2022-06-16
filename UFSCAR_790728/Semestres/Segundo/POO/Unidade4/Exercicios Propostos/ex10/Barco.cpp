#include "Barco.h"
Barco::Barco() {
        cout<<"Construtor barco criado"<<endl;

}
Barco::~Barco() {

    cout<<"Destrutor barco criado"<<endl;
}
void Barco::navega() const {
 cout << "Navegando em superficie maritima" << endl;
}