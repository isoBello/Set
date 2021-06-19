#ifndef NO_H
#define NO_H

#include<iostream>

class No{
    private:
        int _value;
        No* _next;
    public:
        No(int value);
        void set_proximo(No* next);
        No* get_proximo();
        void set_dado(int value);
        int get_dado();
        void print();
};

#endif // !NO_H