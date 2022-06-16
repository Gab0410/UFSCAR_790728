#ifndef STACK_H
#define STACK_H
using namespace std;

template<typename T>

class Stack{
    public:
        Stack(int=10);
        ~Stack(){
            delete [] stackPtr;
        }
        bool push(const T &);
        bool pop( T &);

        bool isEmpty() const{
            return top == -1;
        }
        bool isFull() const{
            return top == size -1;
        }
    private:
        int size, top;
        T *stackPtr;
};

template<typename T>
Stack<T>::Stack(int s)
    :size(s>0?s:10),top(-1),stackPtr(new T[size]){}

template<typename T>
bool Stack<T>::push(const T &value){
    if(!isFull()){
        stackPtr[++top] = value;
        return true;
    }
    return false;
}
template<typename T>
bool Stack<T>::pop(T &popvalue){
    if(!isEmpty()){
        popvalue = stackPtr[top--];
        return true;
    }
    return false;
}

#endif