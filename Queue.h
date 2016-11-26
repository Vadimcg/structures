//
// Created by vadimcg on 24.11.16.
//

#include <iostream>

#ifndef STRUCTURES_QUEUE_H
#define STRUCTURES_QUEUE_H

template<class T>
class Queue{

private:

    const int MIN_SIZE=10;
    unsigned int size_;

    T* queuePointer_;

    unsigned int start_;
    unsigned int end_;

    int amount_;


    void init(){
        this->queuePointer_ =new T[size_];
        this->start_=0;
        this->end_=size_-1;
        this->amount_=0;
    }


    void resize(){
        int newSize=this->size_*3/2+1;

        T*newQueuePointer=new T[newSize];

        for(int i=0;i<this->size_;i++){
            newQueuePointer[i]=this->queuePointer_[i];
        }

        this->queuePointer_=newQueuePointer;
        this->size_=newSize;
    }

public:

    Queue():size_{MIN_SIZE}{
        this->init();
    }


    Queue(unsigned int size):size_{size}{
        this->init();
    }


    ~Queue(){
        delete[] queuePointer_;
    }

    int getAmount(){
        return this->amount_;
    }


    void enqueue(T element){

        if(amount_+1==size_)
            this->resize();

        this->queuePointer_[++amount_]=element;
    }


    T& dequeue(){

        if (amount_ == 0) {
            std::cerr << "Queue is empty!" << std::endl;
            exit(EXIT_FAILURE);
        }

        T& outElement= this->queuePointer_[0];

        for(int i=1;i<amount_;i++){
            this->queuePointer_[i-1]=this->queuePointer_[i];
        }

        amount_--;

        return outElement;
    }






};

#endif //STRUCTURES_QUEUE_H
