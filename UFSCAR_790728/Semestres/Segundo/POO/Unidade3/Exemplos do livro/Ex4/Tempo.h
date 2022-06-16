#ifndef TEMPO_H
#define TEMPO_H

class Tempo{
    public:
        Tempo(int=0,int=0,int=0);

        //funçaõ set
        void setTempo(int,int,int);
        void setHora(int);
        void setMin(int);
        void setSeg(int);

        //função get
        int getHora();
        int getMin();
        int getSeg();

        void printUniversal();
        void printStandard();

    private:
        int hora;
        int minuto;
        int segundo;
};
#endif