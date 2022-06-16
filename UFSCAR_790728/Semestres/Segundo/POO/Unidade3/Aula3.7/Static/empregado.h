#ifndef EMPR_H
#define EMPR_H

class Empregado{
    private:
        static int contador;
        char *prim_nome;
        char *seg_nome;
    public:
        Empregado(const char*,const char*);
        ~Empregado();
        const char *getPnome() const;
        const char*getSnome() const;

        static int getContador();
};
#endif