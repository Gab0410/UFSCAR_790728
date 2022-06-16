#include "ex.h"
#include <iostream>
#include <string.h>

using namespace std;

class estudante: public pessoa {
    private:
        char curso[20];
        char RA[20];
        char universidade[20]; 
    public:
        estudante();
        estudante(char *, char *, char *);
        estudante(char *, char *, char *, char *, char *);
        void setCurso(char *);
        void setRA(char *);
        void setUniversidade(char *);
        char *getCurso();
        char *getRA();
        char *getUniversidade();
        void imprime();
};
estudante::estudante() {
    strcpy(curso,"Computacao");
    strcpy(RA,"123456");
    strcpy(universidade,"UFScar");
}
estudante::estudante(char *c, char *r, char *u) {
    strcpy(curso,c);
    strcpy(RA, r);
    strcpy(universidade,u);
}
estudante::estudante(char *c, char *r, char *u, char *n, char
*s): pessoa(n,s)
{
    strcpy(curso,c);
    strcpy(RA, r);
    strcpy(universidade,u);
}
void estudante::setCurso(char *c) {
    strcpy(curso,c);
}
void estudante::setRA(char *r) {
    strcpy(RA, r);
}
void estudante::setUniversidade(char *u) {
    strcpy(universidade,u);
}
char * estudante::getCurso() {
    return curso;
}
char *estudante::getRA() {
    return RA;
}
char *estudante::getUniversidade() {
    return universidade;
}
void estudante::imprime() {
cout <<" curso : "<< curso << endl;
cout << "RA : "<< RA << endl;
cout << " Univ. : "<< universidade << endl;
pessoa::imprime();
}

/* Esse é um exemplo de herança de uma classe que contem composicao