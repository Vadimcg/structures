//
// Created by vadimcg on 31.10.16.
//

#import <iostream>
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

        while(current!= nullptr){
            current=current->getNextElement();
            size++;
        }

        return size;
    }

    bool isEmpty(){
        return head_== nullptr;
    }

    void pushFront(const T& data){
        LinkedListElement<T>* newElement=new LinkedListElement<T>(data);
        newElement->setNextElement(head_);
        head_=newElement;
    }

    const T& valueAt(int index){

        int size=0;
        auto current=head_;

        if (current == nullptr) {
            std::cerr << "Index out of bounds." << std::endl;
            exit(EXIT_FAILURE);
        }

        while(current){
            if(index==size)
                return current->getData();

            current=current->getNextElement();
            size++;
        }
    }


    const T& front(){
        if (head_ == nullptr) {
            std::cerr << "List is empty" << std::endl;
            exit(EXIT_FAILURE);
        }

        return  head_->getData();
    }

    const T& back(){

        if (head_ == nullptr) {
            std::cerr << "List is empty" << std::endl;
            exit(EXIT_FAILURE);
        }

        auto current=head_;

        while(current->getNextElement()){
            current=current->getNextElement();
        }

        return  current->getData();
    }



    void erase(int index){

        int size=0;
        auto current=this->head_;

        LinkedListElement<T>* prev=nullptr;


        for(int i=0;i<index && current;i++){
            prev=current;
            current=current->getNextElement();
        }

        if (current == nullptr) {
            std::cerr << "Index out of bounds." << std::endl;
            exit(EXIT_FAILURE);
        }

        if(current->getNextElement()){
            prev->setNextElement(current->getNextElement());
        }else
            prev->setNextElement(nullptr);


        this->head_=prev;
        delete current;

    }






};


#endif //STRUCTURES_LINKEDLIST_H
