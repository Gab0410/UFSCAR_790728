#ifndef BASE2_H
#define BASE2_H

class Base2{
    public:
        Base2(char cD){
            letra = cD;
        }
        char getData() const{
            return letra;
        }
    protected:
        char letra;
};

#endif