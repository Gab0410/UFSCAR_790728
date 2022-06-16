#ifndef STR_H
#define STR_H

#include <iostream>
using namespace std;

class String{
    friend ostream &operator<<(ostream &,const String &);
    friend istream &operator>>(istream &, String &);
    private:
        int tam;
        char *sPtr;
        void setString(const char *);
    public:
        String(const char * = "");
        String(const String &);
        ~String();

        const String &operator=(const String &);
        const String &operator+=(const String &);

        bool operator!() const;
        bool operator==(const String &) const;
        bool operator<(const String &) const;
        bool operator!=(const String &) const;
        bool operator>(const String &) const;

        char &operator[](int);
        char operator[](int) const;
        String operator()(int,int=0) const;

        int getTam() const;
};
#endif