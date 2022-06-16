#ifndef E1_H
#define E1_H
class livro
{
private:
    char titulo[20]; // alocação estática
    char autor[50];
    char ISBN[30];
public:
    livro(); // construtor
    livro(char *); // construtor com o título
    void inserir_titulo(char *);
    void inserir_autor(char *);
    void inserir_ISBN(char *);
    char *obter_titulo();
    char *obter_autor();
    char *obter_ISBN();
    void imprimir();
}; 

#endif