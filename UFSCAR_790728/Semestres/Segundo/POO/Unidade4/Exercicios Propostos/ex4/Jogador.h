#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>
using namespace std;
class Time;
class Jogador {
    public:
        Jogador(string n, int i, string p);
        virtual ~Jogador();

        string getNome() const;
        void setNome(string n);

        int getIdade() const;
        void setIdade(int i);

        string getPosicao() const;
        void setPosicao(string p);

        void imprime() const;

        Time *getTime() const;
        void setTime(Time *time);
    private:
        string nome,posicao;
        int idade;
        Time *time;
};
#endif /* JOGADOR_H */