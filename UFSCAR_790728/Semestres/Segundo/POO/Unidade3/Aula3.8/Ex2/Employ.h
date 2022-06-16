#ifndef EMPL_H
#define EMPL_H

#include "Date.h"
class Employ{
    private:
        char fName[25];
        char sName[25];
        const Date birthDay;
        const Date hireDay;
    public:
        Employ(const char *const, const char *const, const Date &, const Date &);
        void print() const;
        ~Employ();
};
#endif