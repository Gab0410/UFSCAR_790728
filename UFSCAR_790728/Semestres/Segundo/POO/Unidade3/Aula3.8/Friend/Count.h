#ifndef C_H
#define C_H
class Count{
    friend void setX(Count &, int); // declaração friend
    public:
        Count();
        void print();
    private:
        int x;

};
void setX(Count &, int);
#endif