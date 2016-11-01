//
// Created by vadimcg on 31.10.16.
//

#include "LinkedListElement.h"

#ifndef STRUCTURES_LINKEDLIST_H
#define STRUCTURES_LINKEDLIST_H


template<class T>
class LinkedList {

private:
    LinkedListElement<T>* head_;

public:
    explicit LinkedList():head_(nullptr){
    }
    ~LinkedList(){
        delete head_;
    }

    int getSize() const{
        int size=0;

        auto current=head_;

        if(current!= nullptr){
            current=current->getNextElement();
            size++;
        }

        return size;
    }

    bool isEmpty(){
        return head_== nullptr;
    }

    void pushFront(const T& data){
        LinkedListElement* newElement=new LinkedListElement(data);
        newElement->setNextElement(head_);
        head_=newElement;
    }

    const T& valueAt(int index){

        int size=0;
        auto current=head_;

        while(current){
            if(index==size)
                return current->getData();

            current=current->getNextElement();
            size++;
        }
    }






};


#endif //STRUCTURES_LINKEDLIST_H
