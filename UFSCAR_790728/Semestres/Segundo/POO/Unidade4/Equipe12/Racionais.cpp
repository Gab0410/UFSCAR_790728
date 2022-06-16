/*Nome dos participantes:

Alexandra Floriano - RA 761771
Alexandre dos Santos Gualberto - RA 790843
Gabriel Meirelles Carvalho Orlando - RA 790728
Marcelina Maye Abaga - RA 790139
Ricardo Araújo da Silva - RA 790919

*/

#include "Racionais.h"

//Função de Saída
ostream &operator<<(ostream &out,const Racionais &n){
    if(n.denominador == 1)
        out<<n.numerador;
    else
        out<<n.numerador<<"/"<<n.denominador;
    return out;
};

//Construtor
Racionais::Racionais(const int num, const int deno)
    :numerador(((num > 0 && deno < 0) || (num < 0 && deno > 0))?-1*abs(num/racionaliza(num,deno)):num/racionaliza(num,deno)),

    denominador(((num < 0 && deno > 0) || (num > 0 && deno < 0))?abs(deno/racionaliza(num,deno)):(deno == 0?1:deno/racionaliza(num,deno)))
    {
        if(deno == 0){
            cout<<"Erro ao instanciar o objeto (denominador = 0)\nPrograma sera encerrado!"<<endl;
            exit(1);
        }
    }
//Destrutor
Racionais::~Racionais(){}

//Racionalizador, efetua o mdc
int Racionais::racionaliza(int n, int d) const{
    if(d>n){
        int aux = n;
        n = d;
        d = aux;
    }
    int r;
    while (d != 0) {
    r = n % d;
    n = d;
    d = r;
    }
    return n;
}

//Método getters
const int Racionais::getNumerador() const{
    return numerador;
}
const int Racionais::getDenominador() const{
    return denominador;
}

//Sobrecarga dos operadores aritiméticos
Racionais Racionais::operator+(const Racionais &r2){
    int scima = this->numerador * r2.denominador + r2.numerador * this->denominador;
    int sbaixo = this->denominador * r2.denominador;
    Racionais r3(scima,sbaixo);
    return r3;
}
Racionais Racionais::operator-(const Racionais &r2){
    int scima = this->numerador * r2.denominador - r2.numerador * this->denominador;
    int sbaixo = this->denominador * r2.denominador;
    Racionais r3(scima,sbaixo);
    return r3;
}
Racionais Racionais::operator*(const Racionais &r2){
    int scima = this->numerador * r2.numerador;
    int sbaixo = this->denominador * r2.denominador;
    Racionais r3(scima,sbaixo);
    return r3;
}
Racionais Racionais::operator/(const Racionais &r2){
    int scima = this->numerador * r2.denominador;
    int sbaixo = this->denominador * r2.numerador;
    Racionais r3(scima,sbaixo);
    return r3;
}

//Sobrecarga dos operadores lógicos
bool Racionais::operator<(const Racionais &right) const{
    return (this->numerador * right.denominador)<(this->denominador*right.numerador);

}
bool Racionais::operator==(const Racionais &right) const{
    return  (this->numerador * right.denominador) == (this->denominador*right.numerador); 
}
bool Racionais::operator<=(const Racionais &right) const{
    return (*this < right || *this == right);
}
bool Racionais::operator!=(const Racionais &right) const{
    return !(*this == right);
}
bool Racionais::operator>(const Racionais &right) const{
    return !(*this <= right);
}
bool Racionais::operator>=(const Racionais &right) const{
    return (*this > right || *this == right);
}