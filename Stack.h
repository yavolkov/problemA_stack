#ifndef STACK_H
#define STACK_H
#include <assert.h>
template <typename T>
class Stack {
private:
    T *m_stack;
    int m_capacity;
    int m_top = -1;
public:
    Stack(int size = 8){
        m_stack = new T[size];
        m_capacity = size;
    }

    ~Stack(){
        delete[] m_stack;
    }

    void extendStack(){
        int new_capacity = m_capacity * 1.5;
        T* new_stack = new T[new_capacity];

        for (int i = 0; i < m_capacity; i++){
            new_stack[i] = m_stack[i];
        }
        delete[] m_stack;
        m_stack = new_stack;
        m_capacity = new_capacity;
    }

    void push(T x){
        if (m_top == m_capacity - 1){
            extendStack();
        }
        m_stack[++m_top] = x;
    }

    T pop(){
        assert(!isEmpty());
        return m_stack[m_top--];
    }

    T& top(){
        assert(!isEmpty());
        return m_stack[m_top];
    }

    int size(){
        return m_top + 1;
    }

    int capacity(){
        return m_capacity;
    }

    void clear(){
        m_top = -1;
        delete[] m_stack;
        m_stack = new T[8];
    }

    bool isEmpty(){
        return (m_top == -1);
    }
};


#endif //STACK_H
