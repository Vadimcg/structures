

#include <iostream>
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

        if(prev){
            if(current->getNextElement()){
                prev->setNextElement(current->getNextElement());
            }else
                prev->setNextElement(nullptr);

        } else{

            if(current->getNextElement())
                this->head_=current->getNextElement();
            else {
                delete this->head_;
                this->head_= nullptr;

                return;
            }

        }

        delete current;
    }

    void insert(int index,const T& data){

        auto current=head_;
        LinkedListElement<T>* backElement= nullptr;

        for(int i=0;current && i<index;i++){
            backElement=current;
            current=current->getNextElement();
        }

        if (current == nullptr) {
            std::cerr << "Index out of bounds." << std::endl;
            exit(EXIT_FAILURE);
        }


        LinkedListElement<T>* newListElement=new LinkedListElement<T>(data);
        newListElement->setNextElement(current);

        if(backElement)
            backElement->setNextElement(newListElement);
        else
            head_=newListElement;
    }


    void reverse(){

        if (head_ == nullptr) {
            std::cerr << "List is empty" << std::endl;
            exit(EXIT_FAILURE);
        }

        LinkedListElement<T>* currentElement=head_;
        LinkedListElement<T>* backElement= nullptr;
        LinkedListElement<T>* nextElement= nullptr;

        while(currentElement){
            nextElement=currentElement->getNextElement();
            currentElement->setNextElement(backElement);
            backElement=currentElement;
            currentElement=nextElement;
        }

        head_=backElement;
    }


    const T& popFront() {

        if (head_ == nullptr) {
            std::cerr << "List is empty" << std::endl;
            exit(EXIT_FAILURE);
        }

        auto lastHead=head_;
        T retValue = head_->getData();

        if (head_->getNextElement())
            head_ = head_->getNextElement();

        delete lastHead;

        return retValue;
    }

    const T& popBack(){

        if (head_ == nullptr) {
            std::cerr << "List is empty" << std::endl;
            exit(EXIT_FAILURE);
        }

        auto backElement=head_;
        LinkedListElement<T>* prevBackElement= nullptr;

        T retValue;

        while(backElement->getNextElement()) {
            prevBackElement=backElement;
            backElement = backElement->getNextElement();
        }

        if(prevBackElement)
            prevBackElement->setNextElement(nullptr);
        else
            head_= nullptr;

        retValue=backElement->getData();
        delete backElement;

        return retValue;







    }


};


#endif //STRUCTURES_LINKEDLIST_H
