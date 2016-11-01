//
// Created by vadimcg on 31.10.16.
//

#import <memory>

#ifndef STRUCTURES_LINKEDLISTELEMENT_H
#define STRUCTURES_LINKEDLISTELEMENT_H

template<class T>
class LinkedListElement {

private:
    LinkedListElement* next_;
    T data_;

public:
    LinkedListElement(const T& data):next_(nullptr),data_(data){}
    ~LinkedListElement(){}

    const T& getData() const {
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
