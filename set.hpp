#ifndef SET_H
#define SET_H

#include<iostream>
#include "no.hpp"

class Set{
    private:
        No* _head;
        No* _tail;
        No* _iter;
        No* _iter_next;
    public:
        Set();
        bool insert(int value);
        bool remove(int value);
        No* find(int value);
        int size();
        void clear();
        void print();
        No* begin();
        No* end();

        //Funções de conjunto
        Set* union_set(Set* s1, Set* s2);
        Set* intersect_set(Set* s1, Set* s2);
        Set* difference_set(Set* s1, Set* s2);
};

#endif // !SET_H