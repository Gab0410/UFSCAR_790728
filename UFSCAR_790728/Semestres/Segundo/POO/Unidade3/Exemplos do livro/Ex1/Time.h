//Impede multiplas inclusoes de arquivo de cabeçalho
#ifndef TIME_H
#define TIME_H

//Classe TIME

class TIME{
    public:
        TIME();
        void setTime(int,int,int);
        void printUniversal();
        void printStandard();
    private:
        int hora;
        int minuto;
        int segundo;
};

#endif
/* Ultilizar as diretivas de pré processamento ifndef, define e endif para formar um empacotador 
de pre procesador que impede que os arquivos de cabeçalho sejam incluidos mais de uma vez em
um programa.*/