#ifndef TEM_H
#define TEM_H

class Tempo{
    public:
        Tempo(int=0,int=0,int=0);

        //funçaõ set
        void setTempo(int,int,int);
        void setHora(int);
        void setMin(int);
        void setSeg(int);

        //função get
        int getHora() const;
        int getMin() const;
        int getSeg() const;

        void printUniversal() const;
        void printStandard();

    private:
        int hora;
        int minuto;
        int segundo;
};
#endif