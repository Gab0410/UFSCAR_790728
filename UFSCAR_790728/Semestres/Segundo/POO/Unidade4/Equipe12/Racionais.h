/*Nome dos participantes:

Alexandra Floriano - RA 761771
Alexandre dos Santos Gualberto - RA 790843
Gabriel Meirelles Carvalho Orlando - RA 790728
Marcelina Maye Abaga - RA 790139
Ricardo Araújo da Silva - RA 790919

*/
#ifndef RACIONAIS_H
#define RACIONAIS_H

using namespace std;
#include <iostream>

class Racionais{
    //Função friend
    friend ostream &operator<<(ostream &,const Racionais &);
    
    private:
        //Atributos e funções private
        const int numerador,denominador;
        int racionaliza(int,int) const;

    public:
        //Construtor, destrutor e métodos getters
        Racionais(const int, const int);
        ~Racionais();
        const int getNumerador() const;
        const int getDenominador() const;

        //Sobrecarga dos operadores aritiméticos
        Racionais operator+(const Racionais &);
        Racionais operator-(const Racionais &);
        Racionais operator*(const Racionais &);
        Racionais operator/(const Racionais &);
        
        //Sobrecarga dos operadores lógicos
        bool operator<(const Racionais &)const;
        bool operator<=(const Racionais &)const;
        bool operator>(const Racionais &)const;
        bool operator>=(const Racionais &)const;
        bool operator==(const Racionais &)const;
        bool operator!=(const Racionais &)const;    
};
#endif

