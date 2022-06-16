#include <iostream>
#include <iomanip>
#include <cstring>

#include "ex1.h"

using namespace std;

livro::livro(char n[]){
    strcpy(titulo,n);
    strcpy(autor,"nenhum");
    strcpy(ISBN,"nada");
}
livro::livro(){
    strcpy(titulo,"vazio");
    strcpy(autor,"nenhum");
    strcpy(ISBN,"nada");
}
void livro::inserir_titulo(char n[]){
    strcpy(titulo,n);
}
void livro::inserir_autor(char n[]){
    strcpy(autor,n);
}
void livro::inserir_ISBN(char n[]){
    strcpy(ISBN,n);
}
char* livro::obter_autor(){
    return autor;
}
char* livro::obter_ISBN(){
    return ISBN;
}
char* livro::obter_titulo(){
    return titulo;
}
void livro::imprimir(){
    cout<<"Livro: "<<obter_titulo()<<"\nAutor: "<<obter_autor()
    <<"\nISBN: "<<obter_ISBN()<<endl;
}
