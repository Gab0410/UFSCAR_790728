#ifndef D_H
#define D_H
class Data{
    private:
        int dia,mes,ano;
    public:
        Data(int,int,int);
        Data();
        void setDia(int);
        void setMes(int);
        void setAno(int);
        int getDia() const;
        int getMes() const;
        int getAno() const;
        void imprime() const;
};
Data::Data(int d,int m,int a){
    setAno(a);
    setMes(m);
    setDia(d);
}
Data::Data(){
    dia = 1;
    mes = 1;
    ano = 2000;
};

class pessoa {
    private:
        char nome [20];
        char sobrenome[20];
        Data nascimento;
    public:
        pessoa();
        pessoa(char *, char*);
        void setNome(char *);
        void setSobrenome(char *);
        char *getNome();
        char *getSobrenome();
        void imprime();
        void setData(int, int, int);
    };
#endif