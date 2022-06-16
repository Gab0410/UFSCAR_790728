#ifndef ENDERECO_H
#define ENDERECO_H
#include <string>
using namespace std;
class Endereco {
    public:
        Endereco(string l,int num,string c,string es);
        virtual ~Endereco();

        string getLog() const;
        void setLog(string);

        int getNum() const;
        void setNum(int);

        string getCid() const;
        void setCid(string);

        string getEst() const;
        void setEst(string);

        void imprime() const;
    private:
        string logradouro,cidade,estado;
        int numero;
};
#endif // ENDERECO_H