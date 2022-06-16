#ifndef TIME_H
#define TIME_H
#include "Jogador.h"
class Time {
    public:
        Time(string name);
        virtual ~Time();
        string getNome() const;
        void setNome(string n);
        void adicionaJogador(int numero,Jogador* jogador);
        void removeJogador(int num);
        void imprime() const;

    private:
        string nome;
        Jogador* *elenco;
};
#endif /* TIME_H */