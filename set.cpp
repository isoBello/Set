#include "set.hpp"

Set::Set(){
    this->_head = nullptr;
    this->_tail = nullptr;
}

// Funções auxiliares
void clear_set(No* no){
    if(no == nullptr)
        return;
    No* aux = no->get_proximo();
    delete no;
    clear_set(aux);
}

void print_set(No* no){
    if(no == nullptr)
        return;
    no->print();
    print_set(no->get_proximo());
}

No* find_helper(No* no, int value){
    if(no == nullptr || no->get_dado() == value)
        return no;
    else
        return find_helper(no->get_proximo(), value);
}

// Funções essenciais 
void Set::insert(No* no){
    if(find(no->get_dado()) != nullptr){
        return;
    } 

    if(this->_head == nullptr){
        this->_head = no;
        this->_tail = no;
    }else{
        insert_node_helper(this->_head, no);  
    }
}

void Set::insert_node_helper(No* node, No* no){
    if(node->get_proximo() == nullptr){
        node->set_proximo(no);
        this->_tail = no;
    }else{
        insert_node_helper(node->get_proximo(), no);
    }
}

void Set::remove(No* no){
    No* node = this->_head;
    No* aux = nullptr;

    while(node != nullptr){
        if(node->get_dado() == no->get_dado()){
            if(aux == nullptr){
                this->_head = node->get_proximo();
            }else if(node->get_proximo() == nullptr){
                aux->set_proximo(nullptr);
                this->_tail = aux;
            }else{
                aux->set_proximo(node->get_proximo());
            }
            delete node;
            return;
        }  
        aux = node;
        node = node->get_proximo(); 
    }
}

No* Set::find(int value){
    return find_helper(this->_head, value);
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
    if(this->empty()){
        return;
    }
    clear_set(this->_head);
}

void Set::print(){
    if(this->empty()){
        return;
    }
    print_set(this->_head);
    std::cout<<std::endl;
}

bool Set::empty(){
    if(this->_head == nullptr){
        return true;
    }
    return false;
}

No* Set::begin(){
    return this->_head;
}

No* Set::end(){
    return this->_tail;
}


