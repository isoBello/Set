#include "set.hpp"

Set::Set(){
    this->_head = nullptr;
    this->_tail = nullptr;
    this->_iter = nullptr;
    this->_iter_next = nullptr;
}

// Funções auxiliares
No* create_node(int value){
    No* no = new No(value, nullptr);
    return no;
}

// Funções essenciais 
bool Set::insert(int value){
    if(find(value) != nullptr){
        return false;
    } 

    No* no = create_node(value);
    if(this->_head == nullptr){
        this->_head = no;
        this->_tail = no;
    }else{
        No* next = this->_tail->get_proximo();
        next->set_proximo(no);
        this->_tail = no;
    }
    return true;
}

bool Set::remove(int value){
    No* no = this->begin();
    No* aux = nullptr;
    while(no != nullptr){
        if(no->get_dado() == value){
            if(no == this->_head && no == this->_tail){
                // O Set só possui um nó
                this->_head = no->get_proximo();
                this->_tail = aux;
                if(this->_tail)
                    this->_tail->get_proximo()->set_proximo(nullptr);
            }else if(no == this->_head){
                // O nó a ser removido é a cabeça
                this->_head = no->get_proximo();
            }else if(no == this->_tail){
                // O nó a ser removido é o fim
                this->_tail = aux;
                if(this->_tail)
                    this->_tail->get_proximo()->set_proximo(nullptr);
            }else{
                aux->get_proximo()->set_proximo(no->get_proximo());
            }
            free(no);
            return true;
        }  
        aux = no;
        no = no->get_proximo();  
    }
    return false;
}

No* Set::find(int value){
    No* no = this->begin();
    while(no != nullptr){
        if(no->get_dado() == value){
            return no;
        }else{
            no = no->get_proximo();
        }
    }
    return nullptr;
}

int Set::size(){
    int nodes = 0;
    No* no = this->_head;
    while(no != nullptr){
        nodes += 1; 
        no = no->get_proximo();
    }
    return nodes;
}

void Set::clear(){
    
}

No* Set::begin(){
    return this->_head;
}

No* Set::end(){
    return this->_tail;
}


