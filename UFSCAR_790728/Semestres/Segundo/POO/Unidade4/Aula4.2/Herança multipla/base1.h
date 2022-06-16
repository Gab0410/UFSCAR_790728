#ifndef BASE1_H
#define BASE1_H

class Base1{
    public:
        Base1(int pV){
            valor = pV;
        }
        int getData() const{
            return valor;
        }
    protected:
        int valor;
};

#endif