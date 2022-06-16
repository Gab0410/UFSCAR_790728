#ifndef I_H
#define I_H

class Increment{
    private:
        int counter;
        const int inc;
    public:
        Increment(int c=0,int i=1);
        void addI(){
            counter += inc;
        }
        void printI() const;
};
#endif