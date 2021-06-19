#include "no.hpp"

No::No(int value){
    this->_value = value;
    this->_next = nullptr;
}

void No::set_proximo(No* next){
    this->_next = next;
}

No* No::get_proximo(){
    return this->_next;
}

void No::set_dado(int value){
    this->_value = value;
}

int No::get_dado(){
    return this->_value;
}

void No::print(){
    std::cout<<this->get_dado()<< " ";
}