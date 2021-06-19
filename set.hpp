#ifndef SET_H
#define SET_H

#include<iostream>
#include "no.hpp"

class Set{
    private:
        No* _head;
        No* _tail;
    public:
        Set();
        void insert(No* no);
        void insert_node_helper(No* node, No* no);
        void remove(No* no);
        No* find(int value);
        int size();
        void clear();
        void print();
        bool empty();
        No* begin();
        No* end();
};

#endif // !SET_H