#include<iostream>
#include "set.hpp"

void avaliacao_basica(){
    Set set = Set();

    for(int i = 1; i < 10; i++){
        No* no = new No(i);
        set.insert(no);
    }

    for(int i = 1; i < 10; i++){
        No* no = new No(i);
        set.insert(no);
    }

    No* no1 = new No(1);
    No* no2 = new No(2);

    set.print();
    set.remove(no1);
    set.print();
    
    No* n1 = set.find(no1->get_dado());
    No* n2 = set.find(no2->get_dado());

    if(n1 != nullptr){
        std::cout<<"FIND: "<<n1->get_dado()<<std::endl;
    }else{
        std::cout<<"NOT FIND"<<std::endl;
    }

    if(n2 != nullptr){
        std::cout<<"FIND: "<<n2->get_dado()<<std::endl;
    }else{
        std::cout<<"NOT FIND"<<std::endl;
    }

    set.clear();

    delete n1;
    delete n2;    
}