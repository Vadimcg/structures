//
// Created by vadimcg on 31.10.16.
//


#include <memory>
#include <iostream>
#ifndef STRUCTURES_LINKEDLISTELEMENT_H
#define STRUCTURES_LINKEDLISTELEMENT_H

template<class T>
class LinkedListElement {

private:
    LinkedListElement* next_;
    T data_;

public:
    LinkedListElement(const T& data):next_(nullptr),data_(data){}
    ~LinkedListElement(){
        std::cerr << "Element with value:"
                  <<data_<<" was deleted" << std::endl;

        delete next_;
    }

    T& getData() {
        return this->data_;
    }

    LinkedListElement<T> getLinkedListElement() const{
        return this;
    }

    void setData(const T& data){
        this->data_=data;
    }

    void setNextElement(LinkedListElement* next){
        this->next_=next;
    }

    LinkedListElement<T>* getNextElement() const{
        return this->next_;
    }

};


#endif //STRUCTURES_LINKEDLISTELEMENT_H
