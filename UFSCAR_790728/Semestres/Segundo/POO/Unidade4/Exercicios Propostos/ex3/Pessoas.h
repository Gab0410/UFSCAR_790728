#ifndef PES_H
#define PES_H

using namespace std;
#include <cstring>
#include<string>


class Pessoas{

    private:
        string nome;
        int idade;
    public:
        Pessoas(int,string);
        string getNome() const;
        void setNome(string);
        int getIdade() const;
        void setIdade(int);
        void imprime() const;
        int compare(Pessoas &);
};
#endif