#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <iomanip>
#include <stdbool.h>
using namespace std;

class Data{
    public:
        Data();
        bool operator>(const Data& direita) const;
        bool operator>=(const Data& direita) const;
        bool operator<(const Data& direita) const;
        bool operator<=(const Data& direita) const;
        bool operator==(const Data& direita) const;
        bool operator!=(const Data& direita) const;
    friend ostream& operator<<(ostream& out, const Data& obj);
    friend istream& operator>>(istream& in, Data& obj);
    private:
        int dia,mes,ano;
        int comparar(const Data) const;

};


#endif