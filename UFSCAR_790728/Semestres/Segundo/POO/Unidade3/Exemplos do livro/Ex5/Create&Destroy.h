#include <string.h>

#ifndef CREATE_H
#define CREATE_H

class CreateAndDestroy{
    public:
        CreateAndDestroy(int,string);
        ~CreateAndDestroy();
    private:
        int objID;
        string msg;
};
#endif